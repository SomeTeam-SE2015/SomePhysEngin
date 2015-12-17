/*
 * Source code from Internet
 * edit by LM
 */

#include "trackball.h"
#include "math/vector.hpp"
#include <cmath>
#include <iostream>
namespace _SomeEngin {

TrackBall::TrackBall(double width, double height)
{
	last_point_ok = false;
	adjustWidth = 1 / (width * 0.5);
    adjustHeight = 1 / (height * 0.5);
}

void TrackBall::mapToSphere(const Vector2& v2d, Vector3& v3d)
{
	double x = v2d.x * adjustWidth - 1.0;
	double y = 1.0 - v2d.y * adjustHeight;
	double x2y2 = x*x+y*y;

	if (x2y2 < 1.0)
	{
		v3d.x = x;
		v3d.y = y;
		v3d.z = sqrt(1.0 - x2y2);
	}
	else
	{
		double norm = 1.0 / sqrt(x2y2);
		v3d.x = x * norm;
		v3d.y = y * norm;
		v3d.z = 0;
	}
}

void TrackBall::init(Camera camera)
{
    const Vector3& campos = camera.get_position();
    const Vector3 camref = camera.get_direction() + campos;
    const Vector3& camup = camera.get_up();

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt( campos.x, campos.y, campos.z,
               camref.x, camref.y, camref.z,
               camup.x,  camup.y,  camup.z );
	glGetDoublev(GL_MODELVIEW_MATRIX, MVmatrix);
}

void TrackBall::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(MVmatrix);
}

void TrackBall::reAdjustTrackBall(double width, double height)
{
	adjustWidth = 1.0 / (width * 0.5);
	adjustHeight = 1.0 / (height * 0.5);
}

void TrackBall::mouseMoveR(int x, int y)
{
    Vector2 new_point_2D(x, y);
    Vector3 new_point_3D;
	mapToSphere(new_point_2D, new_point_3D);

	if (last_point_ok)
	{
        Vector3 axis = cross(last_point_3D, new_point_3D);
        if(length(axis) < 1e-7)
            axis = Vector3::Zero;
		else
            axis = normalize(axis);

        Vector3 dist = last_point_3D - new_point_3D;
        double sinangle = 0.5*length(dist);
		double angle = asin(sinangle) / PI * 180.0;

		rotate(axis, 4*angle);

		last_point_2D = new_point_2D;
		last_point_3D = new_point_3D;
		last_point_ok = true;
	}
}

void TrackBall::mouseClickR(int x, int y)
{
    last_point_2D = Vector2(x, y);
	mapToSphere(last_point_2D, last_point_3D);
    last_point_ok = true;
}

void TrackBall::rotate(const Vector3& axis, double angle)
{
	//Get the TRANSLATION paramter
    Vector3 trans(MVmatrix[12], MVmatrix[13], MVmatrix[14]);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(trans.x, trans.y, trans.z);
	glRotatef(angle, axis.x, axis.y, axis.z);
	glTranslatef(-trans.x, -trans.y, -trans.z);

	glMultMatrixd(MVmatrix);

	glGetDoublev(GL_MODELVIEW_MATRIX, MVmatrix);
}

void TrackBall::mouseClickT(int x, int y)
{
    last_point_2D = Vector2(x, y);
	last_point_ok = true;
}

void TrackBall::mouseMoveT(int x, int y)
{
    Vector2 new_point_2D(x, y);

	if (last_point_ok)
	{
        double adj = 10;
		double x = (new_point_2D.x - last_point_2D.x) * adjustWidth * adj;
		double y = -(new_point_2D.y - last_point_2D.y) * adjustHeight * adj;
        Vector3 shift(x, y, 0);

		translate(shift);

		last_point_2D = new_point_2D;
		last_point_ok = true;
	}
}

void TrackBall::translate(const Vector3& shift)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(shift.x, shift.y, shift.z);
	glMultMatrixd(MVmatrix);

	glGetDoublev(GL_MODELVIEW_MATRIX, MVmatrix);
}

void TrackBall::mouseClickS(int x, int y)
{
    last_point_2D = Vector2(x, y);
	last_point_ok = true;
}

void TrackBall::mouseMoveS(int x, int y)
{
    Vector2 new_point_2D(x, y);

	if (last_point_ok)
	{
		double size = exp((new_point_2D.x - last_point_2D.x) * adjustWidth);

		scaling(size);

		last_point_2D = new_point_2D;
		last_point_ok = true;
	}
}

void TrackBall::scaling(int size)
{
    //Get the TRANSLATION paramter
    Vector3 trans(MVmatrix[12], MVmatrix[13], MVmatrix[14]);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(trans.x, trans.y, trans.z);
    glScalef(size, size, size);
    glTranslatef(-trans.x, -trans.y, -trans.z);
    glMultMatrixd(MVmatrix);

    glGetDoublev(GL_MODELVIEW_MATRIX, MVmatrix);
}

void TrackBall::wheelscrool(double z)
{
    // moove forward and backward in z direction
    static const double scale = 1;
    translate( Vector3(0,0,z * scale) );

}
}
