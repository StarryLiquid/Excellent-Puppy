#include "MouseController.hpp"

#include "Engine.hpp"
#include "Camera.hpp"

using namespace ExcellentPuppy::Engine;

bool MouseController::_mouseLocked = false;
int MouseController::_refX = -1, MouseController::_refY = -1;
void (*MouseController::_onClick)(double, double) = NULL;
void (*MouseController::_onMove)(int, int) = NULL;
bool MouseController::isMouseLocked() {
	return _mouseLocked;
}
void MouseController::setMouseLocked(bool mouseLocked) {
	if(mouseLocked != _mouseLocked) {
		if(mouseLocked) {
			glutSetCursor(GLUT_CURSOR_NONE);
			resetMouse();
		}
		else {
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
	}
	_mouseLocked = mouseLocked;
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
	int dX = x-_refX, dY = y-_refY;
	if(dX != 0 || dY != 0) {
		_refX = x;
		_refY = y;
		auto onMove = _onMove;
		if(onMove != NULL)
			onMove(dX, dY);
		if(_mouseLocked)
			resetMouse();
	}
}
void MouseController::handleMousePresses(int button, int state, int x, int y) {
	auto onClick = _onClick;
	if(onClick != NULL)
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			_onClick((double)(x)/Engine::getScreenWidth(), (double)(y)/Engine::getScreenHeight());
}
