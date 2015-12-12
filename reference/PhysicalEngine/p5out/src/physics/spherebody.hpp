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
	virtual void apply_force(const Vector3& f, const Vector3& offset);
	virtual void apply_force_static(const Vector3& f, const Vector3& offset);
	virtual void clear_force();
	virtual real_t angular_momentum() const;
};

}

#endif

