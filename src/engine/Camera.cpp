#include "Camera.hpp"

using namespace ExcellentPuppy::Engine;

GLdouble Camera::_ratio = 1;

Camera::Camera(
		const GEvector& position,
		const GLfloat& rotationX,
		const GLfloat& rotationY,
		const GEvector& postPosition) :
			_position(position),
			_rotationX({rotationX, 1, 0, 0}),
			_rotationY({rotationY, 0, 1, 0}),
			_postPosition(postPosition) { }
Camera::~Camera() { }

GEvector& Camera::getPosition() {
	return _position;
}
void Camera::setPosition(const GEvector& cameraPosition = { 0, 0, 0 }) {
	this->_position = cameraPosition;
}
GLfloat& Camera::getRotationX() {
	return _rotationX.degrees;
}
GLfloat& Camera::getRotationY() {
	return _rotationY.degrees;
}
const GLdouble& Camera::getRatio() {
	return _ratio;
}
void Camera::setRatio(const GLdouble& ratio) {
	_ratio = ratio;
	setScreenProjection();
}
GEvector& Camera::getPostPosition() {
	return _postPosition;
}
void Camera::setPostPosition(const GEvector& postPosition) {
	_postPosition = postPosition;
}

void Camera::setScreenProjection() {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// A fixing ratio to prevent near plane clipping with floor during FPS mode
	GLdouble perspectiveRatio = 0.7;
	if(_ratio < 1)
		glFrustum(-_ratio*perspectiveRatio, _ratio*perspectiveRatio,
				-perspectiveRatio, perspectiveRatio,
				perspectiveRatio, 50.0);
	else
		glFrustum(-perspectiveRatio, perspectiveRatio,
				-perspectiveRatio/_ratio, perspectiveRatio/_ratio,
				perspectiveRatio, 50.0);
	// Reset the matrix mode
	glMatrixMode(matrixMode);
}
// Only load the look at projections once
static bool firstProjection = true;
void Camera::setCameraProjection() const {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	glMatrixMode(GL_MODELVIEW);
	// Projection matrix has yet to be initialized
	if(firstProjection) {
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 0.0,
				  0.0, 0.0, -3.0,
				  0.0, 1.0, 0.0);
		glPushMatrix();

		firstProjection = false;
	}
	// Reset to projection matrix
	else {
		glPopMatrix();
		glPushMatrix();
	}
	// Rotate and move the scene based on the camera position
	geRotate(-_rotationX);
	geTranslate(-_postPosition);
	geRotate(-_rotationY);
	geTranslate(-_position);
	// Reset the matrix mode
	glMatrixMode(matrixMode);
}
