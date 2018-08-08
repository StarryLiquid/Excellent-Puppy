#include "SquareModel.hpp"

using namespace ExcellentPuppy::Modeling;

GE2Dvector const & SquareModel::getDimensions() const {
	return _dimensions;
}
void SquareModel::setDimensions(GE2Dvector const & dimensions) {
	_dimensions = dimensions;
}

SquareModel::SquareModel(GE2Dvector dimensions) :
	_dimensions(dimensions) { }
SquareModel::~SquareModel() { }

void SquareModel::load() const { }
void SquareModel::draw() const {
	glBegin(GL_QUADS);
		glVertex2f(0                , 0);
		glVertex2f(getDimensions().x, 0);
		glVertex2f(getDimensions().x, getDimensions().y);
		glVertex2f(0                , getDimensions().y);
	glEnd();
}
