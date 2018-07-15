#ifndef MODELS_MODELNV_HPP_
#define MODELS_MODELNV_HPP_

#include "Model.hpp"
#include "../types.hpp"
#include <list>

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
				const GEnv *_specs;
				// The geometry to render this model in
				const std::list<Geometry*> _geometries;

			public:
				ModelNV(const GEnv *specs, std::list<Geometry*> const & geometries);
				virtual ~ModelNV();

				virtual void load() const;
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELNV_HPP_ */
