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

#endif /* TYPES_HPP_ */
