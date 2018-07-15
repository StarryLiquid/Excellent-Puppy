#include "ModelNV.hpp"

#include <GL/freeglut.h>
#include "geometries/Geometry.hpp"

void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);

using namespace ExcellentPuppy::Modeling;

ModelNV::ModelNV(const GEnv* specs, std::list<Geometry*> const & geometries) :
	_specs(specs),
	_geometries(geometries) { }
ModelNV::~ModelNV() { }

void ModelNV::load() const {
}
void ModelNV::draw() const {
	glInterleavedArrays(GE_NV_FORMAT, sizeof(GEnv), _specs);
	for(Geometry* geometry : _geometries)
		geometry->render();
}
