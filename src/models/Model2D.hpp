#ifndef MODELS_SHAPES2D_MODEL2D_HPP_
#define MODELS_SHAPES2D_MODEL2D_HPP_

#include "Model.hpp"

#include "../types2d.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * An abstract 2d model with 2d dimensions
		 */
		class Model2D: public Model {
			public:
				// The bounds of the shape
				virtual GE2Dvector const & getDimensions() const=0;

				Model2D();
				virtual ~Model2D();
		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES2D_MODEL2D_HPP_ */
