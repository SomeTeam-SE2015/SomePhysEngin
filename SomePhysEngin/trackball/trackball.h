/*
 * Source code from Internet
 * edit by LM
 */

#ifndef _TRACKBALL_H_
#define  _TRACKBALL_H_

#include "math/vector.hpp"
#include "math/camera.hpp"
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <GL/glu.h>
namespace _SomeEngin {

class TrackBall
{
    Vector2 last_point_2D;
    Vector3 last_point_3D;
	bool last_point_ok;
	double adjustWidth, adjustHeight;
	double MVmatrix[16];

public:
	TrackBall(double width, double height);

    void init(Camera init_camera);
	void apply();

	void reAdjustTrackBall(double width, double height);

	//mouse callback func for rotate
    void mouseMoveR(int x, int y);
    void mouseClickR(int x, int y);
	//mouse callback func for translate
    void mouseMoveT(int x, int y);
    void mouseClickT(int x, int y);
	//mouse callback func for scaling
    void mouseMoveS(int x, int y);
    void mouseClickS(int x, int y);
    //wheel callback func for z translate
    void wheelscrool(double z);

private:
    void mapToSphere(const Vector2& v2d, Vector3& v3d);
    void rotate(const Vector3& axis, double angle);
    void translate(const Vector3& shift);
    void scaling(int sca);
};
}
#endif
