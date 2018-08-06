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
				Modeling::SquareModel *_model;
				void (*_action)();

			public:
				Button(GE2Dvector position, Modeling::SquareModel *model, void (*action)());
				virtual ~Button();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual void click(const GE2Dvector& point);
			protected:
				virtual void draw() const;
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MENUING_BUTTON_HPP_ */
