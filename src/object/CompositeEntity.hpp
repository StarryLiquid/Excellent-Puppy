#ifndef OBJECT_COMPOSITEENTITY_HPP_
#define OBJECT_COMPOSITEENTITY_HPP_

#include "Entity.hpp"

#include <list>

namespace ExcellentPuppy {
namespace Objects {

	class CompositeEntity: public Entity {
		private:
			std::list<Entity*> _entities;

		public:
			CompositeEntity(GEvertex3D position, GEvec3D rotation);
			CompositeEntity(GEvertex3D position, GEvec3D rotation, std::list<Entity*> entities);
			virtual ~CompositeEntity();

			std::list<Entity*>& getEntities();
			void setEntities(const std::list<Entity*>& entities);

			virtual void subrender();
};

} /* namespace Objects */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_COMPOSITEENTITY_HPP_ */
