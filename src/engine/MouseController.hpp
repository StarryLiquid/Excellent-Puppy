#ifndef ENGINE_MOUSECONTROLLER_HPP_
#define ENGINE_MOUSECONTROLLER_HPP_

namespace ExcellentPuppy {
	namespace Engine {

		/**
		 * Controls the mouse.
		 * Can rotate the active camera using mouse input.
		 * Will also hide the cursor when controlling the camera.
		 */
		class MouseController {
			private:
				// Whether the mouse currently controls the camera
				static bool _cameraControlling;
				// Last position of the mosue to use as reference for camera movement
				static int _refX, _refY;

			public:
				static bool getCameraControlling();
				static void setCameraControlling(bool cameraControlling);

				// Register the mosue callbacks
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
