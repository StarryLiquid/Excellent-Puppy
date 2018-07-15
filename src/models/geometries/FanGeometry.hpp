#ifndef MODELS_GEOMETRIES_FANGEOMETRY_HPP_
#define MODELS_GEOMETRIES_FANGEOMETRY_HPP_

#include "Geometry.hpp"
#include "../../types.hpp"

// The datatype of each vertex index
#define GE_FAN_TYPE GL_UNSIGNED_INT

// A struct holding a single face in the geometry
struct GEfan {
	GLuint* indices; // Indices of the fan, starting from the base vertex index
	unsigned int indicesCount; // Number of vertices in perimeter

	GEfan(GLuint* const & indices, unsigned int const & indicesCount);
	virtual ~GEfan();
};

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model geometry made of a fan of triangles
		 */
		class FanGeometry: public Geometry {
			private:
				// The indices of the fan
				const GEfan *_fan;

			public:
				FanGeometry(GEfan* const& fan);
				virtual ~FanGeometry();

				virtual void render() const;

		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_FANGEOMETRY_HPP_ */
