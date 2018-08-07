#include "QuadGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

QuadGeometry::QuadGeometry(GEquad const * const faces, GLsizei const nFaces) :
	_faces(faces),
	_nVertices(nFaces * GE_QUAD_COUNT) { }
QuadGeometry::~QuadGeometry() { }

void QuadGeometry::render() const {
	glDrawElements(GL_QUADS, _nVertices, GE_QUAD_TYPE, _faces);
}
