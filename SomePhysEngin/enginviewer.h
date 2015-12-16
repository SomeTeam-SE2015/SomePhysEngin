/*
 * This is the main part showing what the engin rendered in the app.
 * And the code are mainly from main.cpp and application class in reference,
 * together with a little feather in Qt and remove SDL SDK
 *
 * Author: Lyu Ming
 * 2015/12
 */

#ifndef ENGINVIEWER_H
#define ENGINVIEWER_H

//#include "scene/scene.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <string>

//using namespace _SomeEngin;

class EnginViewer : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    EnginViewer(QWidget *parent = 0);
    ~EnginViewer(){}

    void reset_scene(FILE* file);
    void reset_scene(const std::string& scene_content);

protected:
    //Scene scene;
    double fps;
    int height, width;
    double speed;
    bool pause;

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    bool initApp();
    void update(double delta_time );
};

#endif // ENGINVIEWER_H
