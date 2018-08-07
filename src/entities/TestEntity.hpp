#ifndef ENTITIES_TESTENTITY_HPP_
#define ENTITIES_TESTENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class CompositeEntity;
		/**
		 * A test entity.
		 * A colorful cube on a colorful plane.
		 * Origin of the model is at the bottom of the cube slightly over the center of the plane.
		 * TODO remove when not needed anymore
		 */
		class TestEntity {
			public:
				// Returns a test entity
				static CompositeEntity* testEntity(
					const GEvector& position = {},
					const GEvector& rotation = {},
					const GEvector& scaling = {1, 1, 1});
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_TESTENTITY_HPP_ */
