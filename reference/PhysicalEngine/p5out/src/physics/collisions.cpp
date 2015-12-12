#include "physics/collisions.hpp"
#include <cmath>
namespace _462 {

bool collides( SphereBody& body1, SphereBody& body2, real_t collision_damping )
{
    // TODO detect collision. If there is one, update velocity
	if ((body1.radius + body2.radius) * (body1.radius + body2.radius)
		>= squared_length(body1.position - body2.position) 
		&& dot(body1.position - body2.position, body1.velocity - body2.velocity) < 0)
	{
		// collision happens
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
	Vector3 relative_posi = body1.position - body2.vertices[0];
	Vector3 edge[3] = { body2.vertices[0] - body2.vertices[1],
		body2.vertices[1] - body2.vertices[2], 
		body2.vertices[2] - body2.vertices[0]};
	Vector3 normal = normalize(cross(edge[0], edge[1]));
	real_t dist = dot(relative_posi, normal);
	if (body1.radius >= abs(dist) && 
		dot(relative_posi, normal) * dot(body1.velocity, normal) < 0)
	{
		relative_posi = relative_posi - normal * dist; //relative posi in tri plane to V0: r
		/* point in triangle:
		 *  r = -t e0 + s e2, t,s>0; t+s<1 
		 *     r dot e0 = - t e0_sq + s e0 dot e2
		 *     r dot e2 = - t e0 dot e2 + s e2_sq
		 */
		real_t r_dot_e0 = dot(edge[0], relative_posi);
		real_t r_dot_e2 = dot(edge[2], relative_posi);
		real_t e0_sq = squared_length(edge[0]);
		real_t e2_sq = squared_length(edge[2]);
		real_t e0e2 = dot(edge[0], edge[2]);
		real_t t = (r_dot_e0 * e2_sq - r_dot_e2 * e0e2) / (e0e2 * e0e2 - e0_sq * e2_sq);
		real_t s = (r_dot_e0 * e0e2 - r_dot_e2 * e0_sq) / (e0e2 * e0e2 - e0_sq * e2_sq);
		if (t >= 0 && s >= 0 && t + s < 1) //dot inside triangle
		{
			// collision happens
			Vector3 perp_velocity = normal * dot(body1.velocity, normal);
			if (squared_length(perp_velocity) < MIN_V_SQ) //ignore too small velocity
			{
				body1.velocity -= perp_velocity;
				return false;
			}
			body1.velocity -= perp_velocity * 2;
			body1.velocity *= (1 - collision_damping);
			return true;
		}
		//TO DO: other critical situation
	}

    return false;
}

bool collides( SphereBody& body1, PlaneBody& body2, real_t collision_damping )
{
    // TODO detect collision. If there is one, update velocity
	Vector3 normal = normalize(body2.normal);
	Vector3 relative_posi = body1.position - body2.position;
	if (abs(dot(normal, relative_posi)) <= body1.radius 
		&& dot(relative_posi, normal) * dot(body1.velocity, normal) < 0)
	{
		// collision happens
		Vector3 perp_velocity = normal * dot(body1.velocity, normal);
		if (squared_length(perp_velocity) < MIN_V_SQ) //ignore too small velocity
		{
			body1.velocity -= perp_velocity;
			return false;
		}
		body1.velocity -= perp_velocity * 2;
		body1.velocity *= (1 - collision_damping);
		return true;
	}
	return false;
}

}
