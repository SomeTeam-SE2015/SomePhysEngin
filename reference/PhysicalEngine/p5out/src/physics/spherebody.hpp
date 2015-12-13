#ifndef _462_PHYSICS_SPHEREBODY_HPP_
#define _462_PHYSICS_SPHEREBODY_HPP_

#include "scene/sphere.hpp"
#include "physics/body.hpp"

namespace _462 {

class Sphere;

class SphereBody : public Body
{
public:
    Sphere* sphere;
    real_t radius;
	real_t mass;
	Vector3 force;
	Vector3 torque;
	Vector3 force_static;
	Vector3 torque_static;

    SphereBody( Sphere* geom );
    virtual ~SphereBody() { }
    virtual Vector3 step_position( real_t dt, real_t motion_damping );
	virtual Vector3 step_orientation(real_t dt, real_t motion_damping);
	virtual void get_step(Vector3& vdif, Vector3& xdif, real_t motion_damping = 0);

	virtual real_t angular_momentum() const
	{
		return 2 * this->mass * this->radius * this->radius / 5;
	};
	virtual void apply_force(const Vector3& f, const Vector3& offset)
	{
		// apply force/torque to sphere
		force += f;
		torque += cross(offset, f);
	};
	virtual void apply_force_static(const Vector3& f, const Vector3& offset)
	{
		// apply force/torque to sphere
		force_static = f;
		torque_static = cross(offset, f);
	};
	virtual void clear_force()
	{
		force = Vector3::Zero;
		torque = Vector3::Zero;
	};

	void inline update_geom() {
		sphere->position = position;
		sphere->orientation = orientation;
	}
};

}

#endif

