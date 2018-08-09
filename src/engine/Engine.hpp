#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

#include "../Base.hpp"

#include <list>
#include <GL/freeglut.h>
#include "MouseController.hpp"

//#include "TextureManager.hpp"
//#include "Animator.hpp"

struct GEvector;

namespace ExcellentPuppy {
	namespace Entities {
		class Entity;
		class Dog;
	}
	namespace Menuing {
		class MainMenu;
	}
	namespace Engine {
		class Camera;
		class Light;
		class DirectionalLight;

		/**
		 * The distinct states of the game
		 */
		enum GameState {
			Walking,
			Tail,
			WalkingFPS,
			Menu
		};
		/**
		 * The game engine, initiates and managed the game
		 */
		class Engine {
			private:
				// TODO
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
				// The entities collide with
				static std::list<Entities::Entity*> _collisionEntities;
				// The dog entity
				static Entities::Dog *_dog;
				// The current game state
				static GameState _currentState;
				// The main menu
				static Menuing::MainMenu *_menu;
				// The last state going to menu
				static GameState _lastState;
				// A directional light in the scene
				static DirectionalLight* _directionalLight;
				// The ambient light intensity, from 0 to 1
				static GLfloat _ambientLight;
				// The directional light intensity, from 0 to 1
				static GLfloat _directionalLightPower;
				// The directional light angle, from 0 to 360
				static GLfloat _directionalLightAngle;
				// The directional light position
				static GEvector _directionalLightPosition;

				// An action to move the camera when the mosue moves
				static decltype(MouseController::_onMove) _moveCamera;
				// An action to move the camera when the mosue moves
				static decltype(MouseController::_onMove) _moveTail;
				// An action to switch between mouse look and menu mode
				static decltype(MouseController::_onLeftClick) _switchToMenu;
				// An action to switch between third person and first person
				static decltype(MouseController::_onRightClick) _switchPerspectives;
				// An action to pass mouse clicks to the menu
				static decltype(MouseController::_onRightClick) _clickMenu;

			public:
				// TODO animation adder/remover
				static const int& getScreenWidth();
				static const int& getScreenHeight();
				static std::list<Entities::Entity*>& getEntities();
				static std::list<Entities::Entity*>& getCollisionEntities();
				static Camera*& getCamera();
				static void setCamera(Camera* camera);
				static GLfloat getAmbientLight();
				static void setAmbientLight(GLfloat power);
				static GLfloat getDirectionalLightPower();
				static void setDirectionalLightPower(GLfloat power);
				static GLfloat getDirectionalLightAngle();
				static void setDirectionalLightAngle(GLfloat angle);
				static GLfloat getDirectionalLightXCoords();
				static void setDirectionalLightXCoords(GLfloat x);
				static GLfloat getDirectionalLightZCoords();
				static void setDirectionalLightZCoords(GLfloat z);
				static const GameState& getCurrentState();
				static void setCurrentState(const GameState& state);

				// Initiate the game engine
				static void init(int argc, char** argv);

			private:
				// Initiates the window to render the scene in
				static void initWindow(int argc, char** argv);
				// Initiates any other classes that are needed
				static void initSubsystems();
				// Build the scene
				static void initScene();
				// Build the menu
				static void initMenu();
				// Bind the callback functions
				static void registerCallbacks();
				// Load all the entities
				static void loadEntities();
				//TODO: void animate();
				// Callback to render the scene
				static void render();
				// Update the camera position based on the displacement
				static void updateCameraPosition();
				// Change the entity's position based on collision with objects in scene
				// Added wall collision parameter to account for entities with wide upper parts
				static void doCollision(Entities::Entity* entity, GLfloat wallCollisionDelta);

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
