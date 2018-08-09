#include "DirectionalLight.hpp"

using namespace ExcellentPuppy::Engine;

GEvector const & DirectionalLight::getDirection() const {
	return _direction;
}
void DirectionalLight::setDirection(const GEvector& direction) {
	_direction = direction;
}

DirectionalLight::DirectionalLight(const GLenum& name,
		const GEvector& position) :
			Light(name, position) { }
DirectionalLight::~DirectionalLight() { }

void DirectionalLight::setSpotlightCutoff(const GLfloat& angle) {
	setProperty(GL_SPOT_CUTOFF, angle);
}
void DirectionalLight::setSpotlightExponent(const GLfloat& exponent) {
	setProperty(GL_SPOT_EXPONENT, exponent);
}

void DirectionalLight::setLight() const {
	Light::setLight();
	setProperty(GL_SPOT_DIRECTION, (GLfloat *)&getDirection());
}
