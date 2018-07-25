#ifndef MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_
#define MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_

#include "Geometry.hpp"

#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		class CompositeGeometry: public Geometry {
			private:
				const std::list<const Geometry*> _geometries;

			public:
				CompositeGeometry(std::list<const Geometry*> const & geometries);
				virtual ~CompositeGeometry();

				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_GEOMETRIES_COMPOSITEGEOMETRY_HPP_ */
