/*
 * This is the main part showing what the engin rendered in the app.
 * And the code are mainly from main.cpp and application class in reference,
 * together with a little feather in Qt and remove SDL SDK
 *
 * Author: Lyu Ming
 * 2015/12
 */

#include "application/imageio.hpp"
#include "application/scene_loader.hpp"
#include "application/opengl.hpp"
#include "enginviewer.h"
#include <GL/glu.h>
#include <QMessageBox>
#include <iostream>
#include <string>

using namespace _SomeEngin;

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define DEFAULT_FPS 30.0
static const GLenum LightConstants[] = {
    GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3,
    GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7
};
static const size_t NUM_GL_LIGHTS = 8;
//void render_scene( const Scene& scene );

EnginViewer::EnginViewer(QWidget *parent) : QOpenGLWidget(parent),
    width(DEFAULT_WIDTH), height(DEFAULT_HEIGHT), running(false), trackball(width, height),
    pressed_button(Qt::NoButton)
{
}

void EnginViewer::initializeGL()
{
    initializeOpenGLFunctions();
    /*
    FILE* file = fopen( "scenes/spring_rotation.scene", "rb" );
    if ( !load_scene( &scene, file ) ) {
        QMessageBox::warning(this, "engin-demo","Error loading scene",
                             QMessageBox::Ok);
        return;
    }
    fps = DEFAULT_FPS;

    if ( !initApp() ) {
        QMessageBox::warning(this, "engin-demo","Failed to start applcation, aborting.",
                             QMessageBox::Ok);
        return;
    }
    trackball.init(scene.camera);*/
}

void EnginViewer::reset_scene(FILE *file)
{
    // scene.reset(); scene is reset while loading file
    if ( !load_scene( &scene, file ) ) {
        QMessageBox::warning(this, "engin-demo","Error loading scene",
                             QMessageBox::Ok);
        return;
    }
    fps = DEFAULT_FPS;

    if ( !initApp() ) {
        QMessageBox::warning(this, "engin-demo","Failed to start applcation, aborting.",
                             QMessageBox::Ok);
        return;
    }
    trackball.init(scene.camera);
    running = true;
}

void EnginViewer::reset_scene(const QString& scene_name)
{
    // scene.reset(); scene is reset while loading file
    FILE* file = fopen( scene_name.toStdString().c_str(), "rb" );
    if ( !load_scene( &scene, file ) ) {
        QMessageBox::warning(this, "engin-demo","Error loading scene",
                             QMessageBox::Ok);
        return;
    }
    fps = DEFAULT_FPS;

    if ( !initApp() ) {
        QMessageBox::warning(this, "engin-demo","Failed to start applcation, aborting.",
                             QMessageBox::Ok);
        return;
    }
    trackball.init(scene.camera);
    running = true;
}

void EnginViewer::resizeGL(int w, int h)
{
    height = h;
    width = w;
    trackball.reAdjustTrackBall(w, h);
}

void EnginViewer::paintGL()
{
    if (!running)
        return;
    update_scene( 1.0 / fps );
    glViewport( 0, 0, width, height );
    // fix camera aspect
    Camera& camera = scene.camera;
    camera.aspect = real_t( width ) / real_t( height );
    // clear buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // reset matrices
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushAttrib( GL_ALL_ATTRIB_BITS );
    render_scene();
    glPopAttrib();

    // flush so the code doesn't have to remember to
    glFlush();
}

bool EnginViewer::initApp()
{
    if ( glewInit() != GLEW_OK ) {
        std::cerr << "GLEW failed to initialize.";
        return false;
    }
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glPixelStorei( GL_PACK_ALIGNMENT, 1 );
    bool load_gl = true;
    pause = false;
    speed = 1.0;
    try {
        Material* const* materials = scene.get_materials();
        Mesh* const* meshes = scene.get_meshes();
        // load all textures
        for ( size_t i = 0; i < scene.num_materials(); ++i ) {
            if ( !materials[i]->load() || ( load_gl && !materials[i]->create_gl_data() ) ) {
                std::cerr << "Error loading texture, aborting.\n";
                return false;
            }
        }
        // load all meshes
        for ( size_t i = 0; i < scene.num_meshes(); ++i ) {
            if ( !meshes[i]->load() || ( load_gl && !meshes[i]->create_gl_data() ) ) {
                std::cerr << "Error loading mesh, aborting.\n";
                return false;
            }
        }
    } catch ( std::bad_alloc const& ) {
        std::cerr << "Out of memory error while initializing scene\n.";
        return false;
    }
    // set the gl state
    if ( load_gl ) {
        float arr[4];
        arr[3] = 1.0; // alpha is always 1
        glClearColor(scene.background_color.r,
                     scene.background_color.g,
                     scene.background_color.b,
                     1.0f );
        scene.ambient_light.to_array( arr );
        glLightModelfv( GL_LIGHT_MODEL_AMBIENT, arr );
        const PointLight* lights = scene.get_lights();
        for ( size_t i = 0; i < NUM_GL_LIGHTS && i < scene.num_lights(); i++ ) {
            const PointLight& light = lights[i];
            glEnable( LightConstants[i] );
            light.color.to_array( arr );
            glLightfv( LightConstants[i], GL_DIFFUSE, arr );
            glLightfv( LightConstants[i], GL_SPECULAR, arr );
            glLightf( LightConstants[i], GL_CONSTANT_ATTENUATION, light.attenuation.constant );
            glLightf( LightConstants[i], GL_LINEAR_ATTENUATION, light.attenuation.linear );
            glLightf( LightConstants[i], GL_QUADRATIC_ATTENUATION, light.attenuation.quadratic );
        }
        glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );
    }

    return true;
}

