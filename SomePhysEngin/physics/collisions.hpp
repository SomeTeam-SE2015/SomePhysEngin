#ifndef _SomeEngin_COLLISIONS_HPP_
#define _SomeEngin_COLLISIONS_HPP_

#include "scene/sphere.hpp"
#include "physics/spherebody.hpp"
#include "physics/trianglebody.hpp"
#include "physics/planebody.hpp"

#define MIN_V_SQ 1E-6

namespace _SomeEngin {

bool collides( SphereBody& body1, SphereBody& body2, real_t collision_damping );
bool collides( SphereBody& body1, TriangleBody& body2, real_t collision_damping );
bool collides( SphereBody& body1, PlaneBody& body2, real_t collision_damping );

}

#endif
