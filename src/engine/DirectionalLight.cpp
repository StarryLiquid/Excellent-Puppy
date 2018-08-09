#include "DirectionalLight.hpp"

using namespace ExcellentPuppy::Engine;

DirectionalLight::DirectionalLight(const GLenum& name,
		const GEvector& position) :
			Light(name, position) { }
DirectionalLight::~DirectionalLight() { }

void DirectionalLight::setDirection(const GEvector& direction) {
	setProperty(GL_SPOT_DIRECTION, (GLfloat *)&direction);
}
void DirectionalLight::setSpotlightCutoff(const GLfloat& angle) {
	setProperty(GL_SPOT_CUTOFF, angle);
}
void DirectionalLight::setSpotlightExponent(const GLfloat& exponent) {
	setProperty(GL_SPOT_EXPONENT, exponent);
}
