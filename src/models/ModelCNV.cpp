#include "ModelCNV.hpp"

#include "geometries/Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

ModelCNV::ModelCNV(const GEcnv* specs, const std::list<Geometry*> geometries) :
	_specs(specs),
	_geometries(geometries) { }
ModelCNV::~ModelCNV() { }

void ModelCNV::load() const {
}
void ModelCNV::draw() const {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
	for(Geometry* geometry : _geometries)
		geometry->render();
}
