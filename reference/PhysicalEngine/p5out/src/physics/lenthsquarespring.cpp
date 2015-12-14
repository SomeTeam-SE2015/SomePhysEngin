#include "math/math.hpp"
#include "math/vector.hpp"
#include "math/quaternion.hpp"
#include "math/matrix.hpp"
#include "physics/spring.hpp"
#include "physics/lenthsquarespring.hpp"
#include "physics/spherebody.hpp"
#include <iostream>

namespace _462 {

LenthSqSpring::LenthSqSpring() : Spring()
{
}

void LenthSqSpring::apply()
{
	// apply forces to attached bodies
	Vector3 direction = display();
	Vector3 force = direction * ( constant / length(direction)
		+ damping*dot(body2->velocity - body1->velocity, direction) / squared_length(direction));
	body1->apply_force(force, body1_offset);
	body2->apply_force(-force, body2_offset);

}

}


