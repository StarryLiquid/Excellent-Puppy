#include "ModelCNV.hpp"

#include "Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

ModelCNV::ModelCNV(const GEcnv* specs, const Geometry* geometry) :
	_specs(specs),
	_geometry(geometry) { }
ModelCNV::~ModelCNV() { }

void ModelCNV::load() const {
}
void ModelCNV::render() const {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
	_geometry->render();
}
