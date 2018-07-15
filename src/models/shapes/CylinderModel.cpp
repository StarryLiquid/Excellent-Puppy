#include "CylinderModel.hpp"

using namespace ExcellentPuppy::Modeling;

double& CylinderModel::getRadius() {
	return _radius;
}
double& CylinderModel::getHeight() {
	return _height;
}
GLint& CylinderModel::getSlices() {
	return _slices;
}
GLint& CylinderModel::getStacks() {
	return _stacks;
}

CylinderModel::CylinderModel(
		const double& radius,
		const double& height,
		const GLint& slices,
		const GLint& stacks) :
	_radius(radius),
	_height(height),
	_slices(slices),
	_stacks(stacks) { }
CylinderModel::~CylinderModel() {}

void CylinderModel::load() const { }
void CylinderModel::draw() const {
	glutSolidCylinder(_radius, _height, _slices, _stacks);
}