void EnginViewer::render_scene()
{
    // backup state so it doesn't mess up raytrace image rendering
    glPushAttrib( GL_ALL_ATTRIB_BITS );
    glPushClientAttrib( GL_CLIENT_ALL_ATTRIB_BITS );

    glClearColor(
        scene.background_color.r,
        scene.background_color.g,
        scene.background_color.b,
        1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnable( GL_NORMALIZE );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_TEXTURE_2D );

    // set camera transform

    const Camera& camera = scene.camera;

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( camera.get_fov_degrees(),
                    camera.get_aspect_ratio(),
                    camera.get_near_clip(),
                    camera.get_far_clip() );

    /*const Vector3& campos = camera.get_position();
    const Vector3 camref = camera.get_direction() + campos;
    const Vector3& camup = camera.get_up();

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt( campos.x, campos.y, campos.z,
               camref.x, camref.y, camref.z,
               camup.x,  camup.y,  camup.z );*/
    trackball.apply();
    glMatrixMode( GL_MODELVIEW );
    // set light data
    float arr[4];
    arr[3] = 1.0; // w is always 1

    scene.ambient_light.to_array( arr );
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, arr );

    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );

    const PointLight* lights = scene.get_lights();

    for ( size_t i = 0; i < NUM_GL_LIGHTS && i < scene.num_lights(); i++ ) {
        const PointLight& light = lights[i];
        glEnable( LightConstants[i] );
        light.color.to_array( arr );
        glLightfv( LightConstants[i], GL_DIFFUSE, arr );
        glLightfv( LightConstants[i], GL_SPECULAR, arr );
        glLightf( LightConstants[i], GL_CONSTANT_ATTENUATION, light.attenuation.constant );
        glLightf( LightConstants[i], GL_LINEAR_ATTENUATION, light.attenuation.linear );
        glLightf( LightConstants[i], GL_QUADRATIC_ATTENUATION, light.attenuation.quadratic );
        light.position.to_array( arr );
        glLightfv( LightConstants[i], GL_POSITION, arr );
    }
    // render each object

    Geometry* const* geometries = scene.get_geometries();

    for ( size_t i = 0; i < scene.num_geometries(); ++i ) {
        const Geometry& geom = *geometries[i];
        Vector3 axis;
        real_t angle;

        glPushMatrix();

        glTranslated( geom.position.x, geom.position.y, geom.position.z );
        geom.orientation.to_axis_angle( &axis, &angle );
        glRotated( angle * ( 180.0 / PI ), axis.x, axis.y, axis.z );
        glScaled( geom.scale.x, geom.scale.y, geom.scale.z );

        geom.render();

        glPopMatrix();
    }

    glPopClientAttrib();
    glPopAttrib();
}

void EnginViewer::update_scene( double delta_time )
{
    static const size_t NUM_ITER = 20;

    // step the simulation
    if ( !pause ) {
        real_t step_size = delta_time / NUM_ITER;
        for ( size_t i = 0; i < NUM_ITER; i++ ) {
            scene.update( step_size * speed );
        }
    }
}


void EnginViewer::mousePressEvent(QMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        trackball.mouseClickR(event->x(), event->y());
        //std::cerr<<"left click: ("<<event->x()<<","<<event->y()<<std::endl;
        break;
    case Qt::RightButton:
        trackball.mouseClickT(event->x(), event->y());
        break;
    }
    pressed_button = event->button();
    event->accept();
}

void EnginViewer::mouseMoveEvent(QMouseEvent *event)
{
    switch(pressed_button)
    {
    case Qt::LeftButton:
        trackball.mouseMoveR(event->x(), event->y());
        break;
    case Qt::RightButton:
        trackball.mouseMoveT(event->x(), event->y());
        break;
    //default:
        //std::cerr<<event->button()<<event->x()<<", "<<event->y()<<std::endl;
    }
    event->accept();
}

void EnginViewer::mouseReleaseEvent(QMouseEvent *event)
{
    pressed_button = Qt::NoButton;
    event->accept();
}

void EnginViewer::wheelEvent(QWheelEvent *event)
{
    double z = event->angleDelta().y()/120.0;
    trackball.wheelscrool(z);
}
