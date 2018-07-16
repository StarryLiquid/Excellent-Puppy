#include "../entities/Flooring.hpp"

#include "../models/ModelNV.hpp"
#include "../models/geometries/QuadGeometry.hpp"
#include "../types.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat Flooring::tileDimension = 2.0;
const GLfloat Flooring::indent = 0.05;
const GLfloat Flooring::underColor = -0.08;
const GLfloat Flooring::bottom = -0.1;

// The NV array of a single tile
const GEnv tileSpec[] = {
	{
		{-1, 1, 1},
		{0, Flooring::bottom, 0}
	},
	{
		{1, 1, 1},
		{Flooring::tileDimension, Flooring::bottom, 0}
	},
	{
		{1, 1, -1},
		{Flooring::tileDimension, Flooring::bottom, -Flooring::tileDimension}
	},
	{
		{-1, 1, -1},
		{0, Flooring::bottom, -Flooring::tileDimension}
	},
	{
		{0, 1, 0},
		{Flooring::indent, 0, -Flooring::indent}
	},
	{
		{0, 1, 0},
		{Flooring::tileDimension-Flooring::indent, 0, -Flooring::indent}
	},
	{
		{0, 1, 0},
		{Flooring::tileDimension-Flooring::indent, 0, -Flooring::tileDimension+Flooring::indent}
	},
	{
		{0, 1, 0},
		{Flooring::indent, 0, -Flooring::tileDimension+Flooring::indent}
	},
};
// The faces of a single tile
const GEquad tileFaces[] = {
	{0, 4, 7, 3},
	{3, 7, 6, 2},
	{2, 6, 5, 1},
	{1, 5, 4, 0},
	{4, 5, 6, 7},
};
// The colors of the tiles
const GEcolor white = {0.9, 0.9, 0.9};
const GEcolor black = {0, 0, 0};
// Material for the tiles
GEMaterial tileMaterial = {{}, {}, {1, 1, 1}, {}, 128, {0, 0, 1, 0, 1}};
// The in-between color
const GEcolor gray  = {0.3, 0.3, 0.3};
// A helper array for alternating colors
const GEcolor *colors[] = {&white, &black};
// A helper vector for iterating horizontally over tiles
const GEvector horizontalTranslate = {Flooring::tileDimension, 0, 0};
// A helper vector for iterating vertically over tiles
const GEvector verticalTranslate = {0, 0, -Flooring::tileDimension};

// A const model of a tile, without color
static bool tileModelLoaded = false;
static const ExcellentPuppy::Modeling::ModelNV tileModel =
		ExcellentPuppy::Modeling::ModelNV(
				tileSpec,
				{new ExcellentPuppy::Modeling::QuadGeometry(
						tileFaces,
						sizeof(tileFaces)/sizeof(GEquad))});

Flooring::Flooring(unsigned int flooringWidth, unsigned int flooringHeight, const GEvector& position, const GEvector& rotation, const GEvector& scaling) :
	Entity(position, rotation, scaling),
	_flooringWidth(flooringWidth),
	_flooringHeight(flooringHeight) { }
Flooring::~Flooring() { }

void Flooring::load() {
	if(!tileModelLoaded) {
		tileModel.load();
		tileModelLoaded = true;
	}
}
void Flooring::subrender() {
	int color = 0;
	// Iterate vertically and horizontally to render the tiles
	glPushMatrix();
	for(int i=0; i<_flooringWidth; i++) {
		glPushMatrix();
		for(int j=0; j<_flooringHeight; j++) {
			// Render the current tile
			geColor(*colors[color]);
			geMaterial(tileMaterial);
			tileModel.render();
			// Move to next tile
			geTranslate(verticalTranslate);
			color = !color;
		}
		glPopMatrix();
		// Move to next column
		geTranslate(horizontalTranslate);
		// Switch color
		if(_flooringHeight%2 == 0)
			color = !color;
	}
	glPopMatrix();
	// Render a plane right under the top of tiles to have a color between tiles
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
