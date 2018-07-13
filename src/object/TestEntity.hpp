#ifndef OBJECT_TESTENTITY_HPP_
#define OBJECT_TESTENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class CompositeEntity;
		/**
		 * A test entity.
		 * A colorful cube on a colorful plane.
		 * Origin of the model is at the bottom of the cube slightly over the center of the plane.
		 */
		class TestEntity {
			public:
				// Returns a test entity
				static CompositeEntity* testEntity(
					const GEvector& position = {},
					const GEvector& rotation = {});
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_TESTENTITY_HPP_ */
