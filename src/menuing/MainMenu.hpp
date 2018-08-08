#ifndef MENUING_MAINMENU_HPP_
#define MENUING_MAINMENU_HPP_

#include "MenuControl.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		class Menu;

		/**
		 * The main menu of the game
		 */
		class MainMenu : public MenuControl {
			private:
				// The action to call when the menu is dismissed
				void (*_onDismiss)();
				// The active menu to render
				Menu* _activeMenu;
				// The main menu to show at the start
				Menu* _buttonMenu;
				// The settings menu
				Menu* _settingsMenu;
				// The help screen
				Menu* _helpsMenu;

			public:
				MainMenu(void (*onDismiss)());
				virtual ~MainMenu();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual bool handleClick(const GE2Dvector& position);
			private:
				virtual void draw() const;
			private:
				void setActiveMenu(Menu* menu);

		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MAINMENU_HPP_ */
