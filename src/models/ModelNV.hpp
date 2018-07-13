#ifndef MODELS_MODELNV_HPP_
#define MODELS_MODELNV_HPP_

#include "Model.hpp"
#include "../types.hpp"

#define GE_NV_FORMAT GL_N3F_V3F

typedef struct {
	GEvector normal;
	GEvector vertex;
} GEnv;

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry;
		
		class ModelNV: public Model {
			private:
				GEnv const *_specs;
				Geometry const *_geometry;

			public:
				ModelNV(GEnv const *specs, Geometry const *geometry);
				virtual ~ModelNV();

				virtual void load() const;
				virtual void render() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODELNV_HPP_ */
