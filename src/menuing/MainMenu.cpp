#include "MainMenu.hpp"

#include "Menu.hpp"
#include "LabeledButton.hpp"
#include "Slider.hpp"
#include "Label.hpp"
#include "../models/shapes2d/SquareModel.hpp"
#include "../models/materials/ColorMaterial.hpp"
#include "../engine/TextureLoader.hpp"
#include "../engine/Engine.hpp"
#include "../models/shapes2d/ImageModel.hpp"

using namespace ExcellentPuppy::Menuing;
		
MainMenu::MainMenu(void (*onDismiss)(void* context)) :
	MenuControl({}) {
	_onDismiss = onDismiss;

	_buttonMenu = new Menu();
	auto buttonMaterial = new Modeling::ColorMaterial({.5, .5, 1});
	auto buttonModel = new Modeling::SquareModel({.4, .2});
	buttonModel->setMaterial(buttonMaterial);
	_buttonMenu->getDependents()->insert(buttonMaterial);
	_buttonMenu->getDependents()->insert(buttonModel);

	auto settingsButton = new LabeledButton("Settings", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .45}, buttonModel, [](void* context) {
		((MainMenu*)context)->goToSettingsMenu();
	}, this);
	_buttonMenu->getControls().push_back(settingsButton);
	auto helpButton = new LabeledButton("Help", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, .15}, buttonModel, [](void* context) {
		((MainMenu*)context)->goToHelpScreen();
	}, this);
	_buttonMenu->getControls().push_back(helpButton);
	auto exitButton = new LabeledButton("Exit", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.15}, buttonModel, [](void* context) {
		glutLeaveMainLoop();
	});
	_buttonMenu->getControls().push_back(exitButton);
	auto dismissButton = new LabeledButton("Back", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.45}, buttonModel, _onDismiss, NULL);
	_buttonMenu->getControls().push_back(dismissButton);

	_buttonMenu->getDependents()->insert(settingsButton);
	_buttonMenu->getDependents()->insert(helpButton);
	_buttonMenu->getDependents()->insert(exitButton);
	_buttonMenu->getDependents()->insert(dismissButton);

	_settingsMenu = new Menu();
	auto ambientSlider = new Slider(
			(GE2Dvector){-Slider::SLIDER_DIMENSIONS.x/2, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .7},
			Engine::Engine::getAmbientLight(),
			[] (void* context, GLfloat value) {
				Engine::Engine::setAmbientLight(value);
			});
	_settingsMenu->getControls().push_back(ambientSlider);
	auto ambientSliderLabel = new Label((GE2Dvector){0, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .85}, "Ambient light");
	_settingsMenu->getControls().push_back(ambientSliderLabel);
	auto directionalPowerSlider = new Slider(
			(GE2Dvector){-Slider::SLIDER_DIMENSIONS.x/2, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .4},
			0.25, // TODO
			[] (void* context, GLfloat value) {
				//Engine::Engine::setAmbientLight(value); TODO
			});
	_settingsMenu->getControls().push_back(directionalPowerSlider);
	auto directionalPowerSliderLabel = new Label((GE2Dvector){0, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .55}, "Directional light");
	_settingsMenu->getControls().push_back(directionalPowerSliderLabel);
	auto directionalRotationSlider = new Slider(
			(GE2Dvector){-Slider::SLIDER_DIMENSIONS.x/2, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .1},
			0.25,
			[] (void* context, GLfloat value) {
				//Engine::Engine::setAmbientLight(value); TODO
			});
	_settingsMenu->getControls().push_back(directionalRotationSlider);
	auto directionalRotationSliderLabel = new Label((GE2Dvector){0, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, .25}, "Directional angle");
	_settingsMenu->getControls().push_back(directionalRotationSliderLabel);
	auto directionalXSlider = new Slider(
			(GE2Dvector){-Slider::SLIDER_DIMENSIONS.x/2, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, -.2},
			0.25, // TODO
			[] (void* context, GLfloat value) {
				//Engine::Engine::setAmbientLight(value); TODO
			});
	_settingsMenu->getControls().push_back(directionalXSlider);
	auto directionalXSliderLabel = new Label((GE2Dvector){0, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, -.05}, "Directional x position");
	_settingsMenu->getControls().push_back(directionalXSliderLabel);
	auto directionalYSlider = new Slider(
			(GE2Dvector){-Slider::SLIDER_DIMENSIONS.x/2, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, -.5},
			0.25, // TODO
			[] (void* context, GLfloat value) {
				//Engine::Engine::setAmbientLight(value); TODO
			});
	_settingsMenu->getControls().push_back(directionalYSlider);
	auto directionalYSliderLabel = new Label((GE2Dvector){0, -Slider::SLIDER_DIMENSIONS.y/2} + (GE2Dvector){0, -.35}, "Directional y position");
	_settingsMenu->getControls().push_back(directionalYSliderLabel);
	auto settingBackButton = new LabeledButton("Back", (GE2Dvector){-.2, -.1} + (GE2Dvector){0, -.7}, buttonModel, [](void* context) {
		((MainMenu*)context)->goToButtonMenu();
	}, this);
	_settingsMenu->getControls().push_back(settingBackButton);

	_settingsMenu->getDependents()->insert(ambientSlider);
	_settingsMenu->getDependents()->insert(ambientSliderLabel);
	_settingsMenu->getDependents()->insert(directionalPowerSlider);
	_settingsMenu->getDependents()->insert(directionalPowerSliderLabel);
	_settingsMenu->getDependents()->insert(directionalRotationSlider);
	_settingsMenu->getDependents()->insert(directionalRotationSliderLabel);
	_settingsMenu->getDependents()->insert(directionalXSlider);
	_settingsMenu->getDependents()->insert(directionalXSliderLabel);
	_settingsMenu->getDependents()->insert(directionalYSlider);
	_settingsMenu->getDependents()->insert(directionalYSliderLabel);
	_settingsMenu->getDependents()->insert(settingBackButton);

	_helpMenu = new Menu();
	auto helpTexutre = Engine::TextureLoader::createTexture("rsc/help.png");
	auto helpModel = new Modeling::ImageModel(helpTexutre, {2, 2});
	auto helpScreen = new Button({-1, -1}, helpModel, [](void* context) {
		((MainMenu*)context)->goToButtonMenu();
	}, this);
	_helpMenu->getControls().push_back(helpScreen);

	_helpMenu->getDependents()->insert(helpModel);
	_helpMenu->getDependents()->insert(helpScreen);

	_activeMenu = _buttonMenu;
}
MainMenu::~MainMenu() {
	delete(_buttonMenu);
	delete(_settingsMenu);
	delete(_helpMenu);
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
void MainMenu::setActiveMenu(MenuControl* menu) {
	_activeMenu = menu;
}
void MainMenu::goToButtonMenu() {
	setActiveMenu(_buttonMenu);
}
void MainMenu::goToSettingsMenu() {
	setActiveMenu(_settingsMenu);
}
void MainMenu::goToHelpScreen() {
	setActiveMenu(_helpMenu);
}
