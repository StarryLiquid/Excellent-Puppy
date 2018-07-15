#include "../entities/SimpleEntity.hpp"

#include "../models/Model.hpp"

using namespace ExcellentPuppy::Entities;

SimpleEntity::SimpleEntity(ExcellentPuppy::Modeling::Model const *model,
                           const GEvector& position,
                           const GEvector& rotation,
                           const GEvector& scaling) :
	Entity(position, rotation, scaling),
	_model(model) { }
SimpleEntity::~SimpleEntity() { }

void SimpleEntity::load() {
	_model->load();
}
void SimpleEntity::subrender(){
	_model->render();
}
