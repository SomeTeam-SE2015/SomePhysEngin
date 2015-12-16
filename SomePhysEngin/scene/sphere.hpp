/**
 * @file sphere.hpp
 * @brief Class defnition for Sphere.
 *
 * @author Kristin Siu (kasiu)
 * @author Eric Butler (edbutler)
 */

#ifndef _SomeEngin_SCENE_SPHERE_HPP_
#define _SomeEngin_SCENE_SPHERE_HPP_

#include "scene/material.hpp"
#include "scene/geometry.hpp"

namespace _SomeEngin {

/**
 * A sphere, centered on its position with a certain radius.
 */
class Sphere : public Geometry
{
public:

    real_t radius;
    const Material* material;

    Sphere();
    virtual ~Sphere();
    virtual void render() const;

};

} /* _SomeEngin */

#endif /* _SomeEngin_SCENE_SPHERE_HPP_ */

