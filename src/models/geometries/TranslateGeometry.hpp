#ifndef MODELS_GEOMETRIES_TRANSLATEGEOMETRY_HPP_
#define MODELS_GEOMETRIES_TRANSLATEGEOMETRY_HPP_

#include "Geometry.hpp"

#include "../../types.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Translate the geometry over a vector.
		 */
		class TranslateGeometry : public Geometry {
			private:
				// The geometry to translate
				Geometry const * const _geometryToTranslate;
				// The vector to translate by
				GEvector const _translateVector;

			public:
				TranslateGeometry(Geometry const * const geometryToTranslate,
						GEvector const & translateVector);
				virtual ~TranslateGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_TRANSLATEGEOMETRY_HPP_ */
