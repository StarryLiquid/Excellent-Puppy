#include "Light.hpp"

using namespace ExcellentPuppy::Engine;
		
Light::Light(
		const GLenum& name,
		const GEvector& position) :
	_name(name),
	_position(position) { }
Light::~Light() { }

const GLenum& Light::getName() {
	return _name;
}
GEvector& Light::getPosition() {
	return _position;
}
void Light::setPosition(const GEvector& position) {
	_position = position;
}
void ExcellentPuppy::Engine::Light::setAmbient(const GEcolor& ambient) {
	setProperty(GL_AMBIENT, (GLfloat *)&ambient);
}
void ExcellentPuppy::Engine::Light::setDiffuse(const GEcolor& diffuse) {
	setProperty(GL_DIFFUSE, (GLfloat *)&diffuse);
}
void ExcellentPuppy::Engine::Light::setSpecular(const GEcolor& specular) {
	setProperty(GL_SPECULAR, (GLfloat *)&specular);
}
void ExcellentPuppy::Engine::Light::setConstantAttenuation(
        const GLfloat& constantAttenuation) {
	setProperty(GL_CONSTANT_ATTENUATION, &constantAttenuation);
}
void ExcellentPuppy::Engine::Light::setLinearAttenuation(
        const GLfloat& linearAttenuation) {
	setProperty(GL_LINEAR_ATTENUATION, &linearAttenuation);
}
void ExcellentPuppy::Engine::Light::setQuadraticAttenuation(
        const GLfloat& quadraticAttenuation) {
	setProperty(GL_QUADRATIC_ATTENUATION, &quadraticAttenuation);
}
void Light::setModelProperty(const GLenum& property, const GLint* const & value) {
	glLightModeliv(property, value);
}

void Light::load() const {
	glEnable(_name);
}
void Light::setLight() const {
	GLfloat pos[4] = {_position.x, _position.y, _position.z, 1.0};
	setProperty(GL_POSITION, pos);
}

void Light::setProperty(const GLenum& property, const GLfloat& value) const {
	glLightf(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLfloat* const & value) const {
	glLightfv(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLint& value) const {
	glLighti(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLint* const & value) const {
	glLightiv(_name, property, value);
}
void Light::setModelProperty(const GLenum& property, const GLfloat& value) {
	glLightModelf(property, value);
}
void Light::setModelProperty(const GLenum& property, const GLfloat* const & value) {
	glLightModelfv(property, value);
}
void Light::setModelProperty(const GLenum& property, const GLint& value) {
	glLightModeli(property, value);
}
