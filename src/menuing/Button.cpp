#include "../menuing/Button.hpp"

#include "../models/shapes2d/SquareModel.hpp"

using namespace ExcellentPuppy::Menuing;

ExcellentPuppy::Modeling::SquareModel * const Button::getModel() const {
	return _model;
}
void Button::setModel(Modeling::SquareModel * const model) {
	_model = model;
}
void (*Button::getAction())() const {
	return _action;
}
void Button::setAction(void (*action)()) {
	_action = action;
}

Button::Button(GE2Dvector position, Modeling::SquareModel *model, void (*action)()) :
	MenuControl(position),
	_model(model),
	_action(action) { }
Button::~Button() { }

#include <iostream>
bool Button::testCollision(const GE2Dvector& point) const {
	auto correctedPoint = point - getPosition();
	return correctedPoint.x > 0 && correctedPoint.y > 0 &&
			correctedPoint.x < _model->getDimensions().x &&
			correctedPoint.y < _model->getDimensions().y;
}
bool Button::handleClick(const GE2Dvector& position) {
	_action();
	return true;
}
void Button::draw() const {
	_model->render();
}
