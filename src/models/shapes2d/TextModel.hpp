#ifndef MODELS_SHAPES2D_TEXTMODEL_HPP_
#define MODELS_SHAPES2D_TEXTMODEL_HPP_

#include "../Model2D.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Represents text to be rendered on screen
		 */
		class TextModel: public Model2D {
			private:
				// The text of this model
				std::string _text;
				// The automatically calculated dimensions of the model
				GE2Dvector _calculatedDimensions;

			public:
				virtual std::string getText();
				virtual void setText(std::string text);
				virtual GE2Dvector const & getDimensions() const;

				TextModel(std::string text);
				virtual ~TextModel();

				virtual void load() const;
			protected:
				virtual void draw() const;
			private:
				// Calculates the dimensions of the model
				void calculateDimesnsions();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES2D_TEXTMODEL_HPP_ */
