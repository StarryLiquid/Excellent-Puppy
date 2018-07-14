#include "../entities/Entity.hpp"

using namespace ExcellentPuppy::Entities;

Entity::Entity(GEvector position, GEvector rotation) :
	_position(position),
	_rotation(rotation) { }
Entity::~Entity() { }

inline void Entity::setPosition(GEvector position) {
	_position = position;
}
GEvector& Entity::getPosition() {
	return _position;
}
inline void Entity::setRotation(GEvector rotation) {
	_rotation = rotation;
}
GEvector& Entity::getRotation() {
	return _rotation;
}

void Entity::render(){
	// Push the current matrix
	glPushMatrix();
	GEvector& rotation = getRotation();
	// Translate and rotate
	geTranslate(_position);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);
	// Render the entity
	subrender();
	// Restore the starting matrix
	glPopMatrix();
}
