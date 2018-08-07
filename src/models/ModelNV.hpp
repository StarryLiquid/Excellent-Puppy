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
				GEnv const * const _specs;
				// The geometry to render this model in
				std::list<Geometry const *> const _geometries;

			public:
				GEnv const * getSpecs() const;
				std::list<Geometry const *> const & getGeometries() const;

				ModelNV(const GEnv *specs, std::list<Geometry const *> geometries);
				virtual ~ModelNV();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELNV_HPP_ */
