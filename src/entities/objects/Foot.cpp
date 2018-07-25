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
	frameModel->setMaterial(dogMaterial);
	Entity* frameEntity = new SimpleEntity(frameModel);
	getEntities().push_back(frameEntity);
	//TODO: _toDelete.push_back(frameEntity);
	_toDelete.push_back(frameModel);

	Modeling::PawPad *bigPadModel = Modeling::PawPad::create();
	bigPadModel->setMaterial(pawMaterial);
	Entity* bigPadEntity = new Entities::SimpleEntity(bigPadModel);
	getEntities().push_back(bigPadEntity);
	//TODO: _toDelete.push_back(bigPadEntity);
	_toDelete.push_back(bigPadModel);

	Modeling::SphereModel *smallPadModel = Modeling::SphereModel::generate(360, 90, 10, 10);
	smallPadModel->setMaterial(pawMaterial);
	Entity* smallPadEntity = new Entities::SimpleEntity(bigPadModel, {-0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	getEntities().push_back(smallPadEntity);
	//TODO: _toDelete.push_back(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(bigPadModel, {0.4,0,-0.65}, {}, {0.2/2, 0.1, 0.35/2});
	getEntities().push_back(smallPadEntity);
	//TODO: _toDelete.push_back(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(bigPadModel, {-0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	getEntities().push_back(smallPadEntity);
	//TODO: _toDelete.push_back(smallPadEntity);
	smallPadEntity = new Entities::SimpleEntity(bigPadModel, {0.15,0,-1.0}, {}, {0.2/2, 0.1, 0.35/2});
	getEntities().push_back(smallPadEntity);
	//TODO: _toDelete.push_back(smallPadEntity);
	_toDelete.push_back(smallPadModel);
}
Foot::~Foot() {
	for(Modeling::Model *model : _toDelete) {
		delete(model);
	}
}
