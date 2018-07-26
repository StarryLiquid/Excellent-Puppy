#ifndef ENTITIES_COMPOSITEENTITY_HPP_
#define ENTITIES_COMPOSITEENTITY_HPP_

#include <list>
#include "../entities/Entity.hpp"

struct GEvector;

namespace ExcellentPuppy {
	namespace Entities {
		/**
		 * An entity composed of several other entities
		 */
		class CompositeEntity : public Entity {
			private:
				// The sub entities of this entity
				std::list<Entity*> _entities;

			public:
				CompositeEntity(
						std::list<Entity*> entities = {},
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~CompositeEntity();

				std::list<Entity*>& getEntities();
				void setEntities(const std::list<Entity*>& entities);

				virtual void load();
				virtual void subrender();
		};
	} /* namespace Objects */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_COMPOSITEENTITY_HPP_ */
