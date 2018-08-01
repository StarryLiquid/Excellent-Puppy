#ifndef MODELS_MODELTNV_HPP_
#define MODELS_MODELTNV_HPP_

#include "Model.hpp"
#include "../types.hpp"
#include <list>

// The format for this model
#define GE_TNV_FORMAT GL_T2F_N3F_V3F

// A struct to hold a single TNV entry
struct GEtnv {
	GEtexCoords coords;
	GEvector normal;
	GEvector vertex;
};

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry;
		class Texture;

		/**
		 * A model based on a texture coordinates, normal and vertex interleaved array
		 */
		class ModelTNV: public Model {
			private:
				// The models texture
				Texture *_tex;
				// The tnv interleaved array
				const GEtnv* _specs;
				// The geometry to render this model in
				const std::list<Geometry*> _geometries;

			public:
				ModelTNV(Texture* tex, const GEtnv* specs, const std::list<Geometry*> geometries);
				virtual ~ModelTNV();

				virtual void load() const;
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELTNV_HPP_ */
