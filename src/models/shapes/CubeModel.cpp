#include "CubeModel.hpp"

#include "../geometries/QuadGeometry.hpp"
#include "../materials/Material.hpp"

using namespace ExcellentPuppy::Modeling;

static const GEvector bottomNormal = { 0, -1,  0 };
static const GEvector topNormal    = { 0, -1,  0 };
static const GEvector backNormal   = { 0,  0,  1 };
static const GEvector frontNormal  = { 0,  0, -1 };
static const GEvector leftNormal   = {-1,  0,  0 };
static const GEvector rightNormal  = { 1,  0,  0 };

unsigned int GEcubeSide::sidesCount() const {
	return (top != NULL) + (bottom != NULL) + (front != NULL) + (back != NULL) + (left != NULL) + (right != NULL);
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
	// Need to reverse normals and faces if rendering inside out
	GLdouble normalSide = 1;
	if(_facingInside) {
		geSwitchFrontFace();
		normalSide = -1;
	}
	if(_sides.bottom != NULL) {
		_sides.bottom->apply();
		geNormal(bottomNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, 0);
		glEnd();
	}
	if(_sides.top != NULL) {
		_sides.top->apply();
		geNormal(topNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
			glVertex3f(0, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.back != NULL) {
		_sides.back->apply();
		geNormal(backNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, _dimensions.y, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(_dimensions.x, 0, 0);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.front != NULL) {
		_sides.front->apply();
		geNormal(frontNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
		glEnd();
	}
	if(_sides.left != NULL) {
		_sides.left->apply();
		geNormal(leftNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(0, _dimensions.y, -_dimensions.z);
			glVertex3f(0, 0, -_dimensions.z);
			glVertex3f(0, 0, 0);
			glVertex3f(0, _dimensions.y, 0);
		glEnd();
	}
	if(_sides.right != NULL) {
		_sides.right->apply();
		geNormal(rightNormal*normalSide);
		glBegin(GL_QUADS);
			glVertex3f(_dimensions.x, _dimensions.y, 0);
			glVertex3f(_dimensions.x, 0, 0);
			glVertex3f(_dimensions.x, 0, -_dimensions.z);
			glVertex3f(_dimensions.x, _dimensions.y, -_dimensions.z);
		glEnd();
	}
	if(_facingInside)
		geSwitchFrontFace();
}
