#ifndef MENUING_LABELEDBUTTON_HPP_
#define MENUING_LABELEDBUTTON_HPP_

#include "Button.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class TextModel;
		class ColorMaterial;
	}
	namespace Menuing {
		/**
		 * A button with a text label
		 */
		class LabeledButton: public Button {
			private:
				// The model of the label, to be rendered over the button
				Modeling::TextModel* _labelModel;
				// The material of the label text
				Modeling::ColorMaterial* _labelColor;

			public:
				virtual std::string getLabel() const;
				virtual void setLabel(std::string label);

				LabeledButton(std::string label,
						GE2Dvector position,
						Modeling::Model2D *model,
						void (*action)(void* context),
						void* context = NULL);
				virtual ~LabeledButton();

			protected:
				virtual void draw() const;
		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_LABELEDBUTTON_HPP_ */
