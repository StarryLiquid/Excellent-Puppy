#include "Flooring.hpp"

#include "../models/ModelNV.hpp"
#include "../models/QuadGeometry.hpp"
#include "../types.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat tileDimension = 1.5;
const GLfloat indent = 0.05;
const GLfloat underColor = -0.08;
const GLfloat bottom = -0.1;

const GEnv tileSpec[] = {
	{
		{-1, 1, 1},
		{0, bottom, 0}
	},
	{
		{1, 1, 1},
		{tileDimension, bottom, 0}
	},
	{
		{1, 1, -1},
		{tileDimension, bottom, -tileDimension}
	},
	{
		{-1, 1, -1},
		{0, bottom, -tileDimension}
	},
	{
		{0, 1, 0},
		{indent, 0, -indent}
	},
	{
		{0, 1, 0},
		{tileDimension-indent, 0, -indent}
	},
	{
		{0, 1, 0},
		{tileDimension-indent, 0, -tileDimension+indent}
	},
	{
		{0, 1, 0},
		{indent, 0, -tileDimension+indent}
	},
};
const GEquad tileFaces[] = {
	{0, 4, 7, 3},
	{3, 7, 6, 2},
	{2, 6, 5, 1},
	{1, 5, 4, 0},
	{4, 5, 6, 7},
};
const GEcolor white = {0.9, 0.9, 0.9};
const GEcolor black = {0, 0, 0};
const GEcolor gray  = {0.3, 0.3, 0.3};
const GEcolor colors[] = {white, black};
const GEvector horizontalTranslate = {tileDimension, 0, 0};
const GEvector verticalTranslate = {0, 0, -tileDimension};

static const ExcellentPuppy::Modeling::ModelNV tileModel =
		ExcellentPuppy::Modeling::ModelNV(
				tileSpec,
				new ExcellentPuppy::Modeling::QuadGeometry(
						tileFaces,
						sizeof(tileFaces)/sizeof(GEquad)));
		
Flooring::Flooring(unsigned int flooringWidth, unsigned int flooringHeight, const GEvector& position, const GEvector& rotation) :
	Entity(position, rotation),
	_flooringWidth(flooringWidth),
	_flooringHeight(flooringHeight) { }
Flooring::~Flooring() { }

void Flooring::subrender() {
	int color = 0;
	glPushMatrix();
	for(int i=0; i<_flooringWidth; i++) {
		glPushMatrix();
		for(int j=0; j<_flooringHeight; j++) {
			geColor(colors[color]);
			tileModel.render();
			geTranslate(horizontalTranslate);
			color = !color;
		}
		glPopMatrix();
		geTranslate(verticalTranslate);
		if(_flooringHeight%2 == 0)
			color = !color;
	}
	glPopMatrix();
	int fWidth = tileDimension * _flooringWidth;
	int fHeight = tileDimension * _flooringHeight;
	geColor(gray);
	glBegin(GL_QUADS);
		glVertex3f(0, underColor, 0);
		glVertex3f(fWidth, underColor, 0);
		glVertex3f(fWidth, underColor, -fHeight);
		glVertex3f(0, underColor, -fHeight);
	glEnd();
}

GEvector Flooring::extent() {
	return {tileDimension * _flooringWidth, 0, -tileDimension * _flooringHeight};
}
