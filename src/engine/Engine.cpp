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
#include "../models/shapes/FootFrame.hpp" // TODO remove
#include "../types.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "MouseController.hpp"

using namespace ExcellentPuppy::Engine;

// Room dimensions
const GLint ROOM_WIDTH  = 20;
const GLint ROOM_HEIGHT = 20;
const GLint ROOM_DEPTH  = 30;

// Handles keyboard input
void handlelKeyboard (unsigned char, int, int);
// Handles special keyboard input
void handleSpecialKeyboard (int, int, int);
// Creates the lamp entity
ExcellentPuppy::Entities::Entity* createLamp(ExcellentPuppy::Engine::Light* light);

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
	glutInitWindowSize(800, 800);
	glutCreateWindow("Excellent Puppy");
}
void Engine::initSubsystems() {
	// TODO: init texture manager
}
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
	Engine::_camera = new Camera({0, 3, 3}); // TODO: move this somewhere else?
	Engine::_camera->setGLProjection();

	// Set up scene world geometry (walls, floor, roof)
	// TODO: roof
	ExcellentPuppy::Entities::Flooring *flooring = new ExcellentPuppy::Entities::Flooring(
			ROOM_WIDTH/ExcellentPuppy::Entities::Flooring::tileDimension,
			ROOM_DEPTH/ExcellentPuppy::Entities::Flooring::tileDimension);
	flooring->getPosition() -= flooring->extent()/2;
	_entities.push_back(flooring);
	ExcellentPuppy::Modeling::Model *wallModel = new ExcellentPuppy::Modeling::CubeModel(
			{ROOM_WIDTH, ROOM_HEIGHT - ExcellentPuppy::Entities::Flooring::bottom, ROOM_DEPTH},
			{0, 0, 1, 1, 1, 1},
			true);
	wallModel->setMaterial(new ExcellentPuppy::Modeling::ColorMaterial({0.8, 0.3, 0.3}));
	_entities.push_back(new ExcellentPuppy::Entities::SimpleEntity(wallModel, {-ROOM_WIDTH/2, ExcellentPuppy::Entities::Flooring::bottom, ROOM_DEPTH/2}));

	// Create a light
	Light * lampLight = new Light(GL_LIGHT0);
	lampLight->setAmbient({0.1, 0.1, 0.1});
	lampLight->setDiffuse({1, 1, 1});
	lampLight->setSpecular({1, 1, 1});
	lampLight->setConstantAttenuation(0.2);
	lampLight->setLinearAttenuation(0.1);
	lampLight->setQuadraticAttenuation(0);

	// Lamp
	ExcellentPuppy::Entities::Entity* lamp = createLamp(lampLight);
	lamp->setPosition({5, 0, -10});
	_entities.push_back(lamp);

	// Dog
	ExcellentPuppy::Entities::Entity* dog = new ExcellentPuppy::Entities::Dog();
	_entities.push_back(dog);

	// TODO Paw test
	_entities.push_back(new ExcellentPuppy::Entities::SimpleEntity(ExcellentPuppy::Modeling::FootFrame::create(), {2,2,0}));
}
void Engine::registerCallbacks() {
	glutDisplayFunc(Engine::render);
	glutKeyboardFunc(handlelKeyboard);
	glutSpecialFunc(handleSpecialKeyboard);
	MouseController::registerCallbacks();
	//TODO: remove
	MouseController::setCameraControlling(true);
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
void handlelKeyboard (unsigned char key, int x, int y) {
	Camera *camera = Engine::getCamera();
	if(camera != NULL){
		if(key==' ')
			camera->getPosition().y += 0.1;
		if(key=='c')
			camera->getPosition().y -= 0.1;

		camera->setGLProjection();
	}
}
void handleSpecialKeyboard (int key, int x, int y) {
	Camera *camera = Engine::getCamera();
	if(camera != NULL){
		if(key==GLUT_KEY_UP)
			camera->getPosition().z -= 0.1;
		if(key==GLUT_KEY_DOWN)
			camera->getPosition().z += 0.1;
		if(key==GLUT_KEY_LEFT)
			camera->getPosition().x -= 0.1;
		if(key==GLUT_KEY_RIGHT)
			camera->getPosition().x += 0.1;

		camera->setGLProjection();
	}
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
