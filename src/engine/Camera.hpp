#ifndef ENGINE_CAMERA_HPP_
#define ENGINE_CAMERA_HPP_

#include "../Base.hpp"

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		/**
		 * A "camera" object that handles projection in a scene.
		 * Can be moved and rotate around the x,y axis.
		 */
		class Camera : public Base {
			private:
				// The position of the camera
				GEvector _position;
				// The rotation of the camera around the X axis,
				// up and down pitch movement
				GErotation _rotationX;
				// The rotation of the camera around the Y axis,
				// left and right yaw movement
				GErotation _rotationY;
				// The width to height ratio of the screen
				static GLdouble _ratio;
				// A translation vector to be applied after rotation
				GEvector _postPosition;

			public:
				Camera(const GEvector& position = { },
					   const GLfloat& rotationX = 0,
					   const GLfloat& rotationY = 0,
					   const GEvector& postPosition = { });
				virtual ~Camera();

				GEvector& getPosition();
				void setPosition(const GEvector& position);
				GLfloat& getRotationX();
				GLfloat& getRotationY();
				static const GLdouble& getRatio();
				static void setRatio(const GLdouble& ratio);
				GEvector& getPostPosition();
				void setPostPosition(const GEvector& postPosition);

				// Set the frustum screen projection
				static void setScreenProjection();
				// Set the model view matrix based on the camera position and angles
				void setCameraProjection() const;
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_CAMERA_HPP_ */
