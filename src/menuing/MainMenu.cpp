#include "MainMenu.hpp"

#include "Button.hpp"
#include "../models/shapes2d/SquareModel.hpp"
#include "../models/materials/ColorMaterial.hpp"

using namespace ExcellentPuppy::Menuing;
		
MainMenu::MainMenu(void (*onDismiss)()) {
	_onDismiss = onDismiss;

	auto buttonModel = new Modeling::SquareModel({0.1, 0.1});
	auto buttonMaterial = new Modeling::ColorMaterial({0.5, 0.5, 1});
	buttonModel->setMaterial(buttonMaterial);
	auto dismissButton = new Button({0 ,0}, buttonModel, _onDismiss);
	getControls().push_back(dismissButton);

	// TODO add buttons
}
MainMenu::~MainMenu() {
	// TODO add button destructs
}
