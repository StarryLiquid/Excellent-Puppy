#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

//#include "TextureManager.hpp"
//#include "MouseController.hpp"
//#include "Animator.hpp"
#include "Camera.hpp"

namespace ExcellentPuppy {
namespace Engine {
	class Engine {
		private:
			// TODO
			// TextureManager
			// MouseController
			// Animators
			// Settings
			static Camera* _camera;
			// Entities

		public:
			// TODO
			// tm getter
			// mouse getter
			// animation adder/remover
			// entities adder/remover
			static Camera*& getCamera();
			static void setCamera(Camera* camera);

			static void init(int argc, char** argv);

		private:
			static void initWindow(int argc, char** argv);
			static void initSubsystems();
			static void initScene();
			static void registerCallbacks();
			//TODO: void animate();
			static void render();
	};
} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_ENGINE_HPP_ */
