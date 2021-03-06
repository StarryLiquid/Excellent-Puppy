#include "Model.hpp"

#include "materials/Material.hpp"

using namespace ExcellentPuppy::Modeling;

Model::Model() :
	_material(NULL) { }
Model::~Model() { }

Material* const & Model::getMaterial() const {
	return _material;
}
void Model::setMaterial(Material* material) {
	_material = material;
}
void Model::deleteMaterial() {
	delete(_material);
}

void Model::render() const {
	if(_material != NULL)
		_material->apply();
	draw();
}
