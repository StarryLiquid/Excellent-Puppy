#include "ModelTNV.hpp"

#include "Texture.hpp"
#include "geometries/Geometry.hpp"

using namespace ExcellentPuppy::Modeling;

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GEtnv) == sizeof(GEtexCoords) + sizeof(GEvector)*2, "Struct GEtnv is padded ");

ModelTNV::ModelTNV(Texture* tex, const GEtnv* specs, const std::list<Geometry*> geometries) :
		_tex(tex),
		_specs(specs),
		_geometries(geometries) { }
ModelTNV::~ModelTNV() { }

void ModelTNV::load() const {
	_tex->loadTexture();
}
void ModelTNV::draw() const {
	// select texture
	_tex->selectTexture();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glInterleavedArrays(GE_TNV_FORMAT, sizeof(GEtnv), _specs);
	for(Geometry* geometry : _geometries)
		geometry->render();
	glDisable(GL_TEXTURE_2D);
}
