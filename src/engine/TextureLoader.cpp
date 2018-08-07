#include "TextureLoader.hpp"

#include <GL/freeglut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include "../models/Texture.hpp"

#include <iostream> //TODO remove

using namespace ExcellentPuppy::Engine;
		
std::list<ExcellentPuppy::Modeling::Texture*> TextureLoader::_textures;

ExcellentPuppy::Modeling::Texture* TextureLoader::createTexture(std::string fileName) {
	GLuint id;
	glGenTextures(1, &id);
	return new Modeling::Texture(fileName, id);
}
void TextureLoader::loadTexture(Modeling::Texture const * texture) {
	if(!texture->_isLoaded) {
		texture->selectTexture();
		int width, height, n;
		unsigned char *data = stbi_load(texture->_filename.c_str(), &width, &height, &n, 0);
		if(data != NULL) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			texture->selectTexture();
			stbi_image_free(data);

			texture->_isLoaded = true;
		}
		else {
			std::cerr << "Can not load texture " << texture->_filename << std::endl;
		}
	}
}
void TextureLoader::loadTextures() {
	for(auto texture : _textures)
		loadTexture(texture);
}
