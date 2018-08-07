#include "Tail.hpp"

#include "../SimpleEntity.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/shapes/CylinderModel.hpp"
//#include "../../models/shapes/ConeModel.hpp"

using namespace ExcellentPuppy::Entities;


CompositeEntity* const & Tail::getBaseJoint() const {
	return _baseJoint;
}
CompositeEntity* const & Tail::getFirstJoint() const {
	return _firstJoint;
}
CompositeEntity* const & Tail::getSecondJoint() const {
	return _secondJoint;
}
CompositeEntity* const & Tail::getTailEndJoint() const {
	return _tailEndJoint;
}

Tail::Tail(ExcellentPuppy::Modeling::Material *material,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity({}, position, rotation, scaling){
	auto tailLinkSphere = ExcellentPuppy::Modeling::SphereModel::generate(360, 180, 10, 10);
	tailLinkSphere->setMaterial(material);
	auto tailLinkCylinder = new ExcellentPuppy::Modeling::CylinderModel(TAIL_RADIUS, TAIL_LINK_LENGTH, 10, 10);
	tailLinkCylinder->setMaterial(material);
	//ExcellentPuppy::Modeling::Model* tailCone = new ExcellentPuppy::Modeling::ConeModel(TAIL_RADIUS, TAIL_LINK_LENGTH, 10, 10);
	//tailCone->setMaterial(material);
	//getDependents()->insert(tailCone);
	getDependents()->insert(tailLinkSphere);
	getDependents()->insert(tailLinkCylinder);

	Entity *sphereEntity, *cylinderEntity;

	_baseJoint = new CompositeEntity({}, {}, {10});
	getEntities().push_back(_baseJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	getDependents()->insert(sphereEntity);
	getDependents()->insert(cylinderEntity);
	getDependents()->insert(_baseJoint);
	_baseJoint->getEntities().push_back(sphereEntity);
	_baseJoint->getEntities().push_back(cylinderEntity);

	_firstJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	_baseJoint->getEntities().push_back(_firstJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	_firstJoint->getEntities().push_back(sphereEntity);
	_firstJoint->getEntities().push_back(cylinderEntity);
	getDependents()->insert(_firstJoint);
	getDependents()->insert(sphereEntity);
	getDependents()->insert(cylinderEntity);

	_secondJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	_firstJoint->getEntities().push_back(_secondJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	_secondJoint->getEntities().push_back(sphereEntity);
	_secondJoint->getEntities().push_back(cylinderEntity);
	getDependents()->insert(_secondJoint);
	getDependents()->insert(sphereEntity);
	getDependents()->insert(cylinderEntity);

	_tailEndJoint = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH});
	_secondJoint->getEntities().push_back(_tailEndJoint);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	//_tailEndJoint = new SimpleEntity(tailCone);
	_tailEndJoint->getEntities().push_back(sphereEntity);
	getDependents()->insert(_tailEndJoint);
	getDependents()->insert(sphereEntity);
}
Tail::~Tail() { }

