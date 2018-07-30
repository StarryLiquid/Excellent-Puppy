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

// Creates the lamp entity
ExcellentPuppy::Entities::Entity* createLamp(ExcellentPuppy::Engine::Light* light);

// Action handlers
decltype(MouseController::_onMove) moveCamera = [] (int dX, int dY) {
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
	}
};
decltype(MouseController::_onClick) switchToMenu = [] (double x, double y) {
	MouseController::setMouseLocked(!MouseController::isMouseLocked());
	if(MouseController::isMouseLocked())
		MouseController::_onMove = moveCamera;
	else
		MouseController::_onMove = NULL;
};

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
void Engine::initScene() {
	// Lock the mouse
	MouseController::setMouseLocked(true);
	MouseController::_onClick = switchToMenu;
	MouseController::_onMove = moveCamera;

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
	Engine::_camera = new Camera({0, 3, 3}); // TODO: move this somewhere else?
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
	Entities::Entity* dog = new Entities::Dog(_camera->getPosition() + (GEvector){0, -1, -2}, {0, 90, 0});
	_entities.push_back(dog);
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

//TODO: should get rid of this eventually
void Engine::handlelKeyboard (unsigned char key, int x, int y) {
	Camera *camera = Engine::getCamera();
	if(camera != NULL){
		if(key==' ')
			camera->getPosition().y += 0.1;
		if(key=='c')
			camera->getPosition().y -= 0.1;

		camera->setCameraProjection();
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

		camera->getPosition() += moveBy;
		camera->setCameraProjection();
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
