#ifndef MENUING_MENU_HPP_
#define MENUING_MENU_HPP_

#include "MenuControl.hpp"

#include <list>
#include "../types2d.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		/**
		 * A menu with controls that react to mouse clicks
		 */
		class Menu : public MenuControl {
			private:
				// The buttons on the menu
				std::list<MenuControl*> _controls;

			public:
				std::list<MenuControl*>& getControls();

				Menu();
				virtual ~Menu();

				// Returns true, as the menu should encompass the entire screen
				virtual bool testCollision(const GE2Dvector& point) const;
				// Handle a mouse click on the menu
				virtual bool handleClick(const GE2Dvector& position);
			protected:
				// Draw the menu on screen
				virtual void draw() const;
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MENU_HPP_ */
