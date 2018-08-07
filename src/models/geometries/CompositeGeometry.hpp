#ifndef MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_
#define MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_

#include "Geometry.hpp"

#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		class CompositeGeometry: public Geometry {
			private:
				std::list<Geometry const *> const _geometries;

			public:
				CompositeGeometry(std::list<Geometry const *> const geometries);
				virtual ~CompositeGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_ */
