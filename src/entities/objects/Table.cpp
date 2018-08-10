#include "Table.hpp"

#include "../../models/shapes/CubeModel.hpp"
#include "../SimpleEntity.hpp"

using namespace ExcellentPuppy::Entities;

const GLfloat Table::TABLE_TOP_WIDTH = 0.1;
const GLfloat Table::TABLE_LEG_WIDTH = 0.2;
const GLfloat Table::TABLE_LEG_HEIGHT = 3.0;
const GLfloat Table::TABLE_WIDTH = 3.2;
const GLfloat Table::TABLE_DEPTH = 4.0;
const GLfloat Table::TABLE_HEIGHT = TABLE_TOP_WIDTH + TABLE_LEG_HEIGHT;
const GLfloat Table::LEG_COLLISION_RADIUS = std::sqrt(TABLE_LEG_WIDTH*TABLE_LEG_WIDTH*2);

std::list<Entity*> const & Table::getTableLegs() {
	return _tableLegs;
}

Table::Table(Modeling::Material* tableMaterial,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
		CompositeEntity({}, position, rotation, scaling) {
	auto tableTopModel = new Modeling::CubeModel(
			{TABLE_WIDTH, TABLE_TOP_WIDTH, TABLE_DEPTH},
			{tableMaterial, tableMaterial, tableMaterial, tableMaterial ,tableMaterial ,tableMaterial},
			false);
	auto tableLegModel = new Modeling::CubeModel(
			{TABLE_LEG_WIDTH, TABLE_LEG_HEIGHT, TABLE_LEG_WIDTH},
			{tableMaterial, NULL, tableMaterial, tableMaterial ,tableMaterial ,tableMaterial},
			false);
	getDependents()->insert(tableTopModel);
	getDependents()->insert(tableLegModel);

	// Left near leg
	auto tableLeg1 = new SimpleEntity(tableLegModel, {-TABLE_WIDTH/2, 0, TABLE_DEPTH/2});
	_tableLegs.push_back(tableLeg1);
	// Left far leg
	auto tableLeg2 = new SimpleEntity(tableLegModel, {-TABLE_WIDTH/2, 0, -(TABLE_DEPTH/2 - TABLE_LEG_WIDTH)});
	_tableLegs.push_back(tableLeg2);
	// Right far leg
	auto tableLeg3 = new SimpleEntity(tableLegModel, {(TABLE_WIDTH/2 - TABLE_LEG_WIDTH), 0, -(TABLE_DEPTH/2 - TABLE_LEG_WIDTH)});
	_tableLegs.push_back(tableLeg3);
	// Right near leg
	auto tableLeg4 = new SimpleEntity(tableLegModel, {(TABLE_WIDTH/2 - TABLE_LEG_WIDTH), 0, TABLE_DEPTH/2});
	_tableLegs.push_back(tableLeg4);
	for(auto leg : _tableLegs) {
		leg->setCollisionRadius(LEG_COLLISION_RADIUS);
		getEntities().push_back(leg);
		getDependents()->insert(leg);
	}

	// The top part of the table
	auto tableTop = new SimpleEntity(tableTopModel, {-TABLE_WIDTH/2, TABLE_LEG_HEIGHT, TABLE_DEPTH/2});
	getEntities().push_back(tableTop);
	getDependents()->insert(tableTop);
}
Table::~Table() { }
