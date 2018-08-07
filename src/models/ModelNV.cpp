#include "ModelNV.hpp"

#include <GL/freeglut.h>
#include "geometries/Geometry.hpp"

void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);

using namespace ExcellentPuppy::Modeling;

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GEnv) == sizeof(GEvector)*2, "Struct GEnv is padded ");

GEnv const * ModelNV::getSpecs() const {
	return _specs;
}
std::list<Geometry const *> const & ModelNV::getGeometries() const {
	return _geometries;
}

ModelNV::ModelNV(const GEnv* specs, std::list<Geometry const *> geometries) :
	_specs(specs),
	_geometries(geometries) { }
ModelNV::~ModelNV() { }

void ModelNV::load() const {
}
void ModelNV::draw() const {
	glInterleavedArrays(GE_NV_FORMAT, sizeof(GEnv), _specs);
	for(auto geometry : _geometries)
		geometry->render();
}
