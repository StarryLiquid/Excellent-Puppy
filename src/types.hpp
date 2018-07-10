#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <GL\freeglut.h>

typedef struct {
	GLfloat u;
	GLfloat v;
} GEtexCoords;
typedef struct {
	GLclampf r;
	GLclampf g;
	GLclampf b;
	GLclampf a;
} GEcolor;
typedef struct {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} GEvec3D, GEvertex3D;

#define GE_CNV_FORMAT GL_C4F_N3F_V3F

typedef struct {
	GEcolor color;
	GEvec3D normal;
	GEvertex3D vertex;
} GEcnv;

#define GE_TRI_TYPE GL_UNSIGNED_INT
const unsigned int GE_TRI_COUNT = 3;

typedef struct {
	GLuint vert1;
	GLuint vert2;
	GLuint vert3;
} GEtriangle;

#endif /* TYPES_HPP_ */
