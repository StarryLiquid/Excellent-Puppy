#include "MouseController.hpp"

#include "Engine.hpp"
#include "Camera.hpp"

using namespace ExcellentPuppy::Engine;

bool MouseController::_cameraControlling = false;
int MouseController::_refX = -1, MouseController::_refY = -1;
bool MouseController::getCameraControlling() {
	return _cameraControlling;
}
void MouseController::setCameraControlling(bool cameraControlling) {
	if(cameraControlling != _cameraControlling) {
		if(cameraControlling) {
			glutSetCursor(GLUT_CURSOR_NONE);
			resetMouse();
		}
		else {
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
	}
	_cameraControlling = cameraControlling;
}

void MouseController::resetMouse() {
	_refX = glutGet(GLUT_WINDOW_WIDTH)/2;
	_refY = glutGet(GLUT_WINDOW_HEIGHT)/2;
	glutWarpPointer(_refX, _refY);
}

void MouseController::registerCallbacks() {
	glutPassiveMotionFunc(handleMouseMotion);
	glutMouseFunc(MouseController::handleMousePresses);
}
void MouseController::handleMouseMotion (int x, int y) {
	Camera *camera = Engine::getCamera();
	int dX = x-_refX, dY = y-_refY;
	if(_cameraControlling && camera != NULL && (dX != 0 || dY != 0)){
		camera->getRotationY() -= dX;
		camera->getRotationX() -= dY;

		// Clamp x rotation so the camera will never go upside down
		if(camera->getRotationX() < -90)
			camera->getRotationX() = -90;
		if(camera->getRotationX() > 90)
			camera->getRotationX() = 90;
		camera->setGLProjection();
		resetMouse();
	}
}
void MouseController::handleMousePresses(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		MouseController::setCameraControlling(!MouseController::getCameraControlling());
	}
	// TODO: Handle clicks while menuing
}
