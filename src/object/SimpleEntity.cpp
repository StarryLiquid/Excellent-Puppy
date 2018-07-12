#include "SimpleEntity.hpp"

#include "../models/Model.hpp"

using namespace ExcellentPuppy::Objects;

SimpleEntity::SimpleEntity(GEvector position, GEvector rotation, ExcellentPuppy::Modeling::Model const *model) :
	Entity(position, rotation),
	_model(model) { }
SimpleEntity::~SimpleEntity() { }

void SimpleEntity::subrender(){
	_model->render();
}
