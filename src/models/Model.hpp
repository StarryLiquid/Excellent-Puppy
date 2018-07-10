#ifndef MODELS_MODEL_HPP_
#define MODELS_MODEL_HPP_

#include "../types.hpp"
#include <GL/freeglut.h>

namespace excellentpuppy {

class Model {
private:
	GEcnv const *_specs;
	GEtriangle const *_faces;
	const GLsizei _nVertices;

public:
	Model(GEcnv const *specs, GEtriangle const *faces, const GLsizei nFaces);
	virtual ~Model();

	virtual void load();
	virtual void render();
	virtual void unload();
};

} /* namespace excellentpuppy */

#endif /* MODELS_MODEL_HPP_ */
