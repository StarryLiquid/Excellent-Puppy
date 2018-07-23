#include "ConeModel.hpp"

using namespace ExcellentPuppy::Modeling;

double& ConeModel::getBase() {
	return _base;
}
double& ConeModel::getHeight() {
	return _height;
}
GLint& ConeModel::getSlices() {
	return _slices;
}
GLint& ConeModel::getStacks() {
	return _stacks;
}
		
ConeModel::ConeModel(const double& base,
		const double& height,
		const GLint& slices,
		const GLint& stacks) :
				Model(),
				_base(base),
				_height(height),
				_slices(slices),
				_stacks(stacks) { }
ConeModel::~ConeModel() { }

void ConeModel::load() const { }
void ConeModel::draw() const {
	glutSolidCone(_base, _height, _slices, _stacks);
}
