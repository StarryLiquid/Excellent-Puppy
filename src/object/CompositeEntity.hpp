#ifndef OBJECT_COMPOSITEENTITY_HPP_
#define OBJECT_COMPOSITEENTITY_HPP_

#include "Entity.hpp"

#include <list>

namespace ExcellentPuppy {
namespace Entities {
	class CompositeEntity: public Entity {
		private:
			std::list<Entity*> _entities;

		public:
			CompositeEntity(
					GEvector position = {0, 0, 0},
					GEvector rotation = {0, 0, 0},
					std::list<Entity*> entities = {});
			virtual ~CompositeEntity();

			std::list<Entity*>& getEntities();
			void setEntities(const std::list<Entity*>& entities);

			virtual void subrender();
	};
} /* namespace Objects */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_COMPOSITEENTITY_HPP_ */
