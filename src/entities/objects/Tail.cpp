#include "Tail.hpp"

#include "../SimpleEntity.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/shapes/CylinderModel.hpp"
//#include "../../models/shapes/ConeModel.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat TAIL_RADIUS = 0.1;
const GLfloat TAIL_LINK_LENGTH = 0.3;

// TODO: add ways to move the tails
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
	CompositeEntity *currentLink;
	currentLink = new CompositeEntity({}, {}, {10});
	getEntities().push_back(currentLink);
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	currentLink->getEntities().push_back(sphereEntity);
	currentLink->getEntities().push_back(cylinderEntity);
	CompositeEntity *newLink = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	currentLink->getEntities().push_back(newLink);
	currentLink = newLink;
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	currentLink->getEntities().push_back(sphereEntity);
	currentLink->getEntities().push_back(cylinderEntity);
	newLink = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH}, {-10});
	currentLink->getEntities().push_back(newLink);
	currentLink = newLink;
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	cylinderEntity = new SimpleEntity(tailLinkCylinder);
	currentLink->getEntities().push_back(sphereEntity);
	currentLink->getEntities().push_back(cylinderEntity);
	newLink = new CompositeEntity({}, {0, 0, TAIL_LINK_LENGTH});
	currentLink->getEntities().push_back(newLink);
	currentLink = newLink;
	sphereEntity = new SimpleEntity(tailLinkSphere, {}, {90}, {TAIL_RADIUS, TAIL_RADIUS ,TAIL_RADIUS});
	//sphereEntity = new SimpleEntity(tailCone);
	currentLink->getEntities().push_back(sphereEntity);
}
Tail::~Tail() { }

