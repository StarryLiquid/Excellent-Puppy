#ifndef MENUING_LABEL_HPP_
#define MENUING_LABEL_HPP_

#include "MenuControl.hpp"

#include "../models/shapes2d/TextModel.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class TextModel;
	}
	namespace Menuing {
		/**
		 * A simple text label.
		 * Renders as the position in the center of text.
		 */
		class Label: public MenuControl {
			private:
				// A text model to show the text
				Modeling::TextModel _model;

			public:
				Label(GE2Dvector position, std::string text);
				virtual ~Label();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual bool handleClick(const GE2Dvector& position);
			protected:
				virtual void draw() const;
		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_LABEL_HPP_ */
