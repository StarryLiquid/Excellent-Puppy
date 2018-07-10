#include "TriangleGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

TriangleGeometry::TriangleGeometry(const GEtriangle* faces, const GLsizei nFaces) :
		_faces(faces),
		_nVertices(nFaces * GE_TRI_COUNT) { }
TriangleGeometry::~TriangleGeometry() { }

void TriangleGeometry::render() const {
	glDrawElements(GL_TRIANGLES, _nVertices, GE_TRI_TYPE, _faces);
}
