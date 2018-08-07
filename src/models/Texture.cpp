#include "Texture.hpp"

#include <GL/freeglut.h>
#include "../engine/TextureLoader.hpp"

using namespace ExcellentPuppy::Modeling;
		
Texture::Texture(std::string filename, GLuint id) :
	_filename(filename),
	_id(id) { }
Texture::~Texture() { }

void Texture::loadTexture() const {
	Engine::TextureLoader::loadTexture(this);
}
void Texture::selectTexture() const {
	glBindTexture(GL_TEXTURE_2D, _id);
}
