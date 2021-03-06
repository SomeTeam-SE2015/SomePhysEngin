#include "math/math.hpp"
#include "math/vector.hpp"
#include "math/quaternion.hpp"
#include "math/matrix.hpp"
#include "physics/spring.hpp"
#include "physics/body.hpp"
#include "physics/spherebody.hpp"
#include <iostream>

namespace _SomeEngin {

Spring::Spring()
{
    body1_offset = Vector3::Zero;
    body2_offset = Vector3::Zero;
    damping = 0.0;
}

void Spring::apply()
{
    // apply forces to attached bodies
	Vector3 direction = display();
	Vector3 force = direction * ((1 - equilibrium / length(direction)) * constant
		+ damping*dot(body2->velocity - body1->velocity, direction)/squared_length(direction));

	body1->apply_force(force, body1_offset);
    body2->apply_force(-force, body2_offset);

}

}


