#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <GL\freeglut.h>
#include <math.h>

#ifndef GE_PI
#define GE_PI
static const GLfloat PI = 3.141592653589793238462643383279502884197169399;
#endif

// A structure of 2d texture coordinates
struct GEtexCoords {
	GLfloat s;
	GLfloat t;
};
// A structure of a single RGBA color
// Can be used for other 4d float colors
struct GEcolor {
	GLclampf r;
	GLclampf g;
	GLclampf b;
	GLclampf a = 1.0;
};
// A structure of a single 3 coordinates vector
// Can be used as a regular vector or vertex, with w assumed to be 1
struct GEvector {
	GLfloat x;
	GLfloat y;
	GLfloat z=0;

	// Addition, subtraction, negation, multiplication and division of vectors
	// ?= operators do in-place changes
	// x?y operators use ?= operators and enable a?b?c operations
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
	inline GEvector operator-() const {
		return {-x, -y, -z};
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
	// Rotate the vector around the X axis
	inline GEvector rotateX(GLfloat angle) {
		GLfloat radAngle = angle * (2*PI/360);
		GLfloat cos = std::cos(radAngle);
		GLfloat sin = std::sin(radAngle);
		return {x, y*cos - z*sin, y*sin + z*cos};
	}
	// Rotate the vector around the Y axis
	inline GEvector rotateY(GLfloat angle) {
		GLfloat radAngle = angle * (2*PI/360);
		GLfloat cos = std::cos(radAngle);
		GLfloat sin = std::sin(radAngle);
		return {z*cos - x*sin, y, z*sin + x*cos};
	}
	// Returns the length of the vector
	inline GLfloat length() {
		return std::sqrt(x*x + y*y + z*z);
	}
};
// A structure for a single rotation around some vector, in degrees
struct GErotation {
	GLfloat degrees;
	GEvector axle;

	// Reverse the rotation
	inline GErotation operator-() const {
		return {-degrees, axle};
	}
};

// A strcuture for selecting which light material settings to set
struct GEMaterialBitMask {
	bool ambient : 1;
	bool diffuse : 1;
	bool specular : 1;
	bool emission : 1;
	bool shininess : 1;
};
// A structure to hold material settings
struct GEMaterial {
	GEcolor ambient;
	GEcolor diffuse;
	GEcolor specular;
	GEcolor emission;
	GLfloat shininess;
	GEMaterialBitMask bitmask;
};

// Calls glTexCoord for a given GEtexCoords value
inline void geTexCoord(const GEtexCoords& coords) {
	glTexCoord2fv((const GLfloat*)&coords);
}
// Calls glColor for a given GEcolor value
inline void geColor(const GEcolor& color) {
	glEnable(GL_COLOR_MATERIAL);
	const float nilColor[4] = {0, 0, 0, 1};
	glMaterialfv(GL_FRONT, GL_EMISSION, nilColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, nilColor);
	const float shininess = 1;
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glColor4fv((const GLfloat*) &color);
}
// Calls glVertex for a given GEvector value
inline void geVertex(const GEvector& vertex) {
	glVertex3fv((const GLfloat*) &vertex);
}
// Calls glNormal for a given GEvector value
inline void geNormal(const GEvector& normal) {
	glNormal3fv((const GLfloat*) &normal);
}
// Calls glTranslate for a given GEvector value
inline void geTranslate(const GEvector& vec) {
	glTranslatef(vec.x, vec.y, vec.z);
}
// Calls glRotate for a given GErotation value
inline void geRotate(const GErotation& rotation) {
	glRotatef(rotation.degrees, rotation.axle.x, rotation.axle.y, rotation.axle.z);
}
// Calls glScale for a given scaling vector
inline void geScale(const GEvector& scale) {
	glScalef(scale.x, scale.y, scale.z);
}
// Calls glMaterial for each material parameter
inline void geMaterial(const GEMaterial& material) {
	if(material.bitmask.ambient || material.bitmask.diffuse) {
		glDisable(GL_COLOR_MATERIAL);
		if(material.bitmask.ambient)
			glMaterialfv(GL_FRONT, GL_AMBIENT , (const GLfloat*)&material.ambient);
		if(material.bitmask.diffuse)
			glMaterialfv(GL_FRONT, GL_DIFFUSE , (const GLfloat*)&material.diffuse);
	}
	if(material.bitmask.specular)
		glMaterialfv(GL_FRONT, GL_SPECULAR , (const GLfloat*)&material.specular);
	if(material.bitmask.emission)
		glMaterialfv(GL_FRONT, GL_EMISSION, (const GLfloat*)&material.emission);
	if(material.bitmask.shininess)
		glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
	// TODO: default params
}
// Reverses the front faces clock order
inline void geSwitchFrontFace() {
	GLint currentMode;
	glGetIntegerv(GL_FRONT_FACE, &currentMode);
	if(currentMode == GL_CCW)
		currentMode = GL_CW;
	else
		currentMode = GL_CCW;
	glFrontFace(currentMode);
}

#endif /* TYPES_HPP_ */
