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

#include "scene/scene.hpp"
#include "trackball/trackball.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QString>
#include <QMouseEvent>
#include <QWheelEvent>

class EnginViewer : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    EnginViewer(QWidget *parent = 0);
    ~EnginViewer(){}

    void reset_scene(FILE* file);
    void reset_scene(const QString& scene_content);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    _SomeEngin::Scene scene;
    double fps;
    int height, width;
    double speed;
    bool pause;
    _SomeEngin::TrackBall trackball;
    Qt::MouseButton pressed_button;

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    bool initApp();
    void update(double delta_time );
    void render_scene();
};

#endif // ENGINVIEWER_H
