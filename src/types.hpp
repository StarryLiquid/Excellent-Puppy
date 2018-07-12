#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <GL\freeglut.h>

typedef struct {
	GLfloat s;
	GLfloat t;
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
} GEvector;
typedef struct {
	GLfloat degrees;
	GLfloat x;
	GLfloat y;
	GLfloat z;
} GErotation;

inline void geTexCoord(const GEtexCoords& coords) {
	glTexCoord2f(coords.s, coords.t);
}
inline void geColor(const GEcolor& color) {
	glColor3f(color.r, color.g, color.b);
}
inline void geVertex(const GEvector& vertex) {
	glVertex3fv((const float *) &vertex);
}
inline void geTranslate(const GEvector& vec) {
	glTranslated(vec.x, vec.y, vec.z);
}
inline void geRotate(const GErotation& rotation) {
	glRotatef(rotation.degrees, rotation.x, rotation.y, rotation.z);
}

#endif /* TYPES_HPP_ */
