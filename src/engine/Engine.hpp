#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

#include <list>
#include "MouseController.hpp"

//#include "TextureManager.hpp"
//#include "Animator.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class Entity;
		class Dog;
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

				// Width of the screen
				static int _screenWidth;
				// Height of the screen
				static int _screenHeight;
				// The current camera in use
				static Camera* _camera;
				// The entities to render in the scene
				static std::list<Entities::Entity*> _entities;
				// The dog entity
				static Entities::Dog *_dog;

				// An action to move the camera when the mosue moves
				static decltype(MouseController::_onMove) _moveCamera;
				// An action to switch between mouse look and menu mode
				static decltype(MouseController::_onClick) _switchToMenu;

			public:
				// TODO
				// tm getter
				// animation adder/remover
				static const int& getScreenWidth();
				static const int& getScreenHeight();
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

				// Handles keyboard input
				static void handlelKeyboard (unsigned char, int, int);
				// Handles special keyboard input
				static void handleSpecialKeyboard (int, int, int);
				// Handle screen reshape
				static void handleScreenReshape(int width, int height);
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_ENGINE_HPP_ */
