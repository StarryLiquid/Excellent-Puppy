#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

#include <list>

//#include "TextureManager.hpp"
//#include "Animator.hpp"
#include "../object/Entity.hpp"
#include "Camera.hpp"

namespace ExcellentPuppy {
namespace Engine {
	class Engine {
		private:
			// TODO
			// TextureManager
			// Animators
			// Settings
			static Camera* _camera;
			static std::list<Entities::Entity*> _entities;

		public:
			// TODO
			// tm getter
			// animation adder/remover
			static std::list<Entities::Entity*>& getEntities();
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
