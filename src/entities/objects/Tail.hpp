#ifndef ENTITIES_OBJECTS_TAIL_HPP_
#define ENTITIES_OBJECTS_TAIL_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		/**
		 * The dog's tail.
		 * Made of links that can be rotated individually so the tail will wag.
		 */
		class Tail: public CompositeEntity {
			public:
				Tail(ExcellentPuppy::Modeling::Material *material,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Tail();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_TAIL_HPP_ */
