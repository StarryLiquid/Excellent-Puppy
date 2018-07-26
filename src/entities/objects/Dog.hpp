#ifndef ENTITIES_OBJECTS_DOG_HPP_
#define ENTITIES_OBJECTS_DOG_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		class Tail;
		class Leg;
		class Head;

		/**
		 * The entity of the dog, including the modelling and positioning
		 */
		class Dog : public CompositeEntity {
			public:
				// Half the width of the body
				static constexpr GLfloat BODY_HALF_WIDTH = 0.5;
				// Radius of the body
				static constexpr GLfloat BODY_RADIUS = 0.3;
				// Height of the body, correcting for body radius
				static constexpr GLfloat BODY_HEIGHT = 0.8 + BODY_RADIUS;

			private:
				Tail *_tail;
				Leg *_frontLeftLeg;
				Leg *_frontRightLeg;
				Leg *_backLeftLeg;
				Leg *_backRightLeg;
				Head *_head;

			public:
				Dog(const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Dog();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_DOG_HPP_ */
