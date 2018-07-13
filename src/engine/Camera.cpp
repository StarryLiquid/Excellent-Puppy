#include "Camera.hpp"

using namespace ExcellentPuppy::Engine;

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

static bool firstProjection = true;
void Camera::setGLProjection() const {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	glMatrixMode(GL_PROJECTION);
	if(firstProjection) {
		glLoadIdentity();
		glFrustum(-1.0, 1.0,
				  -1.0, 1.0,
				   1.0, 20.0);
		gluLookAt(0.0, 0.0, 0.0,
				  0.0, 0.0, -3.0,
				  0.0, 1.0, 0.0);
		glPushMatrix();

		firstProjection = false;
	}
	glPopMatrix();
	glPushMatrix();
	geRotate(_rotationX);
	geRotate(_rotationY);
	geTranslate(_position);
	glMatrixMode(matrixMode);
}
