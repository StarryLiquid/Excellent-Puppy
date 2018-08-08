#include "MainMenu.hpp"

#include "Menu.hpp"
#include "LabeledButton.hpp"
#include "../models/shapes2d/SquareModel.hpp"
#include "../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Menuing;
		
MainMenu::MainMenu(void (*onDismiss)()) :
	MenuControl({}) {
	_onDismiss = onDismiss;

	_buttonMenu = new Menu();
	auto buttonMaterial = new Modeling::ColorMaterial({.5, .5, 1});
	auto buttonModel = new Modeling::SquareModel({.4, .2});
	buttonModel->setMaterial(buttonMaterial);
	_buttonMenu->getDependents()->insert(buttonMaterial);
	_buttonMenu->getDependents()->insert(buttonModel);

	auto settingsButton = new LabeledButton("Settings", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .45}, buttonModel, []() {
		// TODO switch to settings menu
	});
	_buttonMenu->getControls().push_back(settingsButton);
	auto helpButton = new LabeledButton("Help", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .15}, buttonModel, []() {
		// TODO switch to help screen
	});
	_buttonMenu->getControls().push_back(helpButton);
	auto exitButton = new LabeledButton("Exit", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.15}, buttonModel, []() {
		glutLeaveMainLoop();
	});
	_buttonMenu->getControls().push_back(exitButton);
	auto dismissButton = new LabeledButton("Back", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.45}, buttonModel, _onDismiss);
	_buttonMenu->getControls().push_back(dismissButton);

	_buttonMenu->getDependents()->insert(settingsButton);
	_buttonMenu->getDependents()->insert(helpButton);
	_buttonMenu->getDependents()->insert(exitButton);
	_buttonMenu->getDependents()->insert(dismissButton);

	_settingsMenu = NULL;
	_helpsMenu = NULL;

	_activeMenu = _buttonMenu;
}
MainMenu::~MainMenu() {
	delete(_buttonMenu);
}

bool MainMenu::testCollision(const GE2Dvector& point) const {
	return _activeMenu->testCollision(point);
}
bool MainMenu::handleClick(const GE2Dvector& position) {
	return _activeMenu->handleClick(position);
}
void MainMenu::draw() const {
	_activeMenu->render();
}
void MainMenu::setActiveMenu(Menu* menu) {
	_activeMenu = menu;
}
