#include "Engine.hpp"

#include <GL/freeglut.h>

#include "../entities/objects/Flooring.hpp"
#include "../entities/objects/Dog.hpp"
#include "../entities/SimpleEntity.hpp"
#include "../entities/CompositeEntity.hpp"
#include "../entities/LightEntity.hpp"
#include "../models/materials/ColorMaterial.hpp"
#include "../models/materials/LightMaterial.hpp"
#include "../models/shapes/CubeModel.hpp"
#include "../models/shapes/SphereModel.hpp"
#include "../models/shapes/CylinderModel.hpp"
#include "../types.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "MouseController.hpp"

using namespace ExcellentPuppy::Engine;

// Room dimensions
const GLint ROOM_WIDTH  = 20;
const GLint ROOM_HEIGHT = 20;
const GLint ROOM_DEPTH  = 30;

// Camera displacements
const GEvector ABOVE_DOG_DISP = {0, 2.8, 0.5};
const GEvector DOG_EYES_DISP = {1, 1, 0};
const GEvector TAIL_DISP = {0, 1, 3};

// Creates the lamp entity
ExcellentPuppy::Entities::Entity* createLamp(ExcellentPuppy::Engine::Light* light);

// Screen dimensions, with starting values
int Engine::_screenWidth = 800;
const int& Engine::getScreenWidth() {
	return _screenWidth;
}
int Engine::_screenHeight = 800;
const int& Engine::getScreenHeight() {
	return _screenHeight;
}
Camera* Engine::_camera = NULL;
Camera*& Engine::getCamera() {
	return Engine::_camera;
}
void Engine::setCamera(Camera* camera) {
	Engine::_camera = camera;
}
std::list<ExcellentPuppy::Entities::Entity*> Engine::_entities;
std::list<ExcellentPuppy::Entities::Entity*>& Engine::getEntities() {
	return _entities;
}
GameState Engine::_currentState = Walking;
const GameState& Engine::getCurrentState() {
	return _currentState;
}
void Engine::setCurrentState(const GameState& state) {
	_currentState = state;
	switch(state) {
		case Walking: {
			// Lock the mouse and let the user move, move the camera behind the dog
			MouseController::setMouseLocked(true);
			MouseController::_onClick = _switchToMenu;
			MouseController::_onMove = _moveCamera;

			getCamera()->setPostPosition(ABOVE_DOG_DISP);
			updateCameraPosition();
		}
		break;
		case Tail: {
			// Lock the mouse and let the user move the tail, move the camera in front of tail
			MouseController::setMouseLocked(true);
			MouseController::_onClick = _switchToMenu;
			MouseController::_onMove = NULL; // TODO implement tail moving

			getCamera()->setPostPosition(TAIL_DISP);
			updateCameraPosition();
		}
		break;
		case WalkingFPS: {
			// Lock the mouse and let the user move, move the camera inside the dog's head
			MouseController::setMouseLocked(true);
			MouseController::_onClick = _switchToMenu;
			MouseController::_onMove = _moveCamera;

			getCamera()->setPostPosition(DOG_EYES_DISP);
			updateCameraPosition();
		}
		break;
		case Menu: {
			MouseController::setMouseLocked(false);
			MouseController::_onClick = _switchToMenu;
			MouseController::_onMove = NULL;
		}
		break;
	}
}

void Engine::init(int argc, char** argv) {
	initWindow(argc, argv);
	initSubsystems();
	initScene();
	loadEntities();
	registerCallbacks();
	glutMainLoop();
}
void Engine::initWindow(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(_screenWidth, _screenHeight);
	glutCreateWindow("Excellent Puppy");
}
void Engine::initSubsystems() {
	// TODO: init texture manager
}
ExcellentPuppy::Entities::Dog *Engine::_dog = NULL;
void Engine::initScene() {
	// Set clear color to a sky color
	glClearColor(0.8, 0.9, 1, 1);

	// GL settings
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

	// Set lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Use actual viewing angle

	// Set a camera
	Engine::_camera = new Camera();
	Engine::_camera->setCameraProjection();

	// Set up scene world geometry (walls, floor, roof)
	Entities::Flooring *flooring = new Entities::Flooring(
			ROOM_WIDTH/Entities::Flooring::tileDimension,
			ROOM_DEPTH/Entities::Flooring::tileDimension);
	flooring->getPosition() -= flooring->extent()/2;
	_entities.push_back(flooring);
	auto wallMaterial = new Modeling::LightMaterial({{0.8, 0.3, 0.3}, {0.8, 0.3, 0.3}, {0.8, 0.3, 0.3}, {}, 4, {1, 1, 1, 0, 1}});
	auto roofMaterial = new Modeling::LightMaterial({{1, 1, 1}, {1, 1, 1}, {0.7, 0.7, 0.7}, {}, 4, {1, 1, 1, 0, 1}});
	Modeling::Model *wallModel = new Modeling::CubeModel(
			{ROOM_WIDTH, ROOM_HEIGHT - Entities::Flooring::bottom, ROOM_DEPTH},
			{NULL, roofMaterial, wallMaterial, wallMaterial, wallMaterial, wallMaterial},
			true);
	_entities.push_back(new Entities::SimpleEntity(wallModel, {-ROOM_WIDTH/2, Entities::Flooring::bottom, ROOM_DEPTH/2}));

	// Create a light
	Light * lampLight = new Light(GL_LIGHT0);
	lampLight->setAmbient({0.1, 0.1, 0.1});
	lampLight->setDiffuse({1, 1, 1});
	lampLight->setSpecular({1, 1, 1});
	lampLight->setConstantAttenuation(0.2);
	lampLight->setLinearAttenuation(0.1);
	lampLight->setQuadraticAttenuation(0);

	// Lamp
	Entities::Entity* lamp = createLamp(lampLight);
	lamp->setPosition({5, 0, -10});
	_entities.push_back(lamp);

	// Dog
	_dog = new Entities::Dog();
	_entities.push_back(_dog);

	// Set mode to walking
	setCurrentState(Walking);
}
void Engine::registerCallbacks() {
	glutDisplayFunc(Engine::render);
	glutKeyboardFunc(handlelKeyboard);
	glutSpecialFunc(handleSpecialKeyboard);
	glutReshapeFunc(handleScreenReshape);
	MouseController::registerCallbacks();
}
void Engine::loadEntities() {
	for(Entities::Entity *current : _entities)
		current->load();
}

