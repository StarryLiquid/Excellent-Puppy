#include "Leg.hpp"

#include "../SimpleEntity.hpp"
#include "Foot.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/shapes/CylinderModel.hpp"
#include "../../models/shapes/FootFrame.hpp"

using namespace ExcellentPuppy::Entities;

GLfloat const & Leg::getSocketJointAngle() const {
	return _socketJoint->getRotation().x;
}
GLfloat const & Leg::getFootJointAngle() const {
	return _kneeJoint->getRotation().x;
}
GLfloat const & Leg::getKneeJointAngle() const {
	return _footJoint->getRotation().x;
}

void Leg::setFootJointAngle(GLfloat const & footJointAngle) {
	_socketJoint->getRotation().x = footJointAngle;
}
void Leg::setKneeJointAngle(GLfloat const & kneeJointAngle) {
	_kneeJoint->getRotation().x = kneeJointAngle;
}
void Leg::setSocketJointAngle(GLfloat const & socketJointAngle) {
	_footJoint->getRotation().x = socketJointAngle;
}
		
Leg::Leg(Modeling::Material *dogMaterial,
		Modeling::Material *pawMaterial,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
					CompositeEntity({}, position, rotation, scaling) {
	auto legLinkSphere = Modeling::SphereModel::generate(360, 180, 10, 10);
	legLinkSphere->setMaterial(dogMaterial);
	auto legLinkCylinder = new Modeling::CylinderModel(LEG_RADIUS, LEG_LINK_LENGTH, 10, 10);
	legLinkCylinder->setMaterial(dogMaterial);
	getDependents()->insert(legLinkSphere);
	getDependents()->insert(legLinkCylinder);

	Entity *sphereEntity, *cylinderEntity;

	_socketJoint = new CompositeEntity({}, {}, {90});
	getEntities().push_back(_socketJoint);
	sphereEntity = new SimpleEntity(legLinkSphere, {}, {90}, {LEG_RADIUS, LEG_RADIUS ,LEG_RADIUS});
	cylinderEntity = new SimpleEntity(legLinkCylinder);
	_socketJoint->getEntities().push_back(sphereEntity);
	_socketJoint->getEntities().push_back(cylinderEntity);
	getDependents()->insert(_socketJoint);
	getDependents()->insert(sphereEntity);
	getDependents()->insert(cylinderEntity);

	_kneeJoint = new CompositeEntity({}, {0, 0, LEG_LINK_LENGTH});
	_socketJoint->getEntities().push_back(_kneeJoint);
	sphereEntity = new SimpleEntity(legLinkSphere, {}, {90}, {LEG_RADIUS, LEG_RADIUS ,LEG_RADIUS});
	cylinderEntity = new SimpleEntity(legLinkCylinder);
	_kneeJoint->getEntities().push_back(sphereEntity);
	_kneeJoint->getEntities().push_back(cylinderEntity);
	getDependents()->insert(_kneeJoint);
	getDependents()->insert(sphereEntity);
	getDependents()->insert(cylinderEntity);

	_footJoint = new CompositeEntity({}, {0, 0, LEG_LINK_LENGTH}, {-90}, {FOOT_SCALE, FOOT_SCALE, FOOT_SCALE});
	_kneeJoint->getEntities().push_back(_footJoint);
	auto foot = new Foot(dogMaterial, pawMaterial, {0, -Modeling::FootFrame::FEET_HEIGHT, 0.4});
	_footJoint->getEntities().push_back(foot);
	getDependents()->insert(_footJoint);
	getDependents()->insert(foot);
}
Leg::~Leg() { }
