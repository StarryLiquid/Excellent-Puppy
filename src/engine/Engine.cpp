#include "Engine.hpp"

#include <GL/freeglut.h>
#include "../models/TriangleGeometry.hpp"
#include "../models/ModelCNV.hpp"
#include "../object/CompositeEntity.hpp"
#include "../object/SimpleEntity.hpp"
#include "../engine/Camera.hpp"
#include "../object/Flooring.hpp"
#include "../object/TestEntity.hpp"
#include "../types.hpp"
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

	// Some exmple entities
	// TODO: remove when not needed
	_entities.push_back(ExcellentPuppy::Entities::TestEntity::testEntity());
	ExcellentPuppy::Entities::Flooring *flooring = new ExcellentPuppy::Entities::Flooring(10,15);
	flooring->getPosition() -= flooring->extent()/2;
	_entities.push_back(flooring);

	// Set a camera
	Engine::_camera = new Camera(-(GEvector){0, 3, 3}); // TODO: move this somewhere else?
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
