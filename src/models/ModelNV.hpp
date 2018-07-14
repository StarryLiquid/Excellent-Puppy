#ifndef MODELS_MODELNV_HPP_
#define MODELS_MODELNV_HPP_

#include "Model.hpp"
#include "../types.hpp"

// The format for this model
#define GE_NV_FORMAT GL_N3F_V3F

// A struct to hold a single NV entry
struct GEnv {
	GEvector normal;
	GEvector vertex;
};

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry;
		
		/**
		 * A model based on a normal and vertex interleaved array
		 */
		class ModelNV : public Model {
			private:
				// The nv interleaved array
				GEnv const *_specs;
				// The geometry to render this model in
				Geometry const *_geometry;

			public:
				ModelNV(const GEnv *specs, const Geometry *geometry);
				virtual ~ModelNV();

				virtual void load() const;
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELNV_HPP_ */
