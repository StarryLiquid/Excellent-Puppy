#include "TextureLoader.hpp"

#include <GL/freeglut.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include "../models/Texture.hpp"


using namespace ExcellentPuppy::Engine;
		
std::unordered_set<ExcellentPuppy::Modeling::Texture*> TextureLoader::_textures;

ExcellentPuppy::Modeling::Texture* TextureLoader::createTexture(std::string fileName) {
	GLuint id;
	glGenTextures(1, &id);
	auto texture = new Modeling::Texture(fileName, id);
	_textures.insert(texture);
	return texture;
}
void TextureLoader::deleteTexture(Modeling::Texture* texture, bool deleteRef) {
	// If texture is not in the texture set, nothing to delete
	// Also removes the texture from the set
	if(_textures.erase(texture) == 1) {
		// Free the texture
		glDeleteTextures(1, &texture->_id);

		// Delete the texture
		if(deleteRef)
			delete texture;
	}
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
