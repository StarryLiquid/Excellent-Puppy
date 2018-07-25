#ifndef MODELS_GEOMETRIES_SCALEGEOMETRY_HPP_
#define MODELS_GEOMETRIES_SCALEGEOMETRY_HPP_

#include "Geometry.hpp"

#include "../../types.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Scales a geometry over a scale vector.
		 * Can be used to mirror a geometry over an axis.
		 */
		class ScaleGeometry: public Geometry {
			private:
				// The geometry to scale
				const Geometry* _geometryToScale;
				// The vector to scale by
				GEvector _scaleVector;
				// Whether the faces should be reversed from the original geometry
				bool _reversedFrontFaces;

			public:
				ScaleGeometry(const Geometry* const & geometryToScale,
						GEvector const & scaleVector,
						bool const & reversedFrontFaces = false);
				virtual ~ScaleGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_SCALEGEOMETRY_HPP_ */
