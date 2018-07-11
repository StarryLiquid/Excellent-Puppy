#include "Entity.hpp"

#include <GL/freeglut.h>

using namespace ExcellentPuppy::Objects;

Entity::Entity(GEvertex3D position, GEvec3D rotation) :
	_position(position),
	_rotation(rotation) { }
Entity::~Entity() { }

inline void Entity::setPosition(GEvertex3D position) {
	_position = position;
}
GEvertex3D* Entity::getPosition() {
	return (GEvertex3D*) &_position;
}
inline void Entity::setRotation(GEvec3D rotation) {
	_rotation = rotation;
}
GEvec3D* Entity::getRotation() {
	return (GEvec3D*)&_rotation;
}

void Entity::render(){
	glPushMatrix();
	GEvertex3D *position = getPosition();
	GEvec3D *rotation = getRotation();
	glTranslatef(position->x, position->y, position->z);
	glRotatef(rotation->x, 1, 0, 0);
	glRotatef(rotation->y, 0, 1, 0);
	glRotatef(rotation->z, 0, 0, 1);
	subrender();
	glPopMatrix();
}
