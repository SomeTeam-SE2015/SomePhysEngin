/**
 * @file scene_loader.hpp
 * @brief Scene Loader
 *
 * @author Eric Butler (edbutler)
 */

#ifndef _SomeEngin_APPLICATOIN_SCENELOADER_HPP_
#define _SomeEngin_APPLICATOIN_SCENELOADER_HPP_
#include <iostream>

namespace _SomeEngin {

class Scene;

/**
 * Loads a scene from a .scene file.
 * Clears away the old scene. Prints a message to stdout if an error occurs.
 * @return True on success, false on error.
 * Will clear the scene on error.
 */
bool load_scene( Scene* scene, FILE* file );

} /* _SomeEngin */

#endif /* _SomeEngin_APPLICATOIN_SCENELOADER_HPP_ */

