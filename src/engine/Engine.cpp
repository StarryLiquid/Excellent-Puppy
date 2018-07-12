#include "Engine.hpp"

#include <GL/freeglut.h>
#include "../models/TriangleGeometry.hpp"
#include "../models/ModelCNV.hpp"
#include "../object/CompositeEntity.hpp"
#include "../object/SimpleEntity.hpp"
#include "../engine/Camera.hpp"
#include "../types.hpp"

using namespace ExcellentPuppy::Engine;

// A very small number
#define EPSILON 0.0001

// Handles keyboard input
void handleKeyboard (unsigned char, int, int);
// Handles special keyboard input
void handleSpecialKeyboard (int, int, int);
// Handle mouse movement
void handleMouseMotion(int, int);

GEcnv const cubeSpec[] = {
	{
		{ 0, 0, 1, 1 },
		{ 0-0.5, 0-0.5, 1-0.5 },
		{ 0-0.5, 0-0.5, 1-0.5 },
	},
	{
		{ 0, 1, 1, 1 },
		{ 0-0.5, 1-0.5, 1-0.5 },
		{ 0-0.5, 1-0.5, 1-0.5 },
	},
	{
		{ 0, 1, 0, 1 },
		{ 0-0.5, 1-0.5, 0-0.5 },
		{ 0-0.5, 1-0.5, 0-0.5 },
	},
	{
		{ 0, 0, 0, 1 },
		{ 0-0.5, 0-0.5, 0-0.5 },
		{ 0-0.5, 0-0.5, 0-0.5 },
	},
	{
		{ 1, 0, 1, 1 },
		{ 1-0.5, 0-0.5, 1-0.5 },
		{ 1-0.5, 0-0.5, 1-0.5 },
	},
	{
		{ 1, 1, 1, 1 },
		{ 1-0.5, 1-0.5, 1-0.5 },
		{ 1-0.5, 1-0.5, 1-0.5 },
	},
	{
		{ 1, 1, 0, 1 },
		{ 1-0.5, 1-0.5, 0-0.5 },
		{ 1-0.5, 1-0.5, 0-0.5 },
	},
	{
		{ 1, 0, 0, 1 },
		{ 1-0.5, 0-0.5, 0-0.5 },
		{ 1-0.5, 0-0.5, 0-0.5 },
	}
};
GEtriangle const cubeFaces[] = {
	{ 0, 2, 3 },
	{ 2, 0, 1 },
	{ 6, 4, 7 },
	{ 4, 6, 5 },
	{ 3, 4, 0 },
	{ 4, 3, 7 },
	{ 5, 2, 1 },
	{ 2, 5, 6 },
	{ 4, 1, 0 },
	{ 1, 4, 5 },
	{ 2, 7, 3 },
	{ 7, 2, 6 },
};
GEcnv const planeSpec[] = {
	{
		{ 1, 0, 0, 1 },
		{ 0, 1, 0 },
		{ -1.5, -EPSILON, -1.5 },
	},
	{
		{ 0, 1, 0, 1 },
		{ 0, 1, 0 },
		{ 1.5, -EPSILON, -1.5 },
	},
	{
		{ 0, 0, 1, 1 },
		{ 0, 1, 0 },
		{ 1.5, -EPSILON, 1.5 },
	},
	{
		{ 0.65, 0.25, 0.25, 1 },
		{ 0, 1, 0 },
		{ -1.5, -EPSILON, 1.5 },
	},
};
GEtriangle const planeFaces[] = {
	{ 3, 1, 0 },
	{ 1, 3 ,2 },
};

Camera* Engine::_camera = NULL;
Camera*& Engine::getCamera() {
	return Engine::_camera;
}
void Engine::setCamera(Camera* camera) {
	Engine::_camera = camera;
}

static ExcellentPuppy::Objects::Entity *testEntity;
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

	// Some exmple models
	// TODO: put into list
	Modeling::Model *testCube = new Modeling::ModelCNV(cubeSpec,
			new Modeling::TriangleGeometry(cubeFaces,
				sizeof(cubeFaces)/sizeof(GEtriangle)));
	Modeling::Model *testPlane = new Modeling::ModelCNV(planeSpec,
			new Modeling::TriangleGeometry(planeFaces,
				sizeof(planeFaces)/sizeof(GEtriangle)));
	Objects::SimpleEntity *cubeEntity = new Objects::SimpleEntity({0, 0.5, 0},  {0, 0 ,0}, testCube);
	Objects::SimpleEntity *planeEntity = new Objects::SimpleEntity({0, 0, 0},  {0, 0 ,0}, testPlane);
	testEntity = new Objects::CompositeEntity({0, 0, 0},  {0, 0 ,0}, {cubeEntity, planeEntity});

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
