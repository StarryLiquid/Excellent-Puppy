#ifndef ENGINE_MOUSECONTROLLER_HPP_
#define ENGINE_MOUSECONTROLLER_HPP_

namespace ExcellentPuppy {
namespace Engine {
	class MouseController {
		private:
			static bool _cameraControlling;
			static int _refX, _refY;

		public:
			static bool getCameraControlling();
			static void setCameraControlling(bool cameraControlling);

			static void registerCallbacks();

		private:
			static void resetMouse();
			// Handle mouse movement
			static void handleMouseMotion(int x, int y);
			static void handleMousePresses(int button, int state, int x, int y);
	};
} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_MOUSECONTROLLER_HPP_ */
