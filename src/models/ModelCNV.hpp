#ifndef MODELS_MODELCNV_HPP_
#define MODELS_MODELCNV_HPP_

#include "Model.hpp"
#include "../types.hpp"
#include <list>

// The format for this model
#define GE_CNV_FORMAT GL_C4F_N3F_V3F

// A struct to hold a single CNV entry
struct GEcnv {
	GEcolor color;
	GEvector normal;
	GEvector vertex;
};

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry;

		/**
		 * A model based on a color, normal and vertex interleaved array
		 */
		class ModelCNV : public Model {
			private:
				// The cnv interleaved array
				GEcnv const * const _specs;
				// The geometry to render this model in
				std::list<Geometry const *> const _geometries;

			public:
				GEcnv const * getSpecs() const;
				std::list<Geometry const *> const & getGeometries() const;

				ModelCNV(const GEcnv *specs, std::list<Geometry const *> geometries);
				virtual ~ModelCNV();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_MODELCNV_HPP_ */
