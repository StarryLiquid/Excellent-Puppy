#include "Material.hpp"

using namespace ExcellentPuppy::Modeling;

Material::Material() { }
Material::~Material() { }

ColorMaterial::ColorMaterial(GEcolor color) :
	_color(color) {}
ColorMaterial::~ColorMaterial() { }

void ColorMaterial::apply() const {
	geColor(_color);
}

LightMaterial::LightMaterial(GEMaterial material) :
	_material(material) {}
LightMaterial::~LightMaterial() { }

void LightMaterial::apply() const {
	geMaterial(_material);
}
