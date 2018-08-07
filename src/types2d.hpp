#ifndef TYPES_2D_HPP_
#define TYPES_2D_HPP_

#include <GL\freeglut.h>
#include <math.h>

#ifndef GE_PI
#define GE_PI
static const GLfloat PI = 3.141592653589793238462643383279502884197169399;
#endif

// A structure of a single 2 coordinates vector
// Represents screen coordinates from -1.0 to 1.0
struct GE2Dvector {
	GLdouble x;
	GLdouble y;

	// Addition, subtraction, negation, multiplication and division of vectors
	// ?= operators do in-place changes
	// x?y operators use ?= operators and enable a?b?c operations
	inline GE2Dvector& operator+=(const GE2Dvector& rVec) {
		x += rVec.x;
		y += rVec.y;
		return *this;
	}
	friend GE2Dvector operator+(GE2Dvector lVec, const GE2Dvector& rVec) {
		lVec += rVec;
		return lVec;
	}
	inline GE2Dvector& operator-=(const GE2Dvector& rVec) {
		x -= rVec.x;
		y -= rVec.y;
		return *this;
	}
	friend GE2Dvector operator-(GE2Dvector lVec, const GE2Dvector& rVec) {
		lVec -= rVec;
		return lVec;
	}
	inline GE2Dvector operator-() const {
		return {-x, -y};
	}
	inline GE2Dvector& operator*=(const GLdouble& scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}
	friend GE2Dvector operator*(GE2Dvector lVec, const GLdouble& scalar) {
		lVec *= scalar;
		return lVec;
	}
	inline GE2Dvector& operator/=(const GLdouble& scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}
	friend GE2Dvector operator/(GE2Dvector lVec, const GLdouble& scalar) {
		lVec /= scalar;
		return lVec;
	}
	// Rotate the vector around the Z axis
	inline GE2Dvector rotate(GLfloat angle) {
		GLfloat radAngle = angle * (2*PI/360);
		GLfloat cos = std::cos(radAngle);
		GLfloat sin = std::sin(radAngle);
		return {x*sin + y*cos, x*cos - y*sin};
	}
	// Returns the length of the vector
	inline GLfloat length() {
		return std::sqrt(x*x + y*y);
	}
};

// Calls glVertex for a given GE2DVector value
inline void geVertex(const GE2Dvector& vertex) {
	glVertex2dv((const GLdouble*) &vertex);
}
// Calls glTranslate for a given GE2DVector value
inline void geTranslate(const GE2Dvector& vec) {
	glTranslated(vec.x, vec.y, 0);
}
// Calls glRotate for a given angle
inline void geRotate(const GLdouble& angle) {
	glRotated(angle, 0, 0, 1);
}
// Calls glScale for a given scaling vector
inline void geScale(const GE2Dvector& scale) {
	glScaled(scale.x, scale.y, 1);
}

#endif /* TYPES_HPP_ */
