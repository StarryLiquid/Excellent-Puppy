#include "TranslateGeometry.hpp"

using namespace ExcellentPuppy::Modeling;
		
TranslateGeometry::TranslateGeometry(const Geometry* const & geometryToTranslate,
		GEvector const & translateVector) :
			_geometryToTranslate(geometryToTranslate),
			_translateVector(translateVector) { }
TranslateGeometry::~TranslateGeometry() { }

void TranslateGeometry::render() const {
	geSwitchFrontFace();

	geTranslate(_translateVector);
	_geometryToTranslate->render();
	geTranslate(-_translateVector);

	geSwitchFrontFace();
}
