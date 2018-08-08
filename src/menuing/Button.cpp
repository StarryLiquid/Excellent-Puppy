#include "../menuing/Button.hpp"

#include "../models/shapes2d/SquareModel.hpp"

using namespace ExcellentPuppy::Menuing;

ExcellentPuppy::Modeling::Model2D * const Button::getModel() const {
	return _model;
}
void Button::setModel(Modeling::Model2D * const model) {
	_model = model;
}
void (*Button::getAction())(void* context) const {
	return _action;
}
void Button::setAction(void (*action)(void* context)) {
	_action = action;
}

Button::Button(GE2Dvector position, Modeling::Model2D *model, void (*action)(void* context), void* context) :
	MenuControl(position),
	_model(model),
	_action(action),
	_context(context) { }
Button::~Button() { }

#include <iostream>
bool Button::testCollision(const GE2Dvector& point) const {
	auto correctedPoint = point - getPosition();
	return correctedPoint.x > 0 && correctedPoint.y > 0 &&
			correctedPoint.x < _model->getDimensions().x &&
			correctedPoint.y < _model->getDimensions().y;
}
bool Button::handleClick(const GE2Dvector& position) {
	_action(_context);
	return true;
}
void Button::draw() const {
	_model->render();
}
