#include "physics/physics.hpp"
#include <iostream>

namespace _462 {

Physics::Physics()
{
    reset();
}

Physics::~Physics()
{
    reset();
}

void Physics::step( real_t dt )
{
    // TODO step the world forward by dt. Need to detect collisions, apply
    // forces, and integrate positions and orientations.
    //
    // Note: put RK4 here, not in any of the physics bodies
    //
    // Must use the functions that you implemented
    //
    // Note, when you change the position/orientation of a physics object,
    // change the position/orientation of the graphical object that represents
    // it

	// collisions
	//std::cout << "num planes" << num_planes() << std::endl;
	for (SphereList::iterator collider = spheres.begin();
		collider != spheres.end(); collider++)
	{
		//if ( (*collider)->position.y <= 0 )
		for (SphereList::iterator collidee = spheres.begin();
			collidee != spheres.end(); collidee++)
		{
			if (collidee != collider)
			{
				collides(**collider, **collidee, collision_damping);
			}
		}
		for (PlaneList::iterator collidee = planes.begin();
			collidee != planes.end(); collidee++)
		{
			if (collides(**collider, **collidee, collision_damping)) {
				//std::cout << "Plane" << (*collidee)->id << ":" << (*collidee)->position << std::endl;
			}
			
		}
		for (TriangleList::iterator collidee = triangles.begin();
			collidee != triangles.end(); collidee++)
		{
			if (collides(**collider, **collidee, collision_damping)) {
				//std::cout << "Tri" << (*collidee)->id << ":" << (*collider)->velocity << std::endl;
			}
		}
	}

	// Evolision: RK4
	for (int n = 0; n < spheres.size(); n++)
	{
		v0s[n] = spheres[n]->velocity;
		x0s[n] = spheres[n]->position;
	}
	update_force();
	for (int n = 0; n < spheres.size(); n++)
	{
		spheres[n]->step_position(dt / 2, 0);
		rk4_dvdt[n] = (spheres[n]->velocity - v0s[n]); // k1 * dt / 2
		rk4_dxdt[n] = (spheres[n]->position - x0s[n]);
	}
	update_force();
	for (int n = 0; n < spheres.size(); n++)
	{
		spheres[n]->step_position(dt / 2, 0);
		rk4_dvt[n] = (spheres[n]->velocity - v0s[n]); // k2 * dt / 2
		rk4_dxt[n] = (spheres[n]->position - x0s[n]);
		spheres[n]->velocity = v0s[n] + rk4_dvt[n];
		spheres[n]->position = x0s[n] + rk4_dxt[n];
	}
	update_force();
	for (int n = 0; n < spheres.size(); n++)
	{
		spheres[n]->step_position(dt / 2, 0);
		rk4_dvm[n] = (spheres[n]->velocity - v0s[n]); // k3 * dt / 2
		rk4_dxm[n] = (spheres[n]->position - x0s[n]);
		spheres[n]->velocity = v0s[n] + rk4_dvm[n];
		spheres[n]->position = x0s[n] + rk4_dxm[n];
		rk4_dvm[n] += rk4_dvt[n]; // k2 + k3
		rk4_dxm[n] += rk4_dxt[n];
	}
	update_force();
	for (int n = 0; n < spheres.size(); n++)
	{
		spheres[n]->step_position(dt / 2, 0);
		rk4_dvt[n] = (spheres[n]->velocity - v0s[n]); // k4 * dt / 2
		rk4_dxt[n] = (spheres[n]->position - x0s[n]);
		spheres[n]->velocity = v0s[n] + (rk4_dvdt[n] + 2*rk4_dvm[n] + rk4_dvt[n]) / 3;
		// (k1 + 2 k2 + 2 k3 + k4) * dt /6
		spheres[n]->position = x0s[n] + (rk4_dxdt[n] + 2 * rk4_dxm[n] + rk4_dxt[n]) / 3;
	}

	//update sphere geom
	for (SphereList::iterator one = spheres.begin(); one != spheres.end(); one++)
	{
		(*one)->update_geom();
	}
}

void Physics::update_force()
{
	if (static_force_not_initied) //initial for gravity
	{
		for (SphereList::iterator one = spheres.begin(); one != spheres.end(); one++)
		{
			(*one)->apply_force_static(gravity * (*one)->mass, Vector3::Zero);
		}
		static_force_not_initied = false;
	}
	// initial: clear and apply gravity
	if (num_springs() != 0)
	{
		for (SphereList::iterator one = spheres.begin(); one != spheres.end(); one++)
		{
			(*one)->clear_force();
			// TO DO: update interaction
		}
	}
}

void Physics::add_sphere( SphereBody* b )
{
    spheres.push_back( b );

	v0s.push_back(Vector3::Zero);
	x0s.push_back(Vector3::Zero);
	rk4_dvdt.push_back(Vector3::Zero);
	rk4_dxdt.push_back(Vector3::Zero);
	rk4_dvm.push_back(Vector3::Zero);
	rk4_dxm.push_back(Vector3::Zero);
	rk4_dvt.push_back(Vector3::Zero);
	rk4_dxt.push_back(Vector3::Zero);
}

size_t Physics::num_spheres() const
{
    return spheres.size();
}

void Physics::add_plane( PlaneBody* p )
{
    planes.push_back( p );
}

size_t Physics::num_planes() const
{
    return planes.size();
}

void Physics::add_triangle( TriangleBody* t )
{
    triangles.push_back( t );
}

size_t Physics::num_triangles() const
{
    return triangles.size();
}

void Physics::add_spring( Spring* s )
{
    springs.push_back( s );
}

size_t Physics::num_springs() const
{
    return springs.size();
}

void Physics::reset()
{
    for ( SphereList::iterator i = spheres.begin(); i != spheres.end(); i++ ) {
        delete *i;
    }
    for ( PlaneList::iterator i = planes.begin(); i != planes.end(); i++ ) {
        delete *i;
    }
    for ( TriangleList::iterator i = triangles.begin(); i != triangles.end(); i++ ) {
        delete *i;
    }
    for ( SpringList::iterator i = springs.begin(); i != springs.end(); i++ ) {
        delete *i;
    }

    spheres.clear();
    planes.clear();
    triangles.clear();
    springs.clear();
    
    gravity = Vector3::Zero;
	collision_damping = 0.0;
	static_force_not_initied = true;
}

}
