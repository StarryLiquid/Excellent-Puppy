#include "../entities/CompositeEntity.hpp"

using namespace ExcellentPuppy::Entities;

CompositeEntity::CompositeEntity(std::list<Entity*> entities, const GEvector& position, const GEvector& rotation, const GEvector& scaling) :
	Entity(position, rotation, scaling),
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

void CompositeEntity::load() {
	// Iterate over the entities and load each
	for(Entity *entity : _entities) {
		entity->load();
	}
}
void CompositeEntity::subrender() {
	// Iterate over the entities and render each
	for(Entity *entity : _entities) {
		entity->render();
	}
}
