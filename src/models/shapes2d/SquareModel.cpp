#include "SquareModel.hpp"

using namespace ExcellentPuppy::Modeling;

GE2Dvector& SquareModel::getDimensions() {
	return _dimensions;
}

SquareModel::SquareModel(GE2Dvector dimensions) :
	_dimensions(dimensions) { }
SquareModel::~SquareModel() { }

void SquareModel::load() const { }
void SquareModel::draw() const {
	glBegin(GL_QUADS);
		glVertex2f(0            , 0);
		glVertex2f(_dimensions.x, 0);
		glVertex2f(_dimensions.x, _dimensions.y);
		glVertex2f(0            , _dimensions.y);
	glEnd();
}
