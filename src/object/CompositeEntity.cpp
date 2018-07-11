#include "CompositeEntity.hpp"

namespace ExcellentPuppy {
namespace Objects {

CompositeEntity::CompositeEntity(GEvertex3D position, GEvec3D rotation) :
	Entity(position, rotation) { }
CompositeEntity::CompositeEntity(GEvertex3D position, GEvec3D rotation, std::list<Entity*> entities) :
	Entity(position, rotation),
	_entities(entities) { }
CompositeEntity::~CompositeEntity() { }

std::list<Entity*>& CompositeEntity::getEntities() {
	return _entities;
}
void CompositeEntity::setEntities(const std::list<Entity*>& entities) {
	_entities = entities;
}

void CompositeEntity::subrender() {
	for(Entity *entity : _entities) {
		entity->render();
	}
}

} /* namespace Objects */
} /* namespace ExcellentPuppy */
