#include "Dog.hpp"

#include "Tail.hpp"
#include "Leg.hpp"
#include "Head.hpp"
#include "../SimpleEntity.hpp"
#include "../../models/shapes/CylinderModel.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat& Dog::getTailAngleX() const {
	return _tailAngleX;
}
void Dog::setTailAngleX(GLfloat angle) {
	if(angle > 45)
		angle = 45;
	else if(angle < -45)
		angle = -45;

	for(auto entity : _tail->getEntities()) {
		entity->getRotation().x += angle - _tailAngleX;
	}

	_tailAngleX = angle;
}
const GLfloat& Dog::getTailAngleY() const {
	return _tailAngleY;
}
void Dog::setTailAngleY(GLfloat angle) {
	if(angle > 45)
		angle = 45;
	else if(angle < -45)
		angle = -45;

	for(auto entity : _tail->getEntities()) {
		entity->getRotation().y += angle - _tailAngleY;
	}

	_tailAngleY = angle;
}

Dog::Dog(const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity({}, position, rotation, scaling),
			_tailAngleX(0),
			_tailAngleY(0) {
	// Initialize the materials
	// 228, 180, 134
	// Material to use for most of the dog body
	ExcellentPuppy::Modeling::ColorMaterial* dogMaterial = new ExcellentPuppy::Modeling::ColorMaterial({228.0/256, 180.0/256, 134.0/256});
	// Material to use for the paw pads
	ExcellentPuppy::Modeling::ColorMaterial* pawMaterial = new ExcellentPuppy::Modeling::ColorMaterial({0.1, 0.1, 0.1});

	// Build the body of the dog
	// A cylinder, the center of the dog's body
	ExcellentPuppy::Modeling::Model* bodyCenter = new ExcellentPuppy::Modeling::CylinderModel(BODY_RADIUS, BODY_HALF_WIDTH*2, 10, 10);
	bodyCenter->setMaterial(dogMaterial);
	getEntities().push_back(new SimpleEntity(bodyCenter, {0, BODY_HEIGHT, -BODY_HALF_WIDTH}));
	// Half spheres to cap off the two ends of the cylinder
	ExcellentPuppy::Modeling::Model* bodySphere = ExcellentPuppy::Modeling::SphereModel::generate(360, 90, 10, 10);
	bodySphere->setMaterial(dogMaterial);
	getEntities().push_back(new SimpleEntity(bodySphere, {0, BODY_HEIGHT, BODY_HALF_WIDTH}, {-90}, {BODY_RADIUS, BODY_RADIUS, BODY_RADIUS}));
	getEntities().push_back(new SimpleEntity(bodySphere, {0, BODY_HEIGHT, -BODY_HALF_WIDTH}, {90}, {BODY_RADIUS, BODY_RADIUS, BODY_RADIUS}));

	// Add tail
	_tail = new Tail(dogMaterial, {0, BODY_HEIGHT, BODY_HALF_WIDTH+BODY_RADIUS});
	getEntities().push_back(_tail);

	// Add legs
	_frontLeftLeg = new Leg(dogMaterial, pawMaterial, {-BODY_RADIUS*3/4, BODY_HEIGHT, -BODY_HALF_WIDTH});
	getEntities().push_back(_frontLeftLeg);
	_frontRightLeg = new Leg(dogMaterial, pawMaterial, {BODY_RADIUS*3/4, BODY_HEIGHT, -BODY_HALF_WIDTH});
	getEntities().push_back(_frontRightLeg);
	_backLeftLeg = new Leg(dogMaterial, pawMaterial, {-BODY_RADIUS*3/4, BODY_HEIGHT, BODY_HALF_WIDTH});
	getEntities().push_back(_backLeftLeg);
	_backRightLeg = new Leg(dogMaterial, pawMaterial, {BODY_RADIUS*3/4, BODY_HEIGHT, BODY_HALF_WIDTH});
	getEntities().push_back(_backRightLeg);

	// Add the head
	_head = new Head(dogMaterial, pawMaterial, pawMaterial, pawMaterial, {0, BODY_HEIGHT+0.4, -BODY_HALF_WIDTH-0.4});
	getEntities().push_back(_head);

	// Set the collision radius based on head + body length
	setCollisionRadius(BODY_HALF_WIDTH + 1.2);
}
Dog::~Dog() {
	delete(_tail);
	delete(_frontLeftLeg);
	delete(_frontRightLeg);
	delete(_backLeftLeg);
	delete(_backRightLeg);

	// Delete body center
}
