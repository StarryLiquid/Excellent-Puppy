#include <GL\freeglut.h>
#include "models/TriangleGeometry.hpp"
#include "models/ModelCNV.hpp"
#include "object/SimpleEntity.hpp"
#include "types.hpp"

using namespace ExcellentPuppy;

// A very small number
#define EPSILON 0.0001

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

// Renders the scene
void render (void);
// Handles keyboard input
void handleKeyboard (unsigned char, int, int);
// Handles special keyboard input
void handleSpecialKeyboard (int, int, int);
// Sets the projection
void setProjection();

void setup (int* argc, char** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Rotation display");
}

static Objects::SimpleEntity *testCubeEntity;
static Modeling::Model *testPlane;
void init (void) {
	glClearColor(1, 1, 1, 1);

	Modeling::Model *testCube = new Modeling::ModelCNV(cubeSpec,
			new Modeling::TriangleGeometry(cubeFaces,
					sizeof(cubeFaces)/sizeof(GEtriangle)));
	testCubeEntity = new Objects::SimpleEntity({0, 0, 0},  {0, 0 ,0}, testCube);
	testPlane = new Modeling::ModelCNV(planeSpec,
			new Modeling::TriangleGeometry(planeFaces,
					sizeof(planeFaces)/sizeof(GEtriangle)));

	setProjection();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1.0, -3.0,
	          0.0, 0.0,  0.0,
	          0.0, 1.0,  0.0);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glDisable(GL_CULL_FACE);
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

void registerCallbacks (void) {
	glutDisplayFunc(render);
	glutKeyboardFunc(handleKeyboard);
	glutSpecialFunc(handleSpecialKeyboard);
}

void render (void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	testPlane->render();
	testCubeEntity->render();

	glutSwapBuffers();
	glutPostRedisplay();
}

void handleKeyboard (unsigned char key, int x, int y){
	 //glutGetModifiers()
}
void handleSpecialKeyboard (int key, int x, int y){
	if(key==GLUT_KEY_UP)
		testCubeEntity->getRotation()->x += 1;
	if(key==GLUT_KEY_DOWN)
		testCubeEntity->getRotation()->x -= 1;
	if(key==GLUT_KEY_LEFT)
		testCubeEntity->getRotation()->y += 1;
	if(key==GLUT_KEY_RIGHT)
		testCubeEntity->getRotation()->y -= 1;
}

void setProjection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0,
			  -1.0, 1.0,
			   1.0, 6.0);
}

int main (int argc, char** argv) {
	setup(&argc, argv);
	init();
	registerCallbacks();

	glutMainLoop();
}
