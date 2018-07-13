#ifndef MODELS_QUADGEOMETRY_HPP_
#define MODELS_QUADGEOMETRY_HPP_

#include "Geometry.hpp"
#include <GL/freeglut.h>

#define GE_QUAD_TYPE GL_UNSIGNED_INT
const unsigned int GE_QUAD_COUNT = 4;

typedef struct {
	GLuint vert1;
	GLuint vert2;
	GLuint vert3;
	GLuint vert4;
} GEquad;

namespace ExcellentPuppy {
	namespace Modeling {
		class QuadGeometry: public Geometry {
			private:
				GEquad const *_faces;
				const GLsizei _nVertices;

			public:
				QuadGeometry(const GEquad *faces, const GLsizei nFaces);
				virtual ~QuadGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_QUADGEOMETRY_HPP_ */
