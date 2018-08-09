#include "Slider.hpp"

#include "../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Menuing;

const GE2Dvector Slider::SLIDER_DIMENSIONS = {0.5, 0.1};
const GE2Dvector Slider::KNOB_DIMENSIONS = {SLIDER_DIMENSIONS.y/2, SLIDER_DIMENSIONS.y};
const GE2Dvector Slider::TRACK_DIMENSIONS = {SLIDER_DIMENSIONS.x, SLIDER_DIMENSIONS.y/4};

Slider::Slider(GE2Dvector position, GLfloat value, void (*update)(void* context, GLfloat value), void* context):
	MenuControl(position),
	_value(value),
	_update(update),
	_context(context),
	_knob(KNOB_DIMENSIONS),
	_track(TRACK_DIMENSIONS) {
	auto knobColor = new Modeling::ColorMaterial({1, 1, 0});
	_knob.setMaterial(knobColor);
	auto trackColor = new Modeling::ColorMaterial({0.2, 0.2, 0.5});
	_track.setMaterial(trackColor);
	getDependents()->insert(knobColor);
	getDependents()->insert(trackColor);
}
Slider::~Slider() { }

GLfloat const & Slider::getValue() {
	return _value;
}

bool Slider::testCollision(const GE2Dvector& point) const {
	auto correctedPoint = point - getPosition();
	return correctedPoint.x >= 0 && correctedPoint.y >= 0 &&
			correctedPoint.x <= SLIDER_DIMENSIONS.x &&
			correctedPoint.y <= SLIDER_DIMENSIONS.y;
}
bool Slider::handleClick(const GE2Dvector& position) {
	_value = (position.x - getPosition().x)/SLIDER_DIMENSIONS.x;
	_update(_context, _value);
	return true;
}
void Slider::draw() const {
	glPushMatrix();

	glTranslated(0, (SLIDER_DIMENSIONS.y - TRACK_DIMENSIONS.y)/2, 0);
	_track.render();
	glTranslated((TRACK_DIMENSIONS.x - KNOB_DIMENSIONS.x)*_value, (TRACK_DIMENSIONS.y - KNOB_DIMENSIONS.y)/2, -1);
	_knob.render();

	glPopMatrix();
}
