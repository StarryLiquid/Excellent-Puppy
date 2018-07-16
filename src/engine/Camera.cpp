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

// Only load the frustrum and look at projections once
static bool firstProjection = true;
void Camera::setGLProjection() const {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	// Projection matrix has yet to be initialized
	if(firstProjection) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-1.0, 1.0,
				  -1.0, 1.0,
				   1.0, 100.0);
		glMatrixMode(GL_MODELVIEW);
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
	glTranslatef(0, 0, 1);
	geRotate(-_rotationX);
	glTranslatef(0, 0, -1);
	geRotate(-_rotationY);
	geTranslate(-_position);
	// Reset the matrix mode
	glMatrixMode(matrixMode);
}
