#include "../menuing/Button.hpp"

#include "../models/shapes2d/SquareModel.hpp"

using namespace ExcellentPuppy::Menuing;
		
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
void Button::click(const GE2Dvector& point) {
	_action();
}
void Button::draw() const {
	_model->render();
}
