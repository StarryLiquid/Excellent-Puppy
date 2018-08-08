#include "MainMenu.hpp"

#include "LabeledButton.hpp"
#include "../models/shapes2d/SquareModel.hpp"
#include "../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Menuing;
		
MainMenu::MainMenu(void (*onDismiss)()) {
	_onDismiss = onDismiss;

	auto buttonMaterial = new Modeling::ColorMaterial({.5, .5, 1});
	auto buttonModel = new Modeling::SquareModel({.4, .2});
	buttonModel->setMaterial(buttonMaterial);
	getDependents()->insert(buttonMaterial);
	getDependents()->insert(buttonModel);

	auto settingsButton = new LabeledButton("Settings", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .45}, buttonModel, []() {
		// TODO switch to settings menu
	});
	getControls().push_back(settingsButton);
	auto helpButton = new LabeledButton("Help", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .15}, buttonModel, []() {
		// TODO switch to help screen
	});
	getControls().push_back(helpButton);
	auto exitButton = new LabeledButton("Exit", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.15}, buttonModel, []() {
		glutLeaveMainLoop();
	});
	getControls().push_back(exitButton);
	auto dismissButton = new LabeledButton("Back", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.45}, buttonModel, _onDismiss);
	getControls().push_back(dismissButton);

	getDependents()->insert(settingsButton);
	getDependents()->insert(helpButton);
	getDependents()->insert(exitButton);
	getDependents()->insert(dismissButton);
}
MainMenu::~MainMenu() { }
