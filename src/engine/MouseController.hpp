#ifndef ENGINE_MOUSECONTROLLER_HPP_
#define ENGINE_MOUSECONTROLLER_HPP_

namespace ExcellentPuppy {
	namespace Engine {

		/**
		 * Controls the mouse.
		 * Can lock the mouse, recording movement.
		 * Will also hide the cursor when mouse is locked.
		 */
		class MouseController {
			private:
				// Whether the mouse is locked
				static bool _mouseLocked;
				// Last position of the mouse to use as reference for camera movement
				static int _refX, _refY;
			public:
				// An action to do on left mouse click
				// Receives location of mouse when clicked
				static void(*_onLeftClick)(double, double);
				// An action to do on right mouse click
				// Receives location of mouse when clicked
				static void(*_onRightClick)(double, double);
				// An action to do on mouse moves
				// Receives difference in mouse position
				static void(*_onMove)(int, int);

				static bool isMouseLocked();
				static void setMouseLocked(bool mouseLocked);

				// Register the mouse callbacks
				static void registerCallbacks();

			private:
				// Reset the mouse position to the center of the screen
				static void resetMouse();
				// Handle mouse movement
				static void handleMouseMotion(int x, int y);
				// Handle mouse clicks
				static void handleMousePresses(int button, int state, int x, int y);
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_MOUSECONTROLLER_HPP_ */
