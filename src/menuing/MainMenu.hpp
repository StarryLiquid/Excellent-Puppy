#ifndef MENUING_MAINMENU_HPP_
#define MENUING_MAINMENU_HPP_

#include "MenuControl.hpp"

namespace ExcellentPuppy {
	namespace Menuing {
		class MenuControl;
		class Menu;

		/**
		 * The main menu of the game
		 */
		class MainMenu : public MenuControl {
			private:
				// The action to call when the menu is dismissed
				void (*_onDismiss)(void* context);
				// The active menu to render
				MenuControl* _activeMenu;
				// The main menu to show at the start
				Menu* _buttonMenu;
				// The settings menu
				Menu* _settingsMenu;
				// The help screen
				MenuControl* _helpsScreen;

			public:
				MainMenu(void (*onDismiss)(void* context));
				virtual ~MainMenu();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual bool handleClick(const GE2Dvector& position);
			private:
				virtual void draw() const;
			private:
				// Sets the given control as the main control to render
				void setActiveMenu(MenuControl* menu);
				//  Changes to the button menu
				void goToButtonMenu();
				//  Changes to the settings menu
				void goToSettingsMenu();
				//  Changes to the help screen
				void goToHelpScreen();

		};
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_MAINMENU_HPP_ */
