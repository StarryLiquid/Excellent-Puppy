#include "ModelNV.hpp"

#include <GL/freeglut.h>
#include "geometries/Geometry.hpp"

void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);

using namespace ExcellentPuppy::Modeling;

ModelNV::ModelNV(const GEnv* specs, const Geometry* geometry) :
	_specs(specs),
	_geometry(geometry) { }
ModelNV::~ModelNV() { }

void ModelNV::load() const {
}
void ModelNV::draw() const {
	glInterleavedArrays(GE_NV_FORMAT, sizeof(GEnv), _specs);
	_geometry->render();
}
