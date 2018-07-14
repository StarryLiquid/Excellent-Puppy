#ifndef MODELS_TRIANGLEGEOMETRY_HPP_
#define MODELS_TRIANGLEGEOMETRY_HPP_

#include "Geometry.hpp"
#include <GL/freeglut.h>

// The datatype of each vertex index
#define GE_TRI_TYPE GL_UNSIGNED_INT
// Number of vertices in each face
const unsigned int GE_TRI_COUNT = 3;

// A struct holding a single face in the geometry
struct GEtriangle {
	GLuint vert1;
	GLuint vert2;
	GLuint vert3;
};

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model geometry made of triangles
		 */
		class TriangleGeometry : public Geometry {
			private:
				// The faces of the geometry
				GEtriangle const *_faces;
				// The number of vertex indices in the geometry
				const GLsizei _nVertices;

			public:
				TriangleGeometry(const GEtriangle *faces, const GLsizei nFaces);
				virtual ~TriangleGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_TRIANGLEGEOMETRY_HPP_ */
