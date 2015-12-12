#include "physics/spherebody.hpp"
#include "math/vector.hpp"
#include "math/matrix.hpp"
#include "scene/sphere.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

namespace _462 {
	
real_t SphereBody::angular_momentum() const
{
	return 2 * this->mass * this->radius * this->radius / 5;
}

void SphereBody::clear_force()
{
	force = Vector3::Zero;
	torque = Vector3::Zero;
}

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
    torque = Vector3::Zero;
}

Vector3 SphereBody::step_position( real_t dt, real_t motion_damping )
{
    // Note: This function is here as a hint for an approach to take towards
    // programming RK4, you should add more functions to help you or change the
    // scheme
    // return the delta in position dt in the future
	// to the 1st order. RK4 is performed in class "physics"
	Vector3 delta = velocity * dt;
	position += delta;
	velocity += force * (dt / mass) - velocity * (dt * motion_damping);
	position += velocity * dt;
	sphere->position = position;
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
	angular_velocity += torque / angular_momentum();
    return delta;
}

void SphereBody::apply_force(const Vector3& f, const Vector3& offset)
{
	// apply force/torque to sphere
	force += f;
	torque += cross(offset, f);
}

void SphereBody::apply_force_static(const Vector3& f, const Vector3& offset)
{
	// apply force/torque to sphere
	force_static += f;
	torque_static += cross(offset, f);
}

}