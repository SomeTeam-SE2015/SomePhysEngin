#include "physics/spherebody.hpp"
#include "math/vector.hpp"
#include "math/matrix.hpp"
#include "scene/sphere.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

namespace _462 {
SphereBody::SphereBody( Sphere* geom )
{
    sphere = geom;
    position = sphere->position;
    radius = sphere->radius;
    orientation = sphere->orientation;
    mass = 0.0;
    velocity = Vector3::Zero;
    angular_velocity = Vector3::Zero;
    force = Vector3::Zero;
	force_static = Vector3::Zero;
    torque = Vector3::Zero;
	torque_static = Vector3::Zero;
}

Vector3 SphereBody::step_position( real_t dt, real_t motion_damping )//damping ÒÑ°üº¬ dt?!!
{
    // Note: This function is here as a hint for an approach to take towards
    // programming RK4, you should add more functions to help you or change the
    // scheme
    // return the delta in position dt in the future
	// to the 1st order. RK4 is performed in class "physics"
	Vector3 delta = velocity * dt;
	position += delta;
	velocity += (force + force_static) * (dt / mass) - velocity * (dt * motion_damping);
	//velocity *= (1 - motion_damping);
	position += velocity * dt;
    return delta;
}

Vector3 SphereBody::step_orientation( real_t dt, real_t motion_damping )
{
    // Note: This function is here as a hint for an approach to take towards
    // programming RK4, you should add more functions to help you or change the
    // scheme
    // TODO return the delta in orientation dt in the future
    // vec.x = rotation along x axis
    // vec.y = rotation along y axis
    // vec.z = rotation along z axis
	// to the 1st order. RK4 is performed in class "physics"
	Vector3 delta = angular_velocity * dt;
	// orientation += Quaternion(0, delta.x, delta.y, delta.z) * orientation;
	orientation = Quaternion(delta, length(delta)) * orientation;
	angular_velocity += (torque + torque_static) / angular_momentum();
    return delta;
}

void SphereBody::get_step(Vector3& vdif, Vector3& xdif, real_t motion_damping)
{
	vdif = (force + force_static) / mass - velocity * (motion_damping);
	xdif = velocity;
}
}