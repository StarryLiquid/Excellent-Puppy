#include "ModelCNV.hpp"

#include "Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

ModelCNV::ModelCNV(const GEcnv* specs, const Geometry* geo) :
	_specs(specs),
	_geo(geo){ }
ModelCNV::~ModelCNV() { }

void ModelCNV::load() const {
}
void ModelCNV::render() const {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
	_geo->render();
}
