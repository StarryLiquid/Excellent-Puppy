#include "Engine.hpp"

#include <GL/freeglut.h>

#include "../entities/Flooring.hpp"
#include "../entities/SimpleEntity.hpp"
#include "../entities/CompositeEntity.hpp"
#include "../models/materials/ColorMaterial.hpp"
#include "../models/shapes/CubeModel.hpp"
#include "../models/shapes/SphereModel.hpp"
#include "../models/shapes/CylinderModel.hpp"
#include "../types.hpp"
#include "Camera.hpp"
#include "MouseController.hpp"

using namespace ExcellentPuppy::Engine;

// Handles special keyboard input
void handleSpecialKeyboard (int, int, int);

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

	ExcellentPuppy::Entities::Flooring *flooring = new ExcellentPuppy::Entities::Flooring(10,15);
	flooring->getPosition() -= flooring->extent()/2;
	_entities.push_back(flooring);
	ExcellentPuppy::Modeling::Model *wallModel = new ExcellentPuppy::Modeling::CubeModel({20, 20, 30}, {0, 0, 1, 1, 1, 1}, true);
	wallModel->setMaterial(new ExcellentPuppy::Modeling::ColorMaterial({0.8, 0.3, 0.3}));
	_entities.push_back(new ExcellentPuppy::Entities::SimpleEntity(wallModel, {-10, 0, 15}));

	// TODO: lamp
	ExcellentPuppy::Modeling::Material *lampMaterial = new ExcellentPuppy::Modeling::ColorMaterial({0.5, 0.5, 0.5});
	ExcellentPuppy::Modeling::Material *lampBulbMaterial = new ExcellentPuppy::Modeling::ColorMaterial({1, 1, 1});
	ExcellentPuppy::Modeling::Model *lampBaseModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 90, 30, 15);
	lampBaseModel->setMaterial(lampMaterial);
	ExcellentPuppy::Entities::Entity *lampBase = new ExcellentPuppy::Entities::SimpleEntity(lampBaseModel, {0, 0, 0}, {180, 0, 0});
	ExcellentPuppy::Modeling::Model *lampPoleModel = new ExcellentPuppy::Modeling::CylinderModel(0.1, 5+0.2, 30, 1);
	lampPoleModel->setMaterial(lampMaterial);
	ExcellentPuppy::Entities::Entity *lampPole = new ExcellentPuppy::Entities::SimpleEntity(lampPoleModel, {0,  1 - 0.1, 0}, {-90, 0, 0});
	ExcellentPuppy::Modeling::Model *lampBulbModel = ExcellentPuppy::Modeling::SphereModel::generate(360, 180, 30, 15);
	lampBulbModel->setMaterial(lampBulbMaterial);
	ExcellentPuppy::Entities::Entity *lampBulb = new ExcellentPuppy::Entities::SimpleEntity(lampBulbModel, {0, 1 + 5 + 1/2, 0}, {0, 0, 0}, {0.25, 0.5, 0.25});
	_entities.push_back(new ExcellentPuppy::Entities::CompositeEntity({lampBase, lampPole, lampBulb}));

	// Set a camera
	Engine::_camera = new Camera({0, 3, 3}); // TODO: move this somewhere else?
	Engine::_camera->setGLProjection();

	// GL settings
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

	/*
	// Set lighting
	// TODO should probably move this to the lamp
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0);
	 */
}
void Engine::registerCallbacks() {
	glutDisplayFunc(Engine::render);
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

	for(Entities::Entity *current : _entities)
		current->render();

	glutSwapBuffers();
	glutPostRedisplay();

	// TODO: everything
}

//TODO: should get rid of this eventually
void handleSpecialKeyboard (int key, int x, int y) {
	Camera *camera = Engine::getCamera();
	if(camera != NULL){
		if(key==GLUT_KEY_UP)
			camera->getPosition().z -= 1;
		if(key==GLUT_KEY_DOWN)
			camera->getPosition().z += 1;
		if(key==GLUT_KEY_LEFT)
			camera->getPosition().x -= 1;
		if(key==GLUT_KEY_RIGHT)
			camera->getPosition().x += 1;

		camera->setGLProjection();
	}
}
