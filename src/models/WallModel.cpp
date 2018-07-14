#include "WallModel.hpp"

#include <GL/freeglut.h>

using namespace ExcellentPuppy::Modeling;
		
WallModel::WallModel() { }
WallModel::~WallModel() { }

void WallModel::load() const { }
void WallModel::draw() const {
	glBegin(GL_QUADS);
		glVertex3f(-10, 0 , -15);
		glVertex3f(-10, 20, -15);
		glVertex3f(-10, 20, 15 );
		glVertex3f(-10, 0 , 15 );
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-10, 0 , 15 );
		glVertex3f(-10, 20, 15 );
		glVertex3f(10 , 20, 15 );
		glVertex3f(10 , 0 , 15 );
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(10 , 0 , 15 );
		glVertex3f(10 , 20, 15 );
		glVertex3f(10 , 20, -15);
		glVertex3f(10 , 0 , -15);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(10 , 0 , -15);
		glVertex3f(10 , 20, -15);
		glVertex3f(-10, 20, -15);
		glVertex3f(-10, 0 , -15);
	glEnd();
}
