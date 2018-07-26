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
			CompositeEntity({}, position, rotation, scaling) ,
			_toDelete({}) {
	Modeling::FootFrame *frameModel = Modeling::FootFrame::create();
	_toDelete.push_front(frameModel);
	frameModel->setMaterial(dogMaterial);
	Entity* frameEntity = new SimpleEntity(frameModel);
	//TODO: _toDelete.push_front(frameEntity);
	getEntities().push_front(frameEntity);

	Modeling::PawPad *bigPadModel = Modeling::PawPad::create();
	_toDelete.push_front(bigPadModel);
	bigPadModel->setMaterial(pawMaterial);
	Entity* bigPadEntity = new Entities::SimpleEntity(bigPadModel);
	//TODO: _toDelete.push_front(bigPadEntity);
	getEntities().push_front(bigPadEntity);

	Modeling::SphereModel *smallPadModel = Modeling::SphereModel::generate(360, 90, 10, 10);
	_toDelete.push_front(smallPadModel);
	smallPadModel->setMaterial(pawMaterial);
	Entity* smallPadEntity = new Entities::SimpleEntity(smallPadModel, {-0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	//TODO: _toDelete.push_front(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	//TODO: _toDelete.push_front(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {-0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	//TODO: _toDelete.push_front(smallPadEntity);
	getEntities().push_front(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(smallPadModel, {0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	//TODO: _toDelete.push_front(smallPadEntity);
	getEntities().push_front(smallPadEntity);
}
Foot::~Foot() {
	for(Modeling::Model *model : _toDelete) {
		delete(model);
	}
}
