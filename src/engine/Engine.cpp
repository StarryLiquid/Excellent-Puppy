#include "Engine.hpp"

#include <GL/freeglut.h>

#include "../entities/objects/Flooring.hpp"
#include "../entities/objects/Dog.hpp"
#include "../entities/SimpleEntity.hpp"
#include "../entities/CompositeEntity.hpp"
#include "../entities/LightEntity.hpp"
#include "../entities/objects/PizzaBox.hpp"
#include "../entities/objects/Chair.hpp"
#include "../entities/objects/Table.hpp"
#include "../models/materials/ColorMaterial.hpp"
#include "../models/materials/LightMaterial.hpp"
#include "../models/shapes/CubeModel.hpp"
#include "../models/shapes/SphereModel.hpp"
#include "../models/shapes/CylinderModel.hpp"
#include "../menuing/MainMenu.hpp"
#include "../types.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "DirectionalLight.hpp"
#include "MouseController.hpp"
#include "TextureLoader.hpp"

using namespace ExcellentPuppy::Engine;

// Room dimensions
const GLint ROOM_WIDTH  = 20;
const GLint ROOM_HEIGHT = 20;
const GLint ROOM_DEPTH  = 30;

// Camera displacements for different camera modes
const GEvector ABOVE_DOG_DISP = {0, 2.8, 0.5};
const GEvector DOG_EYES_DISP = {0, 1, -1};
const GEvector TAIL_DISP = {0, 1, 3};
const GEvector DOG_FACE_DISP = {0, 1, 3};

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
std::list<std::pair<ExcellentPuppy::Entities::Entity*, GEvector>> Engine::_collisionEntities;
std::list<std::pair<ExcellentPuppy::Entities::Entity*, GEvector>>& Engine::getCollisionEntities() {
	return _collisionEntities;
}
GLfloat Engine::_ambientLight = 0.25;
GLfloat Engine::getAmbientLight() {
	return _ambientLight;
}
void Engine::setAmbientLight(GLfloat power) {
	_ambientLight = power;
	GEcolor ambientColor = {_ambientLight, _ambientLight, _ambientLight};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (GLfloat*)&ambientColor);
}
DirectionalLight* Engine::_directionalLight = NULL;
GLfloat Engine::_directionalLightPower = 1;
GLfloat Engine::getDirectionalLightPower() {
	return _directionalLightPower;
}
void Engine::setDirectionalLightPower(GLfloat power) {
	_directionalLight->setDiffuse({power, power, power});
	_directionalLight->setSpecular({power, power, power});
}
GLfloat Engine::_directionalLightAngle = 90;
GLfloat Engine::getDirectionalLightAngle() {
	return _directionalLightAngle;
}
void Engine::setDirectionalLightAngle(GLfloat angle){
	_directionalLight->setDirection((GEvector){0, -1, 1}.rotateY(angle));
}
GEvector Engine::_directionalLightPosition = {-3, 10, 6};
GLfloat Engine::getDirectionalLightXCoords() {
	return (_directionalLightPosition.x + ((GLfloat)ROOM_WIDTH)/2)/ROOM_WIDTH;
}
void Engine::setDirectionalLightXCoords(GLfloat x) {
	_directionalLightPosition.x = (x * ROOM_WIDTH) - ((GLfloat)ROOM_WIDTH)/2;
	_directionalLight->setPosition(_directionalLightPosition);
}
GLfloat Engine::getDirectionalLightZCoords() {
	return (_directionalLightPosition.z + ((GLfloat)ROOM_DEPTH)/2)/ROOM_DEPTH;
}
void Engine::setDirectionalLightZCoords(GLfloat z) {
	_directionalLightPosition.z = (z * ROOM_DEPTH) - ((GLfloat)ROOM_DEPTH)/2;
	_directionalLight->setPosition(_directionalLightPosition);
}
GameState Engine::_currentState = Walking;
const GameState& Engine::getCurrentState() {
	return _currentState;
}
void Engine::setCurrentState(const GameState& state) {
	// Correct camera rotation if needed
	if(_currentState == Head)
		getCamera()->getRotationY() -= 180;

	// Return tail and head to original angles
	_dog->setTailAngleX(0);
	_dog->setTailAngleY(0);
	_dog->setHeadAngleX(0);
	_dog->setHeadAngleY(0);

	// Change callbacks and other paramters to fit new state
	_currentState = state;
	switch(state) {
		case Walking: {
			// Lock the mouse and let the user move, move the camera behind the dog
			MouseController::setMouseLocked(true);
			MouseController::_onLeftClick = _switchToMenu;
			MouseController::_onRightClick = _switchPerspectives;
			MouseController::_onMove = _moveCamera;

			getCamera()->setPostPosition(ABOVE_DOG_DISP);
			updateCameraPosition();
		}
		break;
		case Tail: {
			// Lock the mouse and let the user move the tail, move the camera in front of tail
			MouseController::setMouseLocked(true);
			MouseController::_onLeftClick = _switchToMenu;
			MouseController::_onRightClick = NULL;
			MouseController::_onMove = _moveTail;

			getCamera()->setPostPosition(TAIL_DISP);
			getCamera()->getRotationX() = 0;
			updateCameraPosition();
		}
		break;
		case Head: {
			// Lock the mouse and let the user move the head, move the camera in front of dog's face
			MouseController::setMouseLocked(true);
			MouseController::_onLeftClick = _switchToMenu;
			MouseController::_onRightClick = NULL;
			MouseController::_onMove = _moveHead;

			getCamera()->setPostPosition(DOG_FACE_DISP);
			getCamera()->getRotationX() = 0;
			getCamera()->getRotationY() += 180;
			updateCameraPosition();
		}
		break;
		case WalkingFPS: {
			// Lock the mouse and let the user move, move the camera inside the dog's head
			MouseController::setMouseLocked(true);
			MouseController::_onLeftClick = _switchToMenu;
			MouseController::_onRightClick = _switchPerspectives;
			MouseController::_onMove = _moveCamera;

			getCamera()->setPostPosition(DOG_EYES_DISP);
			updateCameraPosition();
		}
		break;
		case Menu: {
			// Free the mouse and let the user click on menu items
			MouseController::setMouseLocked(false);
			MouseController::_onLeftClick = _switchToMenu;
			MouseController::_onRightClick = _clickMenu;
			MouseController::_onMove = NULL;
		}
		break;
	}
}

