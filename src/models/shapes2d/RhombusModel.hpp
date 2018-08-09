#ifndef MODELS_SHAPES2D_RHOMBUSMODEL_HPP_
#define MODELS_SHAPES2D_RHOMBUSMODEL_HPP_

#include "SquareModel.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A simple rhombus model
		 */
		class RhombusModel: public SquareModel {
			public:
				RhombusModel(GE2Dvector dimensions);
				virtual ~RhombusModel();

			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES2D_RHOMBUSMODEL_HPP_ */
