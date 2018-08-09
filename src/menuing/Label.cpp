#include "Label.hpp"

using namespace ExcellentPuppy::Menuing;
		
Label::Label(GE2Dvector position, std::string text) :
	MenuControl(position),
	_model(text) { }
Label::~Label() { }

bool Label::testCollision(const GE2Dvector& point) const {
	return false;
}
bool Label::handleClick(const GE2Dvector& position) {
	return false;
}
void Label::draw() const{
	glPushMatrix();

	glColor3f(0, 0, 0);
	auto scale = 1/_model.getDimensions().y/11;
	auto correctedModelDimensions = _model.getDimensions()*scale;
	glTranslated(-correctedModelDimensions.x/2, -correctedModelDimensions.y/2, 0);
	glScaled(scale, scale, 1);
	_model.render();

	glPopMatrix();
}
