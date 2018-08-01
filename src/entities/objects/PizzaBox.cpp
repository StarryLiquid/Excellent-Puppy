#include "PizzaBox.hpp"

#include "../SimpleEntity.hpp"
#include "../../models/ModelTNV.hpp"
#include "../../models/geometries/QuadGeometry.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat BOX_DIMENSION = 1.5;
const GLfloat BOX_HEIGHT = 0.3;
const GLfloat SIDE_THICKNESS = 0.025*3;
const GLfloat BACK_SIDE_THICKNESS = SIDE_THICKNESS/2;

const GLfloat UV_SQUARE_DIMENSION = 0.25;

const GEtnv BOX_SPECS[] = {
	{ // 0 - Bottom plane
		{0.5 + UV_SQUARE_DIMENSION/2 * 3, UV_SQUARE_DIMENSION},
		{0, -1, 0},
		{-BOX_DIMENSION/2, 0.0, -BOX_DIMENSION/2},
	},
	{ // 1
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION},
		{0, -1, 0},
		{BOX_DIMENSION/2, 0.0, -BOX_DIMENSION/2},
	},
	{ // 2
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 2},
		{0, -1, 0},
		{BOX_DIMENSION/2, 0.0, BOX_DIMENSION/2},
	},
	{ // 3
		{0.5 + UV_SQUARE_DIMENSION/2 * 3, UV_SQUARE_DIMENSION * 2},
		{0, -1, 0},
		{-BOX_DIMENSION/2, 0.0, BOX_DIMENSION/2},
	},
	{ // 4 - Top plane
		{0.5 - UV_SQUARE_DIMENSION/2 * 3, UV_SQUARE_DIMENSION},
		{0, 1, 0},
		{-BOX_DIMENSION/2, BOX_HEIGHT, -BOX_DIMENSION/2},
	},
	{ // 5
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION},
		{0, 1, 0},
		{BOX_DIMENSION/2, BOX_HEIGHT, -BOX_DIMENSION/2},
	},
	{ // 6
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION*2},
		{0, 1, 0},
		{BOX_DIMENSION/2, BOX_HEIGHT, BOX_DIMENSION/2},
	},
	{ // 7
		{0.5 - UV_SQUARE_DIMENSION/2 * 3, UV_SQUARE_DIMENSION*2},
		{0, 1, 0},
		{-BOX_DIMENSION/2, BOX_HEIGHT, BOX_DIMENSION/2},
	},
	{ // 8 - Inner top plane
		{0.5 - (3.0/2 - SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (1 + BACK_SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{1, 3, 1},
		{-(BOX_DIMENSION/2 - BACK_SIDE_THICKNESS), BOX_HEIGHT, -(BOX_DIMENSION/2 - BACK_SIDE_THICKNESS)},
	},
	{ // 9
		{0.5 - (1.0/2 + SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (1 + BACK_SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{-1, 3, 1},
		{(BOX_DIMENSION/2 - SIDE_THICKNESS), BOX_HEIGHT, -(BOX_DIMENSION/2 - BACK_SIDE_THICKNESS)},
	},
	{ // 10
		{0.5 - (1.0/2 + SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (2 - SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{-1, 3, -1},
		{(BOX_DIMENSION/2 - SIDE_THICKNESS), BOX_HEIGHT, (BOX_DIMENSION/2 - SIDE_THICKNESS)},
	},
	{ // 11
		{0.5 - (3.0/2 - SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (2 - SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{1, 3, -1},
		{-(BOX_DIMENSION/2 - SIDE_THICKNESS), BOX_HEIGHT, (BOX_DIMENSION/2 - SIDE_THICKNESS)},
	},
	{ // 12 - Inner bottom
		{0.5 - (3.0/2 - SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (1 + BACK_SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{1, 1, 1},
		{-(BOX_DIMENSION/2 - SIDE_THICKNESS), SIDE_THICKNESS, -(BOX_DIMENSION/2 - BACK_SIDE_THICKNESS)},
	},
	{ // 13
		{0.5 - (1.0/2 + SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (1 + BACK_SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{-1, 1, 1},
		{(BOX_DIMENSION/2 - SIDE_THICKNESS), SIDE_THICKNESS, -(BOX_DIMENSION/2 - BACK_SIDE_THICKNESS)},
	},
	{ // 14
		{0.5 - (1.0/2 + SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (2 - SIDE_THICKNESS/BOX_DIMENSION) * UV_SQUARE_DIMENSION},
		{-1, 1, -1},
		{(BOX_DIMENSION/2 - SIDE_THICKNESS), SIDE_THICKNESS, (BOX_DIMENSION/2 - SIDE_THICKNESS)},
	},
	{ // 15
		{0.5 - (3.0/2 - SIDE_THICKNESS/BOX_DIMENSION)*UV_SQUARE_DIMENSION, (2 - SIDE_THICKNESS) * UV_SQUARE_DIMENSION/BOX_DIMENSION},
		{1, 1, -1},
		{-(BOX_DIMENSION/2 - SIDE_THICKNESS), SIDE_THICKNESS, (BOX_DIMENSION/2 - SIDE_THICKNESS)},
	},
	{ // 16 - Bottom plane perimeter - for sides
		{0.5 - UV_SQUARE_DIMENSION/2, 0},
		{-1, 0, -1},
		{-BOX_DIMENSION/2, 0.0, -BOX_DIMENSION/2},
	},
	{ // 17
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION},
		{1, 0, -1},
		{BOX_DIMENSION/2, 0.0, -BOX_DIMENSION/2},
	},
	{ // 18
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 2},
		{1, 0, 1},
		{BOX_DIMENSION/2, 0.0, BOX_DIMENSION/2},
	},
	{ // 19
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 3},
		{-1, 0, 1},
		{-BOX_DIMENSION/2, 0.0, BOX_DIMENSION/2},
	},
	{ // 20
		{0.5 - UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 4},
		{-1, 0, 1},
		{-BOX_DIMENSION/2, 0.0, -BOX_DIMENSION/2},
	},
	{ // 21 - Top plane perimeter - for sides
		{0.5 + UV_SQUARE_DIMENSION/2, 0},
		{-1, 0, -1},
		{-BOX_DIMENSION/2, BOX_HEIGHT, -BOX_DIMENSION/2},
	},
	{ // 22
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION},
		{1, 0, -1},
		{BOX_DIMENSION/2, BOX_HEIGHT, -BOX_DIMENSION/2},
	},
	{ // 23
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 2},
		{1, 0, 1},
		{BOX_DIMENSION/2, BOX_HEIGHT, BOX_DIMENSION/2},
	},
	{ // 24
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 3},
		{-1, 0, 1},
		{-BOX_DIMENSION/2, BOX_HEIGHT, BOX_DIMENSION/2},
	},
	{ // 25
		{0.5 + UV_SQUARE_DIMENSION/2, UV_SQUARE_DIMENSION * 4},
		{-1, 0, 1},
		{-BOX_DIMENSION/2, BOX_HEIGHT, -BOX_DIMENSION/2},
	},
};
const GEquad BOX_FACES[] = {
	{0,  1,    2,    3},    // Pizza box bottom
	{5,  4,    4+4,  5+4},  // Pizza box top plane part 1
	{6,  5,    5+4,  6+4},  // Pizza box top plane part 2
	{7,  6,    6+4,  7+4},  // Pizza box top plane part 3
	{4,  7,    7+4,  4+4},  // Pizza box top plane part 4
	{9,  8,    8+4,  9+4},  // Pizza box inner side 1
	{10, 9,    9+4,  10+4}, // Pizza box inner side 2
	{11, 10,   10+4, 11+4}, // Pizza box inner side 3
	{8,  11,   11+4, 8+4},  // Pizza box inner side 4
	{15, 14,   13,   12},   // Pizza box inner bottom
	{16, 16+5, 17+5, 17},   // Pizza box side 1
	{17, 17+5, 18+5, 18},   // Pizza box side 1
	{18, 18+5, 19+5, 19},   // Pizza box side 1
	{19, 19+5, 20+5, 20},   // Pizza box side 1
};

Entity* ExcellentPuppy::Entities::createPizzaBox(Modeling::Texture *texture) {
	auto model = new ExcellentPuppy::Modeling::ModelTNV(texture, BOX_SPECS, {new ExcellentPuppy::Modeling::QuadGeometry(BOX_FACES, sizeof(BOX_FACES)/sizeof(GEquad))});
	auto entity = new ExcellentPuppy::Entities::SimpleEntity(model);
	entity->setCollisionRadius(std::sqrt(BOX_DIMENSION*BOX_DIMENSION/2));
	return entity;
}