void Engine::init(int argc, char** argv) {
	initWindow(argc, argv);
	initScene();
	initMenu();
	initSubsystems();
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
	TextureLoader::loadTextures();
}
ExcellentPuppy::Entities::Dog *Engine::_dog = NULL;
void Engine::initScene() {
	// Set clear color to a sky color
	glClearColor(0.8, 0.9, 1, 1);

	// GL settings
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

	// Set lighting/shading
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Use actual viewing angle
	setAmbientLight(_ambientLight);

	// Set a camera
	Engine::_camera = new Camera();
	Engine::_camera->setCameraProjection();

	// Set up scene world geometry (walls, floor, roof)
	auto *flooring = new Entities::Flooring(
			ROOM_WIDTH/Entities::Flooring::tileDimension,
			ROOM_DEPTH/Entities::Flooring::tileDimension);
	flooring->getPosition() -= flooring->extent()/2;
	_entities.push_back(flooring);
	auto wallMaterial = new Modeling::LightMaterial({{0.8, 0.3, 0.3}, {0.8, 0.3, 0.3}, {0.8, 0.3, 0.3}, {}, 4, {1, 1, 1, 0, 1}});
	auto roofMaterial = new Modeling::LightMaterial({{1, 1, 1}, {1, 1, 1}, {0.7, 0.7, 0.7}, {}, 4, {1, 1, 1, 0, 1}});
	auto *wallModel = new Modeling::CubeModel(
			{ROOM_WIDTH, ROOM_HEIGHT - Entities::Flooring::bottom, ROOM_DEPTH},
			{NULL, roofMaterial, wallMaterial, wallMaterial, wallMaterial, wallMaterial},
			true);
	_entities.push_back(new Entities::SimpleEntity(wallModel, {-ROOM_WIDTH/2, Entities::Flooring::bottom, ROOM_DEPTH/2}));

	// Create a light
	auto lampLight = new Light(GL_LIGHT0);
	lampLight->setAmbient({0, 0, 0}); // Using global ambient light
	lampLight->setDiffuse({1, 1, 1});
	lampLight->setSpecular({1, 1, 1});
	lampLight->setConstantAttenuation(0.2);
	lampLight->setLinearAttenuation(0.1);
	lampLight->setQuadraticAttenuation(0);

	// Lamp
	auto lamp = createLamp(lampLight);
	lamp->setPosition({5, 0, -10});
	lamp->setCollisionRadius(1);
	_entities.push_back(lamp);
	_collisionEntities.push_back({lamp, {}});

	// Create a directional light
	_directionalLight = new DirectionalLight(GL_LIGHT1, {});
	_directionalLight->setAmbient({0, 0, 0}); // Using global ambient light
	_directionalLight->setConstantAttenuation(0.2);
	_directionalLight->setLinearAttenuation(0.1);
	_directionalLight->setQuadraticAttenuation(0);
	_directionalLight->setSpotlightCutoff(30);
	setDirectionalLightPower(getDirectionalLightPower());
	setDirectionalLightAngle(getDirectionalLightAngle());
	setDirectionalLightXCoords(getDirectionalLightXCoords());

	// Dog
	_dog = new Entities::Dog();
	_entities.push_back(_dog);

	// Pizza box
	auto pizzaBoxTexture = ExcellentPuppy::Engine::TextureLoader::createTexture("rsc/pizza lid texture.png");
	auto box = Entities::createPizzaBox(pizzaBoxTexture);
	box->setPosition({1, 0, -3.5});
	_entities.push_back(box);
	_collisionEntities.push_back({box, {}});

	// Chair
	auto chairMaterial = new Modeling::ColorMaterial({0.8, 0.45, 0.2});
	auto chair = Entities::Chair::createChair(chairMaterial);
	chair->setPosition({4, 0, -3.5});
	chair->setRotation({0, 90, 0});
	_entities.push_back(chair);
	_collisionEntities.push_back({chair, {}});
	chair->getDependents()->insert(chairMaterial);

	// Table
	auto table = new Entities::Table(chairMaterial, {4 + 2, 0, -3.5});
	_entities.push_back(table);
	// Only do collision with the table legs
	for(auto tableLeg : table->getTableLegs()) {
		_collisionEntities.push_back({tableLeg, table->getPosition()});
	}

	// Set mode to walking
	setCurrentState(Walking);
}
ExcellentPuppy::Menuing::MainMenu *Engine::_menu = NULL;
GameState Engine::_lastState = GameState::Walking;
void Engine::initMenu() {
	_menu = new Menuing::MainMenu([](void* context) {
		setCurrentState(_lastState);
	});
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

	_directionalLight->load();
}

