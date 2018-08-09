#include "RhombusModel.hpp"

using namespace ExcellentPuppy::Modeling;
		
RhombusModel::RhombusModel(GE2Dvector dimensions) :
	SquareModel(dimensions) { }
RhombusModel::~RhombusModel() { }

void RhombusModel::draw() const {
	glBegin(GL_QUADS);
		glVertex2f(getDimensions().x  , getDimensions().y/2);
		glVertex2f(getDimensions().x/2, getDimensions().y);
		glVertex2f(0                  , getDimensions().y/2);
		glVertex2f(getDimensions().x/2, 0);
	glEnd();
}
