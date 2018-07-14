#include "LightMaterial.hpp"

using namespace ExcellentPuppy::Modeling;

LightMaterial::LightMaterial(GEMaterial material) :
	_material(material) {}
LightMaterial::~LightMaterial() { }

void LightMaterial::apply() const {
	geMaterial(_material);
}