void Engine::render (void) {
	// TODO: animate()
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(getCurrentState() != Menu) {
		// Set the location of the spotlight according to the projection
		_directionalLight->setLight();

		// Render all the entities
		for(Entities::Entity *current : _entities)
			current->render();
	}
	else {
		_menu->render();
	}

	// Swap buffers and signal to render next frame
	glutSwapBuffers();
	glutPostRedisplay();
}
void Engine::updateCameraPosition() {
	_camera->setPosition(_dog->getPosition());
	_camera->setCameraProjection();
}
void Engine::doCollision(Entities::Entity* entity, GLfloat wallCollisionDelta) {
	// Check collision with walls
	GLfloat wallCollisionRadius = entity->getCollisionRadius() + wallCollisionDelta;
	if(entity->getPosition().x  > ROOM_WIDTH/2 - wallCollisionRadius)
		entity->getPosition().x = ROOM_WIDTH/2 - wallCollisionRadius;
	if(entity->getPosition().x  < -(ROOM_WIDTH/2 - wallCollisionRadius))
		entity->getPosition().x = -(ROOM_WIDTH/2 - wallCollisionRadius);
	if(entity->getPosition().z  > ROOM_DEPTH/2 - wallCollisionRadius)
		entity->getPosition().z = ROOM_DEPTH/2 - wallCollisionRadius;
	if(entity->getPosition().z  < -(ROOM_DEPTH/2 - wallCollisionRadius))
		entity->getPosition().z = -(ROOM_DEPTH/2 - wallCollisionRadius);

	// Check collision with other collision enabled entities
	for(auto collisionEntityPair : _collisionEntities) {
		auto collisionEntity = collisionEntityPair.first;
		if(collisionEntity != entity) {
			GEvector correctedPosition = collisionEntity->getPosition() + collisionEntityPair.second;
			GLfloat minDistance = collisionEntity->getCollisionRadius() + entity->getCollisionRadius();
			GEvector direction = entity->getPosition() - correctedPosition;
			GLfloat directionDistance = direction.length();
			if(directionDistance < minDistance) {
				entity->getPosition() = correctedPosition + direction*(minDistance/directionDistance);
			}
		}
	}
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
decltype(MouseController::_onMove) Engine::_moveTail = [] (int dX, int dY) {
	if(dX != 0 || dY != 0){
		_dog->setTailAngleX(_dog->getTailAngleX() + dY);
		_dog->setTailAngleY(_dog->getTailAngleY() + dX);
	}
};
decltype(MouseController::_onMove) Engine::_moveHead = [] (int dX, int dY) {
	if(dX != 0 || dY != 0){
		_dog->setHeadAngleX(_dog->getHeadAngleX() - dY);
		_dog->setHeadAngleY(_dog->getHeadAngleY() + dX);
	}
};
decltype(MouseController::_onLeftClick) Engine::_switchToMenu = [] (const GE2Dvector& position) {
	// Switch to the menu if not on menu mode
	if(_currentState != Menu){
		_lastState = _currentState;
		setCurrentState(Menu);
	}
	// Pass click to the menu
	else {
		_menu->handleClick(position);
	}
};
decltype(MouseController::_onRightClick) Engine::_switchPerspectives = [] (const GE2Dvector& position) {
	if(_currentState == WalkingFPS)
		setCurrentState(Walking);
	else
		setCurrentState(WalkingFPS);
};
decltype(MouseController::_onRightClick) Engine::_clickMenu = [] (const GE2Dvector& position) {
	_menu->handleClick(position);
};
void Engine::handlelKeyboard (unsigned char key, int x, int y) {
	if(_currentState != Menu) {
		switch(key) {
			case ' ': {
				setCurrentState(_currentState != Tail ? Tail : Walking);
			}
			break;
			case 'H':
			case 'h': {
				setCurrentState(_currentState != Head ? Head : Walking);
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

		_dog->setPosition(_dog->getPosition() + moveBy);
		doCollision(_dog, 1);
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
	auto *lampMaterial = new ExcellentPuppy::Modeling::LightMaterial({{0.5, 0.5, 0.5}, {0.1, 0.1, 0.1}, {1, 1, 1}, {0, 0, 0}, 32, {1, 1, 1, 1, 1}});
	auto *lampBulbMaterial = new ExcellentPuppy::Modeling::LightMaterial({{1, 1, 1}, {1, 1, 0.4}, {0, 0, 0},  {0.9, 0.9, 0.9}, 1, {1, 1, 1, 1, 1}});
	auto *lampBaseModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 90, 30, 15);
	lampBaseModel->setMaterial(lampMaterial);
	auto *lampBase = new ExcellentPuppy::Entities::SimpleEntity(lampBaseModel, {0, 0, 0}, {180, 0, 0});
	auto *lampPoleModel = new ExcellentPuppy::Modeling::CylinderModel(0.1, 5+0.2, 30, 1);
	lampPoleModel->setMaterial(lampMaterial);
	auto *lampPole = new ExcellentPuppy::Entities::SimpleEntity(lampPoleModel, {0,  1 - 0.1, 0}, {-90, 0, 0});
	auto *lampBulbModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 180, 30, 15);
	lampBulbModel->setMaterial(lampBulbMaterial);
	auto *lampBulbModelEntity = new ExcellentPuppy::Entities::SimpleEntity(lampBulbModel, {0, 0, 0}, {0, 0, 0}, {0.25, 0.5, 0.25});
	auto *lampBulbLight = new ExcellentPuppy::Entities::LightEntity(light);
	auto *lampBulb = new ExcellentPuppy::Entities::CompositeEntity({lampBulbModelEntity, lampBulbLight}, {0, 1 + 5 + 1/2, 0});
	auto *lamp = new ExcellentPuppy::Entities::CompositeEntity({lampBase, lampPole, lampBulb});
	auto dependents = lamp->getDependents();
	dependents->insert(lampMaterial);
	dependents->insert(lampBulbMaterial);
	dependents->insert(lampBaseModel);
	dependents->insert(lampBase);
	dependents->insert(lampPoleModel);
	dependents->insert(lampPole);
	dependents->insert(lampBulbModel);
	dependents->insert(lampBulbLight);
	dependents->insert(lampBulb);
	return lamp;
}
