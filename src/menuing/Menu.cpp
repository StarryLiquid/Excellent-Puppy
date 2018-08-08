#include "../menuing/Menu.hpp"

#include <GL/freeglut.h>
#include "MenuControl.hpp"

using namespace ExcellentPuppy::Menuing;

std::list<MenuControl*>& Menu::getControls() {
	return _controls;
}

Menu::Menu() :
	MenuControl({}) { }
Menu::~Menu() { }

bool Menu::testCollision(const GE2Dvector& point) const {
	return true;
}
bool Menu::handleClick(const GE2Dvector& position) {
	auto correctedPosition = position - getPosition();
	for(auto control : _controls)
		if(control->testCollision(correctedPosition))
			if(control->handleClick(correctedPosition))
				return true;
	return false;
}
void Menu::draw() const {
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
