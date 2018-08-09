#include "ImageModel.hpp"

using namespace ExcellentPuppy::Modeling;

#include "../Texture.hpp"

Texture const * ImageModel::getTexture() const {
	return _texture;
}

ImageModel::ImageModel(Texture const * const texture, GE2Dvector dimensions) :
		SquareModel(dimensions),
		_texture(texture) { }
ImageModel::~ImageModel() { }

void ImageModel::load() const {
	_texture->loadTexture();
}
void ImageModel::draw() const {
	_texture->selectTexture();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glTexCoord2f(0                , 1);
		glVertex2f  (0                , 0);
		glTexCoord2f(1                , 1);
		glVertex2f  (getDimensions().x, 0);
		glTexCoord2f(1                , 0);
		glVertex2f  (getDimensions().x, getDimensions().y);
		glTexCoord2f(0                , 0);
		glVertex2f  (0                , getDimensions().y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
