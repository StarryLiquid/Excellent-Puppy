#ifndef MENUING_BUTTON_HPP_
#define MENUING_MENUING_HPP_

#include "MenuControl.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Model2D;
	}
	namespace Menuing {
		/**
		 * A clickable button on a menu
		 */
		class Button : public MenuControl {
			private:
				// The background model of the button
				Modeling::Model2D* _model;
				// The action to execute on click
				void (*_action)(void* context);
				void* _context;

			public:
				virtual Modeling::Model2D * const getModel() const;
				virtual void setModel(Modeling::Model2D * const model);
				virtual void (*getAction())(void* context) const;
				virtual void setAction(void (*action)(void* context));

				Button(GE2Dvector position, Modeling::Model2D * model, void (*action)(void* context), void* context = NULL);
				virtual ~Button();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual bool handleClick(const GE2Dvector& position);
			protected:
				virtual void draw() const;
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MENUING_BUTTON_HPP_ */
