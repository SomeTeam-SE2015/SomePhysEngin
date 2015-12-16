/**
 * @file model.hpp
 * @brief Model class
 *
 * @author Eric Butler (edbutler)
 */

#ifndef _SomeEngin_SCENE_MODEL_HPP_
#define _SomeEngin_SCENE_MODEL_HPP_

#include "scene/material.hpp"
#include "scene/geometry.hpp"
#include "scene/mesh.hpp"

namespace _SomeEngin {

/**
 * A mesh of triangles.
 */
class Model : public Geometry
{
public:

    const Mesh* mesh;
    const Material* material;

    Model();
    virtual ~Model();

    virtual void render() const;

};


} /* _SomeEngin */

#endif /* _SomeEngin_SCENE_MODEL_HPP_ */