void Engine::render (void) {
	// TODO: animate()
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render all the entities
	for(Entities::Entity *current : _entities)
		current->render();

	// Swap buffers and signal to render next frame
	glutSwapBuffers();
	glutPostRedisplay();
}
void Engine::updateCameraPosition() {
	_camera->setPosition(_dog->getPosition());
	_camera->setCameraProjection();
}

// Action handlers
decltype(MouseController::_onMove) Engine::_moveCamera = [] (int dX, int dY) {
	auto camera = Engine::getCamera();
	if(camera != NULL && (dX != 0 || dY != 0)){
		camera->getRotationY() -= dX;
		camera->getRotationX() -= dY;

		// Clamp x rotation so the camera will never go upside down
		if(camera->getRotationX() < -90)
			camera->getRotationX() = -90;
		if(camera->getRotationX() > 90)
			camera->getRotationX() = 90;
		camera->setCameraProjection();

		// Update dog rotation
		_dog->setRotation({0, camera->getRotationY() ,0});
	}
};
decltype(MouseController::_onClick) Engine::_switchToMenu = [] (double x, double y) {
	if(_currentState == Menu)
		setCurrentState(Walking);
	else
		setCurrentState(Menu);
};
void Engine::handlelKeyboard (unsigned char key, int x, int y) {
	if(_currentState != Menu) {
		switch(key) {
			case ' ': {
				setCurrentState(_currentState != Tail ? Tail : Walking);
			}
			break;
		}
	}
}
void Engine::handleSpecialKeyboard (int key, int x, int y) {
	auto *camera = Engine::getCamera();
	GEvector moveBy = {};
	if(camera != NULL){
		if(key==GLUT_KEY_UP)
			moveBy.x -= 0.1;
		if(key==GLUT_KEY_DOWN)
			moveBy.x += 0.1;
		if(key==GLUT_KEY_LEFT)
			moveBy.z -= 0.1;
		if(key==GLUT_KEY_RIGHT)
			moveBy.z += 0.1;

		moveBy = moveBy.rotateY(-camera->getRotationY());

		//camera->getPosition() += moveBy;
		_dog->setPosition(_dog->getPosition() + moveBy);
		updateCameraPosition();
	}
}
void Engine::handleScreenReshape(int width, int height) {
	Engine::_screenWidth = width;
	Engine::_screenHeight = height;
	glViewport(0, 0, width, height);
	Camera::setRatio((GLdouble)(width) / height);
}

ExcellentPuppy::Entities::Entity* createLamp(ExcellentPuppy::Engine::Light* light) {
	ExcellentPuppy::Modeling::Material *lampMaterial = new ExcellentPuppy::Modeling::LightMaterial({{0.5, 0.5, 0.5}, {0.1, 0.1, 0.1}, {1, 1, 1}, {0, 0, 0}, 32, {1, 1, 1, 1, 1}});
	ExcellentPuppy::Modeling::Material *lampBulbMaterial = new ExcellentPuppy::Modeling::LightMaterial({{1, 1, 1}, {1, 1, 0.4}, {0, 0, 0},  {0.9, 0.9, 0.9}, 1, {1, 1, 1, 1, 1}});
	ExcellentPuppy::Modeling::Model *lampBaseModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 90, 30, 15);
	lampBaseModel->setMaterial(lampMaterial);
	ExcellentPuppy::Entities::Entity *lampBase = new ExcellentPuppy::Entities::SimpleEntity(lampBaseModel, {0, 0, 0}, {180, 0, 0});
	ExcellentPuppy::Modeling::Model *lampPoleModel = new ExcellentPuppy::Modeling::CylinderModel(0.1, 5+0.2, 30, 1);
	lampPoleModel->setMaterial(lampMaterial);
	ExcellentPuppy::Entities::Entity *lampPole = new ExcellentPuppy::Entities::SimpleEntity(lampPoleModel, {0,  1 - 0.1, 0}, {-90, 0, 0});
	ExcellentPuppy::Modeling::Model *lampBulbModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 180, 30, 15);
	lampBulbModel->setMaterial(lampBulbMaterial);
	ExcellentPuppy::Entities::Entity *lampBulbModelEntity = new ExcellentPuppy::Entities::SimpleEntity(lampBulbModel, {0, 0, 0}, {0, 0, 0}, {0.25, 0.5, 0.25});
	ExcellentPuppy::Entities::Entity *lampBulbLight = new ExcellentPuppy::Entities::LightEntity(light);
	ExcellentPuppy::Entities::Entity *lampBulb = new ExcellentPuppy::Entities::CompositeEntity({lampBulbModelEntity, lampBulbLight}, {0, 1 + 5 + 1/2, 0});
	return new ExcellentPuppy::Entities::CompositeEntity({lampBase, lampPole, lampBulb});
}
