#include "Model.hpp"

#include <GL/freeglut.h>

namespace excellentpuppy {

Model::Model(GEcnv const *specs, GEtriangle const *faces, const GLsizei nFaces) :
		_specs(specs),
		_faces(faces),
		_nVertices(nFaces*GE_TRI_COUNT){ }
Model::~Model() { }

void Model::load() {
	glInterleavedArrays(GE_CNV_FORMAT, sizeof(GEcnv), _specs);
}
void Model::render() {
	glDrawElements(GL_TRIANGLES, _nVertices, GE_TRI_TYPE, _faces);
}
void Model::unload() {

}

} /* namespace excellentpuppy */
