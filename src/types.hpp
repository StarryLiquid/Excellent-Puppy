#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <GL\freeglut.h>

struct GEtexCoords {
	GLfloat s;
	GLfloat t;
};
struct GEcolor {
	GLclampf r;
	GLclampf g;
	GLclampf b;
	GLclampf a;
};
struct GEvector {
	GLfloat x;
	GLfloat y;
	GLfloat z;

	inline GEvector& operator+=(const GEvector& rVec) {
		x += rVec.x;
		y += rVec.y;
		z += rVec.z;
		return *this;
	}
	friend GEvector operator+(GEvector lVec, const GEvector& rVec) {
		lVec += rVec;
		return lVec;
	}
	inline GEvector& operator-=(const GEvector& rVec) {
		x -= rVec.x;
		y -= rVec.y;
		z -= rVec.z;
		return *this;
	}
	friend GEvector operator-(GEvector lVec, const GEvector& rVec) {
		lVec -= rVec;
		return lVec;
	}
	inline GEvector& operator-() {
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}
	inline GEvector& operator*=(const GLfloat& scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	friend GEvector operator*(GEvector lVec, const GLfloat& scalar) {
		lVec *= scalar;
		return lVec;
	}
	inline GEvector& operator/=(const GLfloat& scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}
	friend GEvector operator/(GEvector lVec, const GLfloat& scalar) {
		lVec /= scalar;
		return lVec;
	}
};
struct GErotation {
	GLfloat degrees;
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

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
