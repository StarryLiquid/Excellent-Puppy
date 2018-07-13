#include "SimpleEntity.hpp"

#include "../models/Model.hpp"

using namespace ExcellentPuppy::Entities;

SimpleEntity::SimpleEntity(ExcellentPuppy::Modeling::Model const *model,
                           const GEvector& position,
                           const GEvector& rotation) :
	Entity(position, rotation),
	_model(model) { }
SimpleEntity::~SimpleEntity() { }

void SimpleEntity::subrender(){
	_model->render();
}
