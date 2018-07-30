#include "Camera.hpp"

using namespace ExcellentPuppy::Engine;

GLdouble Camera::_ratio = 1;

Camera::Camera(
		const GEvector& position,
		const GLfloat& rotationX,
		const GLfloat& rotationY) :
			_position(position),
			_rotationX({rotationX, 1, 0, 0}),
			_rotationY({rotationY, 0, 1, 0}) { }
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

void Camera::setScreenProjection() {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(_ratio < 1)
		glFrustum(-_ratio, _ratio,
				-1.0, 1.0,
				1.0, 100.0);
	else
		glFrustum(-1.0, 1.0,
				-1/_ratio, 1/_ratio,
				1.0, 100.0);
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
	geRotate(-_rotationY);
	geTranslate(-_position);
	// Reset the matrix mode
	glMatrixMode(matrixMode);
}
