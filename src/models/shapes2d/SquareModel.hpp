#ifndef MODELS_SHAPES2D_SQUAREMODEL_HPP_
#define MODELS_SHAPES2D_SQUAREMODEL_HPP_

#include "../Model2D.hpp"

#include "../../types2d.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A simple 2d square model
		 */
		class SquareModel: public Model2D {
			private:
				// The dimensions of the square
				GE2Dvector _dimensions;

			public:
				virtual GE2Dvector const & getDimensions() const;
				virtual void setDimensions(GE2Dvector const & dimensions);

				SquareModel(GE2Dvector dimensions);
				virtual ~SquareModel();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES2D_SQUAREMODEL_HPP_ */
