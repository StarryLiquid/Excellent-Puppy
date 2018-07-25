#include "ScaleGeometry.hpp"

using namespace ExcellentPuppy::Modeling;
		
ScaleGeometry::ScaleGeometry(const Geometry* const & geometryToScale,
		GEvector const & scaleVector,
		bool const & reversedFrontFaces) :
	_geometryToScale(geometryToScale),
	_scaleVector(scaleVector),
	_reversedFrontFaces(reversedFrontFaces) { }
ScaleGeometry::~ScaleGeometry() { }

void ScaleGeometry::render() const {
	glPushMatrix();
	if(_reversedFrontFaces)
		geSwitchFrontFace();

	geScale(_scaleVector);
	_geometryToScale->render();

	if(_reversedFrontFaces)
		geSwitchFrontFace();
	glPopMatrix();
}
