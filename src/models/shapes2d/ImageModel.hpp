#ifndef MODELS_SHAPES2D_IMAGEMODEL_HPP_
#define MODELS_SHAPES2D_IMAGEMODEL_HPP_

#include "SquareModel.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Texture;
		
		/**
		 * A texture image.
		 */
		class ImageModel: public SquareModel {
			private:
				// The model's texture
				Texture const * const _texture;

			public:
				Texture const * getTexture() const;

				ImageModel(Texture const * const texture, GE2Dvector dimensions);
				virtual ~ImageModel();

				virtual void load() const;
			protected:
				void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES2D_IMAGEMODEL_HPP_ */
