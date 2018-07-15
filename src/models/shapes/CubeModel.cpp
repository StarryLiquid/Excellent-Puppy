#include "CubeModel.hpp"

#include "../geometries/QuadGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

static const GEvector bottomNormal = { 0, -1,  0 };
static const GEvector topNormal    = { 0, -1,  0 };
static const GEvector backNormal   = { 0,  0,  1 };
static const GEvector frontNormal  = { 0,  0, -1 };
static const GEvector leftNormal   = {-1,  0,  0 };
static const GEvector rightNormal  = { 1,  0,  0 };

unsigned int GEcubeSide::sidesCount() const {
	return top + bottom + front + back + left + right;
}

const GEvector& CubeModel::getDimensions() {
	return _dimensions;
}
const GEcubeSide& CubeModel::getSides() {
	return _sides;
}
const bool& CubeModel::isFacingInside() {
	return _facingInside;
}

CubeModel::CubeModel(const GEvector& dimensions,
           const GEcubeSide& sides,
           const bool& facingInside) :
	_dimensions(dimensions),
	_sides(sides),
	_facingInside(facingInside) { }
CubeModel::~CubeModel() {}

void CubeModel::load() const { }
void CubeModel::draw() const {
	// Need to reverse normals if rendering inside out
	GLdouble normalSide=1;
	if(_facingInside) {
		glFrontFace(GL_CW);
		normalSide = -1;
	}
	if(_sides.bottom) {
		geNormal(bottomNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, 0);
		glEnd();
	}
	if(_sides.top) {
		geNormal(topNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
			glVertex3f(0, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.back) {
		geNormal(backNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, _dimensions.y, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(_dimensions.x, 0, 0);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.front) {
		geNormal(frontNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
		glEnd();
	}
	if(_sides.left) {
		geNormal(leftNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(0, 0, 0);
			glVertex3f(0, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.right) {
		geNormal(rightNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
			glVertex3f(_dimensions.x, 0, 0);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
		glEnd();
	}
	glFrontFace(GL_CCW);
}
