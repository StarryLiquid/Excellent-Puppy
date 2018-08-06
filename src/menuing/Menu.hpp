#ifndef MENUING_MENU_HPP_
#define MENUING_MENU_HPP_

#include <list>
#include "../types2d.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		class MenuControl;

		/**
		 * A menu with controls that react to mouse clicks
		 */
		class Menu {
			private:
				// The buttons on the menu
				std::list<MenuControl*> _controls;

			public:
				std::list<MenuControl*>& getControls();

				Menu();
				virtual ~Menu();

				// Render the menu on screen
				void render();
				// Handle a mouse click on the menu
				void handleClick(const GE2Dvector& position);
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MENU_HPP_ */
