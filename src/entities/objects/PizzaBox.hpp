#ifndef ENTITIES_PIZZABOX_HPP_
#define ENTITIES_PIZZABOX_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		class Texture;
	}
	namespace Entities {
		class Entity;

		/**
		 * Creates a pizza box entity with a given texture.
		 */
		Entity* createPizzaBox(ExcellentPuppy::Modeling::Texture *texture);
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_PIZZABOX_HPP_ */
