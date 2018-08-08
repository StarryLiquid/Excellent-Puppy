#include "LabeledButton.hpp"

using namespace ExcellentPuppy::Menuing;

#include "../models/shapes2d/SquareModel.hpp"
#include "../models/shapes2d/TextModel.hpp"
#include "../models/materials/ColorMaterial.hpp"

std::string LabeledButton::getLabel() const {
	return _labelModel->getText();
}
void LabeledButton::setLabel(std::string label) {
	_labelModel->setText(label);
}
		
LabeledButton::LabeledButton(std::string label,
		GE2Dvector position,
		Modeling::Model2D *model,
		void (*action)(void* context),
		void* context) :
			Button(position, model, action, context),
			_labelModel(new Modeling::TextModel(label)),
			_labelColor(new Modeling::ColorMaterial({0, 0, 0})) {
	_labelModel->setMaterial(_labelColor);
}
LabeledButton::~LabeledButton() {
	delete(_labelModel);
	delete(_labelColor);
}

void LabeledButton::draw() const {
	// Draw the button bounds
	Button::draw();

	// Draw the text in front of the background model
	glPushMatrix();
	auto scale = 1/_labelModel->getDimensions().y/11;
	auto translateDimensions = (getModel()->getDimensions() - (_labelModel->getDimensions()*scale))/2;
	glTranslated(translateDimensions.x, translateDimensions.y+0.01, -1);
	glScaled(scale, scale, 1);
	_labelModel->render();
	glPopMatrix();
}
