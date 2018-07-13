#ifndef MODELS_TRIANGLEGEOMETRY_HPP_
#define MODELS_TRIANGLEGEOMETRY_HPP_

#include "Geometry.hpp"
#include <GL/freeglut.h>

#define GE_TRI_TYPE GL_UNSIGNED_INT
const unsigned int GE_TRI_COUNT = 3;

typedef struct {
	GLuint vert1;
	GLuint vert2;
	GLuint vert3;
} GEtriangle;

namespace ExcellentPuppy {
	namespace Modeling {
		class TriangleGeometry : public Geometry {
			private:
				GEtriangle const *_faces;
				const GLsizei _nVertices;

			public:
				TriangleGeometry(const GEtriangle *faces, const GLsizei nFaces);
				virtual ~TriangleGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_TRIANGLEGEOMETRY_HPP_ */
