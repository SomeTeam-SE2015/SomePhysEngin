#ifndef _SomeEngin_PHYSICS_BODY_HPP_
#define _SomeEngin_PHYSICS_BODY_HPP_

#include "math/vector.hpp"
#include "math/quaternion.hpp"
#include <exception>
#include <iostream>

namespace _SomeEngin {

class Body
{
public:
    int id;
    int type;
    Vector3 position;
    Quaternion orientation;
    Vector3 velocity;
    Vector3 angular_velocity;

	/* typedef struct { // Struct to combine status for position
		Vector3 v;
		Vector3 x;
	} v_and_x; 
	typedef struct { // Struct to combine status for orientation
		Vector3 omega;
		Quaternion theta;
	} omega_and_theta;*/

    virtual ~Body() { }
    virtual Vector3 step_position( real_t dt, real_t motion_damping ) = 0;
    virtual Vector3 step_orientation( real_t dt, real_t motion_damping ) = 0;
    virtual void apply_force( const Vector3& f, const Vector3& offset ) = 0;
};

}

#endif
