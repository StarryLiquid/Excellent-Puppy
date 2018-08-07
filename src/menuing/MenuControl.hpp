#ifndef MENUING_MENUCONTROL_HPP_
#define MENUING_MENUCONTROL_HPP_

#include "../Base.hpp"

#include "../types2d.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		/**
		 * An abstract control in a menu.
		 */
		class MenuControl : public Base {
			private:
				// The position of the control
				GE2Dvector _position;

			public:
				const GE2Dvector& getPosition() const;
				void setPosition(GE2Dvector& position);

				MenuControl(GE2Dvector position);
				virtual ~MenuControl();

				// Render the control on screen
				virtual void render() const;
				// Check if the given point is in the control
				virtual bool testCollision(const GE2Dvector& point) const=0;
				// Do the click action
				virtual void click(const GE2Dvector& point)=0;
			private:
				// Draw the model of the control
				virtual void draw() const=0;
		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MENUCONTROL_HPP_ */
