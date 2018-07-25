#include "Dog.hpp"

#include "Tail.hpp"
#include "../SimpleEntity.hpp"
#include "../../models/shapes/CylinderModel.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Entities;

// Half the width of the body
const GLfloat BODY_HALF_WIDTH = 0.75;
// Radius of the body
const GLfloat BODY_RADIUS = 0.4;
// Height of the body, correcting for body radius
const GLfloat BODY_HEIGHT = 0.8 + BODY_RADIUS;

Dog::Dog(std::list<Entity*> entities ,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity(entities, position, rotation, scaling) {
	// 228, 180, 134
	// Material to use for most of the dog body
	ExcellentPuppy::Modeling::ColorMaterial* dogMaterial = new ExcellentPuppy::Modeling::ColorMaterial({228.0/256, 180.0/256, 134.0/256});
	// A cylinder, the center of the dog's body
	ExcellentPuppy::Modeling::Model* bodyCenter = new ExcellentPuppy::Modeling::CylinderModel(BODY_RADIUS, BODY_HALF_WIDTH*2, 10, 10);
	bodyCenter->setMaterial(dogMaterial);
	getEntities().push_back(new SimpleEntity(bodyCenter, {0, BODY_HEIGHT, -BODY_HALF_WIDTH}));
	// Half spheres to cap off the two ends of the cylinder
	ExcellentPuppy::Modeling::Model* bodySphere = ExcellentPuppy::Modeling::SphereModel::generate(360, 90, 10, 10);
	bodyCenter->setMaterial(dogMaterial);
	getEntities().push_back(new SimpleEntity(bodySphere, {0, BODY_HEIGHT, BODY_HALF_WIDTH}, {-90}, {BODY_RADIUS, BODY_RADIUS, BODY_RADIUS}));
	getEntities().push_back(new SimpleEntity(bodySphere, {0, BODY_HEIGHT, -BODY_HALF_WIDTH}, {90}, {BODY_RADIUS, BODY_RADIUS, BODY_RADIUS}));
	_tail = new Tail(dogMaterial, {0, BODY_HEIGHT, BODY_HALF_WIDTH+BODY_RADIUS});
	getEntities().push_back(_tail);
}
Dog::~Dog() { }
