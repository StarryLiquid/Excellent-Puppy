#include "ModelTNV.hpp"

#include "Texture.hpp"
#include "geometries/Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GEtnv) == sizeof(GEtexCoords) + sizeof(GEvector)*2, "Struct GEtnv is padded ");

Texture const * ModelTNV::getTexture() const {
	return _texture;
}
GEtnv const * ModelTNV::getSpecs() const {
	return _specs;
}
std::list<Geometry const *> const & ModelTNV::getGeometries() const {
	return _geometries;
}

ModelTNV::ModelTNV(Texture const * const tex, GEtnv const * const specs, std::list<Geometry const *> const geometries) :
		_texture(tex),
		_specs(specs),
		_geometries(geometries) { }
ModelTNV::~ModelTNV() { }

void ModelTNV::load() const {
	_texture->loadTexture();
}
void ModelTNV::draw() const {
	// select texture
	_texture->selectTexture();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glInterleavedArrays(GE_TNV_FORMAT, sizeof(GEtnv), _specs);
	for(auto geometry : _geometries)
		geometry->render();
	glDisable(GL_TEXTURE_2D);
}
