#include "ModelNV.hpp"

#include "Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

ModelNV::ModelNV(const GEnv* specs, const Geometry* geometry) :
	_specs(specs),
	_geometry(geometry) { }
ModelNV::~ModelNV() { }

void ModelNV::load() const {
}
void ModelNV::render() const {
	glInterleavedArrays(GE_NV_FORMAT, sizeof(GEnv), _specs);
	_geometry->render();
}
