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
				Texture const * const _texture;
				// The tnv interleaved array
				GEtnv const * const _specs;
				// The geometry to render this model in
				std::list<Geometry const *> const _geometries;

			public:
				Texture const * getTexture() const;
				GEtnv const * getSpecs() const;
				std::list<Geometry const *> const & getGeometries() const;

				ModelTNV(Texture const * tex, GEtnv const * specs, std::list<Geometry const *> geometries);
				virtual ~ModelTNV();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELTNV_HPP_ */
