#ifndef MENUING_BUTTON_HPP_
#define MENUING_MENUING_HPP_

#include "MenuControl.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class SquareModel;
	}
	namespace Menuing {
		/**
		 * A clickable button on a menu
		 */
		class Button : public MenuControl {
			private:
				// The background model of the button
				Modeling::SquareModel* _model;
				// The action to execute on click
				void (*_action)();

			public:
				virtual Modeling::SquareModel * const getModel() const;
				virtual void setModel(Modeling::SquareModel * const model);
				virtual void (*getAction())() const;
				virtual void setAction(void (*action)());

				Button(GE2Dvector position, Modeling::SquareModel * model, void (*action)());
				virtual ~Button();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual void click(const GE2Dvector& point);
			protected:
				virtual void draw() const;
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MENUING_BUTTON_HPP_ */
