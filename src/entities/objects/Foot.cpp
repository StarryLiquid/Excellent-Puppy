#include "Foot.hpp"

#include "../../models/shapes/FootFrame.hpp"
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
}
Foot::~Foot() {
	for(Modeling::Model *model : _toDelete) {
		delete(model);
	}
}
