#include "scene/geometry.hpp"

namespace _SomeEngin {

Geometry::Geometry():
    position( Vector3::Zero ),
    orientation( Quaternion::Identity ),
    scale( Vector3::Ones )
{

}

Geometry::~Geometry() { } 

}
