#include "ColorMaterial.hpp"

using namespace ExcellentPuppy::Modeling;

ColorMaterial::ColorMaterial(GEcolor color) :
	_color(color) {}
ColorMaterial::~ColorMaterial() { }

void ColorMaterial::apply() const {
	geColor(_color);
}
