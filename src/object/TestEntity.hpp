#ifndef OBJECT_TESTENTITY_HPP_
#define OBJECT_TESTENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class CompositeEntity;
		class TestEntity {
			public:
				static CompositeEntity* testEntity(
					const GEvector& position = {},
					const GEvector& rotation = {});
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_TESTENTITY_HPP_ */
