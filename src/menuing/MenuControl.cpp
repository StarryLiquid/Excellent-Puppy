#include "MenuControl.hpp"

using namespace ExcellentPuppy::Menuing;

const GE2Dvector& MenuControl::getPosition() const {
	return _position;
}
void MenuControl::setPosition(GE2Dvector& position) {
	_position = position;
}

MenuControl::MenuControl(GE2Dvector position) :
	_position(position) { }
MenuControl::~MenuControl() { }

void MenuControl::render() const {
	// Move to the control's position
	geTranslate(_position);
	draw();
}
