#include "Tail.hpp"

#include "../SimpleEntity.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/shapes/CylinderModel.hpp"
//#include "../../models/shapes/ConeModel.hpp"

using namespace ExcellentPuppy::Entities;


GLfloat const & Tail::getBaseJointAngle() const {
	return _baseJoint->getRotation().x;
}
GLfloat const & Tail::getFirstJointAngle() const {
	return _firstJoint->getRotation().x;
}
GLfloat const & Tail::getSecondJointAngle() const {
	return _secondJoint->getRotation().x;
}
GLfloat const & Tail::getTailEndJointAngle() const {
	return _tailEndJoint->getRotation().x;
}

void Tail::setBaseJointAngle(GLfloat const & basetJointAngle) {
	_baseJoint->getRotation().x = basetJointAngle;
}
void Tail::setFirstJointAngle(GLfloat const & firstJointAngle) {
	_firstJoint->getRotation().x = firstJointAngle;
}
void Tail::setSecondJointAngle(GLfloat const & secondJointAngle) {
	_secondJoint->getRotation().x = secondJointAngle;
}
void Tail::setTailEndJointAngle(GLfloat const & tailEndJointAngle) {
	_tailEndJoint->getRotation().x = tailEndJointAngle;
}

Tail::Tail(ExcellentPuppy::Modeling::Material *material,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity({}, position, rotation, scaling){
	ExcellentPuppy::Modeling::Model* tailLinkSphere = ExcellentPuppy::Modeling::SphereModel::generate(360, 180, 10, 10);
	tailLinkSphere->setMaterial(material);
	ExcellentPuppy::Modeling::Model* tailLinkCylinder = new ExcellentPuppy::Modeling::CylinderModel(TAIL_RADIUS, TAIL_LINK_LENGTH, 10, 10);
	tailLinkCylinder->setMaterial(material);
	//ExcellentPuppy::Modeling::Model* tailCone = new ExcellentPuppy::Modeling::ConeModel(TAIL_RADIUS, TAIL_LINK_LENGTH, 10, 10);
	//tailCone->setMaterial(material);

	Entity *sphereEntity, *cylinderEntity;

	_baseJoint = new CompositeEntity({}, {}, {10});
	getEntities().push_back(_baseJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	_baseJoint->getEntities().push_back(sphereEntity);
	_baseJoint->getEntities().push_back(cylinderEntity);

	_firstJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	_baseJoint->getEntities().push_back(_firstJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	_firstJoint->getEntities().push_back(sphereEntity);
	_firstJoint->getEntities().push_back(cylinderEntity);

	_secondJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	_firstJoint->getEntities().push_back(_secondJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	_secondJoint->getEntities().push_back(sphereEntity);
	_secondJoint->getEntities().push_back(cylinderEntity);

	_tailEndJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH});
	_secondJoint->getEntities().push_back(_tailEndJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	//_tailEndJoint = new SimpleEntity(tailCone);
	_tailEndJoint->getEntities().push_back(sphereEntity);
}
Tail::~Tail() { }

