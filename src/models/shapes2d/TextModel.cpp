#include "TextModel.hpp"

using namespace ExcellentPuppy::Modeling;

#define GE_FONT GLUT_STROKE_ROMAN

std::string TextModel::getText() {
	return _text;
}
void TextModel::setText(std::string text) {
	_text = text;
	calculateDimesnsions();
}
GE2Dvector const & TextModel::getDimensions() const {
	return _calculatedDimensions;
}

TextModel::TextModel(std::string text) {
	setText(text);
}
TextModel::~TextModel() { }

void TextModel::load() const { }
void TextModel::draw() const {
	glPushMatrix();
	for(auto character : _text)
		glutStrokeCharacter(GE_FONT, character);
	glPopMatrix();
}
void TextModel::calculateDimesnsions() {
	_calculatedDimensions = (GE2Dvector){glutStrokeLengthf(GE_FONT, (unsigned char*)_text.c_str()), glutStrokeHeight(GE_FONT)};
}
