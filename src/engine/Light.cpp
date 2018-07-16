#include "Light.hpp"

using namespace ExcellentPuppy::Engine;
		
Light::Light(
		const GLenum& name,
		const GEvector& position) :
	_name(name) {
	setPosition(position);
}
Light::~Light() { }

const GLenum& Light::getName() {
	return _name;
}
const GEvector& Light::getPosition() {
	return _position;
}
void Light::setPosition(const GEvector& position) {
	_position = position;
	GLfloat pos[4] = {_position.x, _position.y, _position.z, 1.0};
	setProperty(GL_POSITION, pos);
}
const GEcolor& ExcellentPuppy::Engine::Light::getAmbient() {
	return _ambient;
}
void ExcellentPuppy::Engine::Light::setAmbient(const GEcolor& ambient) {
	_ambient = ambient;
	setProperty(GL_AMBIENT, (GLfloat *)&_ambient);
}
const GEcolor& ExcellentPuppy::Engine::Light::getDiffuse() {
	return _diffuse;
}
void ExcellentPuppy::Engine::Light::setDiffuse(const GEcolor& diffuse) {
	_diffuse = diffuse;
	setProperty(GL_DIFFUSE, (GLfloat *)&_diffuse);
}
const GEcolor& ExcellentPuppy::Engine::Light::getSpecular() {
	return _specualr;
}
void ExcellentPuppy::Engine::Light::setSpecular(const GEcolor& specular) {
	_specualr = specular;
	setProperty(GL_SPECULAR, (GLfloat *)&_specualr);
}
const GLfloat& ExcellentPuppy::Engine::Light::getConstantAttenuation() {
	return _constantAttenuation;
}
void ExcellentPuppy::Engine::Light::setConstantAttenuation(
        const GLfloat& constantAttenuation) {
	_constantAttenuation = constantAttenuation;
	setProperty(GL_CONSTANT_ATTENUATION, &_constantAttenuation);
}
const GLfloat& ExcellentPuppy::Engine::Light::getLinearAttenuation() {
	return _linearAttenuation;
}
void ExcellentPuppy::Engine::Light::setLinearAttenuation(
        const GLfloat& linearAttenuation) {
	_linearAttenuation = linearAttenuation;
	setProperty(GL_LINEAR_ATTENUATION, &_linearAttenuation);
}
const GLfloat& ExcellentPuppy::Engine::Light::getQuadraticAttenuation() {
	return _quadraticAttenuation;
}
void ExcellentPuppy::Engine::Light::setQuadraticAttenuation(
        const GLfloat& quadraticAttenuation) {
	_quadraticAttenuation = quadraticAttenuation;
	setProperty(GL_QUADRATIC_ATTENUATION, &_quadraticAttenuation);
}
void Light::setModelProperty(const GLenum& property, const GLint* const & value) {
	glLightModeliv(property, value);
}

void Light::load() const {
	glEnable(_name);
}

void Light::setProperty(const GLenum& property, const GLfloat& value) {
	glLightf(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLfloat* const & value) {
	glLightfv(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLint& value) {
	glLighti(_name, property, value);
}
void Light::setProperty(const GLenum& property, const GLint* const & value) {
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
