#ifndef MODELS_MODELCNV_HPP_
#define MODELS_MODELCNV_HPP_

#include "Model.hpp"
#include "../types.hpp"

#define GE_CNV_FORMAT GL_C4F_N3F_V3F

typedef struct {
	GEcolor color;
	GEvector normal;
	GEvector vertex;
} GEcnv;

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry;

		class ModelCNV : public Model {
			private:
				GEcnv const *_specs;
				Geometry const *_geometry;

			public:
				ModelCNV(GEcnv const *specs, Geometry const *geometry);
				virtual ~ModelCNV();

				virtual void load() const;
				virtual void render() const;
		};

	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_MODELCNV_HPP_ */
