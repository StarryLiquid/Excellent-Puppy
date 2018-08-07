#include "ModelCNV.hpp"

#include "geometries/Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GEcnv) == sizeof(GEcolor) + sizeof(GEvector)*2, "Struct GEcnv is padded ");

GEcnv const * ModelCNV::getSpecs() const {
	return _specs;
}
std::list<Geometry const *> const & ModelCNV::getGeometries() const {
	return _geometries;
}

ModelCNV::ModelCNV(const GEcnv* specs, std::list<Geometry const *> geometries) :
	_specs(specs),
	_geometries(geometries) { }
ModelCNV::~ModelCNV() { }

void ModelCNV::load() const {
}
void ModelCNV::draw() const {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
	for(auto geometry : _geometries)
		geometry->render();
}
