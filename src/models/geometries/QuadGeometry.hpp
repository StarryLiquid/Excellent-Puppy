#ifndef MODELS_QUADGEOMETRY_HPP_
#define MODELS_QUADGEOMETRY_HPP_

#include "Geometry.hpp"
#include <GL/freeglut.h>

// The datatype of each vertex index
#define GE_QUAD_TYPE GL_UNSIGNED_INT
// Number of vertices in each face
const unsigned int GE_QUAD_COUNT = 4;

// A struct holding a single face in the geometry
struct GEquad {
	GLuint vert1;
	GLuint vert2;
	GLuint vert3;
	GLuint vert4;
};

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model geometry made of quadrilaterals
		 */
		class QuadGeometry: public Geometry {
			private:
				// The faces of the geometry
				GEquad const * const _faces;
				// The number of vertex indices in the geometry
				GLsizei const _nVertices;

			public:
				QuadGeometry(GEquad const * const faces, GLsizei const nFaces);
				virtual ~QuadGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_QUADGEOMETRY_HPP_ */
