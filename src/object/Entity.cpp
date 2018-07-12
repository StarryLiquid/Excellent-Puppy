#include "Entity.hpp"

#include <GL/freeglut.h>

using namespace ExcellentPuppy::Objects;

Entity::Entity(GEvector position, GEvector rotation) :
	_position(position),
	_rotation(rotation) { }
Entity::~Entity() { }

inline void Entity::setPosition(GEvector position) {
	_position = position;
}
GEvector* Entity::getPosition() {
	return (GEvector*) &_position;
}
inline void Entity::setRotation(GEvector rotation) {
	_rotation = rotation;
}
GEvector* Entity::getRotation() {
	return (GEvector*)&_rotation;
}

void Entity::render(){
	glPushMatrix();
	GEvector *rotation = getRotation();
	geTranslate(_position);
	glRotatef(rotation->x, 1, 0, 0);
	glRotatef(rotation->y, 0, 1, 0);
	glRotatef(rotation->z, 0, 0, 1);
	subrender();
	glPopMatrix();
}
