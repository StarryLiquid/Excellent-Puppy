#include "FanGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

GEfan::GEfan(GLuint* const & perimeter, unsigned int const & indicesCount) :
	indices(perimeter), indicesCount(indicesCount) {}
GEfan::~GEfan() {
	delete(indices);
}

FanGeometry::FanGeometry(GEfan* const & fan) :
		_fan(fan) { }
FanGeometry::~FanGeometry() { }

void FanGeometry::render() const {
	glDrawElements(GL_TRIANGLE_FAN, _fan->indicesCount, GE_FAN_TYPE, _fan->indices);
}
