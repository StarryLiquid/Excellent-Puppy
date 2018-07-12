#include "CompositeEntity.hpp"

using namespace ExcellentPuppy::Entities;

CompositeEntity::CompositeEntity(GEvector position, GEvector rotation, std::list<Entity*> entities) :
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
