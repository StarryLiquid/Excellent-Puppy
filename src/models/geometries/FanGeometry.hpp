#ifndef MODELS_GEOMETRIES_FANGEOMETRY_HPP_
#define MODELS_GEOMETRIES_FANGEOMETRY_HPP_

#include "Geometry.hpp"
#include "../../types.hpp"

// The datatype of each vertex index
#define GE_FAN_TYPE GL_UNSIGNED_INT

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model geometry made of a fan of triangles
		 */
		class FanGeometry: public Geometry {
			private:
				// Indices of the fan, starting from the base vertex index
				GLuint const * _indices;
				// Number of vertices in perimeter
				GLsizei const _indicesCount;

			public:
				FanGeometry(GLuint const * indices, GLsizei const & indicesCount);
				virtual ~FanGeometry();

				virtual void render() const;

		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_FANGEOMETRY_HPP_ */
