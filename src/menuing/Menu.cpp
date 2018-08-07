#include "../menuing/Menu.hpp"

#include <GL/freeglut.h>
#include "MenuControl.hpp"

using namespace ExcellentPuppy::Menuing;

std::list<MenuControl*>& Menu::getControls() {
	return _controls;
}

Menu::Menu() { }
Menu::~Menu() { }

void Menu::render() {
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);

	// Disables projection transformation for menu render
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	// Disables modelview transformation for menu render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Disable lighting for menu rendering
	glDisable(GL_LIGHTING);

	for(auto button : _controls)
		button->render();

	// Reenable lighting
	glEnable(GL_LIGHTING);

	// Restore modelview and projection metrices
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	// Reset the matrix mode
	glMatrixMode(matrixMode);
}
void Menu::handleClick(const GE2Dvector& position) {
	for(auto control : _controls)
		if(control->testCollision(position)) {
			control->click(position);
			break;
		}
}
