#include "../entities/Entity.hpp"

using namespace ExcellentPuppy::Entities;

Entity::Entity(const GEvector& position, const GEvector& rotation, const GEvector& scaling) :
	_position(position),
	_rotation(rotation),
	_scaling(scaling) { }
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
inline void Entity::setScaling(GEvector scaling) {
	_scaling = scaling;
}
GEvector& Entity::getScaling() {
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
	geScale(_scaling);
	// Render the entity
	subrender();
	// Restore the starting matrix
	glPopMatrix();
}
