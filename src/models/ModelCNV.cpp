#include "ModelCNV.hpp"

#include "geometries/Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

ModelCNV::ModelCNV(const GEcnv* specs, const Geometry* geometry) :
	_specs(specs),
	_geometry(geometry) { }
ModelCNV::~ModelCNV() { }

void ModelCNV::load() const {
}
void ModelCNV::draw() const {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
	_geometry->render();
}
