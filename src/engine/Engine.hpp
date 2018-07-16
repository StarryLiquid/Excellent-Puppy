#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

#include <list>

//#include "TextureManager.hpp"
//#include "Animator.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class Entity;
	}
	namespace Engine {
		class Camera;
		class Light;

		/**
		 * The game engine, initiates and managed the game
		 */
		class Engine {
			private:
				// TODO
				// TextureManager
				// Animators
				// Settings

				// The current camera in use
				static Camera* _camera;
				// The entities to render in the scene
				static std::list<Entities::Entity*> _entities;

			public:
				// TODO
				// tm getter
				// animation adder/remover
				static std::list<Entities::Entity*>& getEntities();
				static Camera*& getCamera();
				static void setCamera(Camera* camera);

				// Initiate the game engine
				static void init(int argc, char** argv);

			private:
				// Initiates the window to render the scene in
				static void initWindow(int argc, char** argv);
				// Initiates any other classes that are needed
				static void initSubsystems();
				// Build the scene
				static void initScene();
				// Bind the callback functions
				static void registerCallbacks();
				// Load all the entities
				static void loadEntities();
				//TODO: void animate();
				// Callback to render the scene
				static void render();
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_ENGINE_HPP_ */
