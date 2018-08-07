#include "Foot.hpp"

#include "../../models/shapes/FootFrame.hpp"
#include "../../models/shapes/PawPad.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../SimpleEntity.hpp"

using namespace ExcellentPuppy::Entities;
		
Foot::Foot(Modeling::Material *dogMaterial,
		Modeling::Material *pawMaterial,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity({}, position, rotation, scaling) {
	auto frameModel = Modeling::FootFrame::create();
	frameModel->setMaterial(dogMaterial);
	auto frameEntity = new SimpleEntity(frameModel);
	getEntities().push_front(frameEntity);
	getDependents()->insert(frameModel);
	getDependents()->insert(frameEntity);

	auto bigPadModel = Modeling::PawPad::create();
	bigPadModel->setMaterial(pawMaterial);
	auto bigPadEntity = new Entities::SimpleEntity(bigPadModel);
	getEntities().push_front(bigPadEntity);
	getDependents()->insert(bigPadModel);
	getDependents()->insert(bigPadEntity);

	auto smallPadModel = Modeling::SphereModel::generate(360, 90, 10, 10);
	getDependents()->insert(smallPadModel);
	smallPadModel->setMaterial(pawMaterial);
	auto smallPadEntity = new Entities::SimpleEntity(smallPadModel, {-0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	getDependents()->insert(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	getDependents()->insert(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {-0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	getDependents()->insert(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	getDependents()->insert(smallPadEntity);
	getEntities().push_front(smallPadEntity);
}
Foot::~Foot() { }
