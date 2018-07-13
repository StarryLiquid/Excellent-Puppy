#ifndef OBJECT_COMPOSITEENTITY_HPP_
#define OBJECT_COMPOSITEENTITY_HPP_

#include "Entity.hpp"

#include <list>

struct GEvector;

namespace ExcellentPuppy {
	namespace Entities {
		/**
		 * An entity composed of several other entities
		 */
		class CompositeEntity: public Entity {
			private:
				// The sub entities of this entity
				std::list<Entity*> _entities;

			public:
				CompositeEntity(
						const GEvector& position = {},
						const GEvector& rotation = {},
						std::list<Entity*> entities = {});
				virtual ~CompositeEntity();

				std::list<Entity*>& getEntities();
				void setEntities(const std::list<Entity*>& entities);

				virtual void subrender();
		};
	} /* namespace Objects */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_COMPOSITEENTITY_HPP_ */
