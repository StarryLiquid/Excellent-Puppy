#include "QuadGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

QuadGeometry::QuadGeometry(const GEquad *faces, const GLsizei nFaces) :
	_faces(faces),
	_nVertices(nFaces * GE_QUAD_COUNT) { }
QuadGeometry::~QuadGeometry() { }

void QuadGeometry::render() const {
	glDrawElements(GL_QUADS, _nVertices, GE_QUAD_TYPE, _faces);
}
