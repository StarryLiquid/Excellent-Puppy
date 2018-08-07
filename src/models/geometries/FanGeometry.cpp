#include "FanGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

FanGeometry::FanGeometry(GLuint const * indices, GLsizei const & indicesCount) :
		_indices(indices),
		_indicesCount(indicesCount) { }
FanGeometry::~FanGeometry() { }

void FanGeometry::render() const {
	glDrawElements(GL_TRIANGLE_FAN, _indicesCount, GE_FAN_TYPE, _indices);
}
