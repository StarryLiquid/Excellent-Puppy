#ifndef ENGINE_CAMERA_HPP_
#define ENGINE_CAMERA_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		/**
		 * A "camera" object that handles projection in a scene.
		 * Can be moved and rotate around the x,y axis.
		 */
		class Camera {
			private:
				// The negative position of the camera
				GEvector _position;
				// The rotation of the camera around the X axis,
				// up and down pitch movement
				GErotation _rotationX;
				// The rotation of the camera around the Y axis,
				// left and right yaw movement
				GErotation _rotationY;

			public:
				Camera(const GEvector& position = { },
					   const GLfloat& rotationX = 0,
					   const GLfloat& rotationY = 0);
				virtual ~Camera();

				GEvector& getPosition();
				void setPosition(const GEvector& position);
				GLfloat& getRotationX();
				GLfloat& getRotationY();

				// Set the projection matrix based on the camera position and angles
				void setGLProjection() const;
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_CAMERA_HPP_ */
