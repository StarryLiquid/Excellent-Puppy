#include "Engine.hpp"

#include <GL/freeglut.h>
#include "../models/TriangleGeometry.hpp"
#include "../models/ModelCNV.hpp"
#include "../object/CompositeEntity.hpp"
#include "../object/SimpleEntity.hpp"
#include "../engine/Camera.hpp"
#include "../object/TestEntity.hpp"
#include "../types.hpp"

using namespace ExcellentPuppy::Engine;

// Handles keyboard input
void handleKeyboard (unsigned char, int, int);
// Handles special keyboard input
void handleSpecialKeyboard (int, int, int);
// Handle mouse movement
void handleMouseMotion(int, int);

Camera* Engine::_camera = NULL;
Camera*& Engine::getCamera() {
	return Engine::_camera;
}
void Engine::setCamera(Camera* camera) {
	Engine::_camera = camera;
}

static ExcellentPuppy::Entities::CompositeEntity* testEntity = NULL;
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
	glutCreateWindow("Rotation display");
}
void Engine::initSubsystems() {
	// TODO: init mouse
	// TODO: init texture manager
}
void Engine::initScene() {
	// Set clear color
	glClearColor(1, 1, 1, 1);

	// Some exmple entities
	// TODO: put into list
	// TODO: remove when not needed
	testEntity = ExcellentPuppy::Entities::TestEntity::testEntity();

	Engine::_camera = new Camera((GEvector){0, 0, 3}); // TODO: move this somewhere else?
	Engine::_camera->setGLProjection();

	// GL settings
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

/**#ifdef LIGHTING
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0);
#endif*/
}
void Engine::registerCallbacks() {
	glutDisplayFunc(Engine::render);
	glutKeyboardFunc(handleKeyboard);
	glutSpecialFunc(handleSpecialKeyboard);
	glutPassiveMotionFunc(handleMouseMotion);
}

void Engine::render (void) {
	// TODO: animate()
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	testEntity->render();

	glutSwapBuffers();
	glutPostRedisplay();

	// TODO: everything
}

void handleKeyboard (unsigned char key, int x, int y) {
}
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

static int lastX = -1, lastY = -1;
void handleMouseMotion (int x, int y) {
	Camera *camera = Engine::getCamera();
	if(camera != NULL){
		if(lastX != -1) {
			Engine::getCamera()->getRotationY() += x-lastX;
			Engine::getCamera()->getRotationX() -= y-lastY;

			if(Engine::getCamera()->getRotationX() < -90)
				Engine::getCamera()->getRotationX() = -90;
			if(Engine::getCamera()->getRotationX() > 90)
				Engine::getCamera()->getRotationX() = 90;
		}
		Engine::getCamera()->setGLProjection();
	}

	lastX = x;
	lastY = y;
}
