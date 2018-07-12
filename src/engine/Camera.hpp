#ifndef ENGINE_CAMERA_HPP_
#define ENGINE_CAMERA_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
namespace Engine {
	class Camera {
		private:
			GEvector _position;
			GErotation _rotationY;
			GErotation _rotationX;

		public:
			Camera(const GEvector& position = { 0, 0, 0 },
			       const GLfloat& rotationX = 0,
			       const GLfloat& rotationY = 0);
			virtual ~Camera();

			GEvector& getPosition();
			void setPosition(const GEvector& position);
			GLfloat& getRotationX();
			GLfloat& getRotationY();

			void setGLProjection() const;
};
} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_CAMERA_HPP_ */
