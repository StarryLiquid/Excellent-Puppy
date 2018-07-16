#include "LightEntity.hpp"

#include "../engine/Light.hpp"

using namespace ExcellentPuppy::Entities;

LightEntity::LightEntity(
		Engine::Light* const & light,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
				Entity(position, rotation, scaling),
				_light(light) { }
LightEntity::~LightEntity() { }


void LightEntity::load() {
	_light->load();
}
void LightEntity::subrender() {
	_light->setLight();
}
