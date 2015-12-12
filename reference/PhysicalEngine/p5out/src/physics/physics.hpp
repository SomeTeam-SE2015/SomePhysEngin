#ifndef _462_PHYSICS_PHYSICS_HPP_
#define _462_PHYSICS_PHYSICS_HPP_

#include "math/math.hpp"
#include "math/quaternion.hpp"
#include "math/vector.hpp"
#include "physics/body.hpp"
#include "physics/spherebody.hpp"
#include "physics/trianglebody.hpp"
#include "physics/planebody.hpp"
#include "physics/spring.hpp"
#include "physics/collisions.hpp"

#include <vector>

namespace _462 {

class Physics
{
public:
    Vector3 gravity;
	real_t collision_damping;

    Physics();
    ~Physics();

    void step( real_t dt );
    void add_sphere( SphereBody* s );
    size_t num_spheres() const;
    void add_plane( PlaneBody* p );
    size_t num_planes() const;
    void add_triangle( TriangleBody* t );
    size_t num_triangles() const;
    void add_spring( Spring* s );
    size_t num_springs() const;

    void reset();

private:
    typedef std::vector< Spring* > SpringList;
    typedef std::vector< SphereBody* > SphereList;
	typedef std::vector< PlaneBody* > PlaneList;
	typedef std::vector< TriangleBody* > TriangleList;
	typedef std::vector< Vector3 > VectorList;

    SpringList springs;
    SphereList spheres;
    PlaneList planes;
    TriangleList triangles;

	VectorList v0s;
	VectorList x0s;
	VectorList rk4_dvdt;
	VectorList rk4_dxdt; //k1
	VectorList rk4_dvm;
	VectorList rk4_dxm; //k2+k3
	VectorList rk4_dvt;
	VectorList rk4_dxt; //k4

	bool static_force_not_initied;
	virtual void update_force();
};

}

#endif

