#ifndef ENTITIES_OBJECTS_DOG_HPP_
#define ENTITIES_OBJECTS_DOG_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class Tail;
		class Paw;

		/**
		 * The entity of the dog, including the modelling and positioning
		 */
		class Dog : public CompositeEntity {
			private:
				Tail *_tail;

			public:
				Dog(std::list<Entity*> entities = {},
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Dog();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_DOG_HPP_ */
