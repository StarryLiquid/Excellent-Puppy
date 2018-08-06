#ifndef MENUING_MAINMENU_HPP_
#define MENUING_MAINMENU_HPP_

#include "Menu.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		class Button;

		/**
		 * The main menu of the game
		 */
		class MainMenu : public Menu {
			private:
				// The action to call when the menu is dismissed
				void (*_onDismiss)();
				// TODO add button properties

			public:
				MainMenu(void (*onDismiss)());
				virtual ~MainMenu();
		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MAINMENU_HPP_ */
