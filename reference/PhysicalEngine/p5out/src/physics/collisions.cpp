#include "physics/collisions.hpp"

namespace _462 {

bool collides( SphereBody& body1, SphereBody& body2, real_t collision_damping )
{
    // TODO detect collision. If there is one, update velocity
	if ((body1.radius + body2.radius) * body1.radius + body2.radius
		>= squared_length(body1.position - body2.position)) {
		//collision happens
		Vector3 totalMomentum = body1.velocity * body1.mass + body2.velocity * body2.mass;
		Vector3 velocityDif = body1.velocity - body2.velocity;
		real_t totalMass = body1.mass + body2.mass;
		body1.velocity = (totalMomentum - velocityDif*collision_damping*body2.mass) / totalMass;
		body2.velocity = (totalMomentum + velocityDif*collision_damping*body1.mass) / totalMass;
		return true;
	}

    return false;
}

bool collides( SphereBody& body1, TriangleBody& body2, real_t collision_damping )
{
    // TODO detect collision. If there is one, update velocity

    return false;
}

bool collides( SphereBody& body1, PlaneBody& body2, real_t collision_damping )
{
    // TODO detect collision. If there is one, update velocity

	return false;
}

}
