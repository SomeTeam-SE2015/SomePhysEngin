#include "math/math.hpp"
#include "math/vector.hpp"
#include "math/quaternion.hpp"
#include "math/matrix.hpp"
#include "physics/spring.hpp"
#include "physics/body.hpp"
#include "physics/spherebody.hpp"
#include <iostream>

namespace _462 {

Spring::Spring()
{
    body1_offset = Vector3::Zero;
    body2_offset = Vector3::Zero;
    damping = 0.0;
}

real_t Spring::length()
{
	Vector3 x1 = body1->position + body1->orientation * body1_offset;
	Vector3 x2 = body2->position + body2->orientation * body2_offset;
	return distance( x1, x2 );
}

void Spring::step( real_t dt )
{
    // TODO apply forces to attached bodies
}

}


