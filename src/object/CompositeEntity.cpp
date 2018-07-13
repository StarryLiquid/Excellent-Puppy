#include "CompositeEntity.hpp"

using namespace ExcellentPuppy::Entities;

CompositeEntity::CompositeEntity(const GEvector& position, const GEvector& rotation, std::list<Entity*> entities) :
	Entity(position, rotation),
	_entities(entities) { }
CompositeEntity::~CompositeEntity() {
	while(!_entities.empty()){
		Entity *first = *(_entities.begin());
		delete(first);
		_entities.pop_front();
	}
}

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
