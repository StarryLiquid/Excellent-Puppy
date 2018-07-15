#include "../entities/TestEntity.hpp"

#include "../entities/CompositeEntity.hpp"
#include "../entities/SimpleEntity.hpp"
#include "../models/ModelCNV.hpp"
#include "../models/geometries/TriangleGeometry.hpp"

using namespace ExcellentPuppy::Entities;

// A very small number
#define EPSILON 0.0001

GEcnv const cubeSpec[] = {
	{
		{ 0, 0, 1, 1 },
		{ 0-0.5, 0-0.5, 1-0.5 },
		{ 0-0.5, 0-0.5, 1-0.5 },
	},
	{
		{ 0, 1, 1, 1 },
		{ 0-0.5, 1-0.5, 1-0.5 },
		{ 0-0.5, 1-0.5, 1-0.5 },
	},
	{
		{ 0, 1, 0, 1 },
		{ 0-0.5, 1-0.5, 0-0.5 },
		{ 0-0.5, 1-0.5, 0-0.5 },
	},
	{
		{ 0, 0, 0, 1 },
		{ 0-0.5, 0-0.5, 0-0.5 },
		{ 0-0.5, 0-0.5, 0-0.5 },
	},
	{
		{ 1, 0, 1, 1 },
		{ 1-0.5, 0-0.5, 1-0.5 },
		{ 1-0.5, 0-0.5, 1-0.5 },
	},
	{
		{ 1, 1, 1, 1 },
		{ 1-0.5, 1-0.5, 1-0.5 },
		{ 1-0.5, 1-0.5, 1-0.5 },
	},
	{
		{ 1, 1, 0, 1 },
		{ 1-0.5, 1-0.5, 0-0.5 },
		{ 1-0.5, 1-0.5, 0-0.5 },
	},
	{
		{ 1, 0, 0, 1 },
		{ 1-0.5, 0-0.5, 0-0.5 },
		{ 1-0.5, 0-0.5, 0-0.5 },
	}
};
GEtriangle const cubeFaces[] = {
	{ 0, 2, 3 },
	{ 2, 0, 1 },
	{ 6, 4, 7 },
	{ 4, 6, 5 },
	{ 3, 4, 0 },
	{ 4, 3, 7 },
	{ 5, 2, 1 },
	{ 2, 5, 6 },
	{ 4, 1, 0 },
	{ 1, 4, 5 },
	{ 2, 7, 3 },
	{ 7, 2, 6 },
};
GEcnv const planeSpec[] = {
	{
		{ 1, 0, 0, 1 },
		{ 0, 1, 0 },
		{ -1.5, -EPSILON, -1.5 },
	},
	{
		{ 0, 1, 0, 1 },
		{ 0, 1, 0 },
		{ 1.5, -EPSILON, -1.5 },
	},
	{
		{ 0, 0, 1, 1 },
		{ 0, 1, 0 },
		{ 1.5, -EPSILON, 1.5 },
	},
	{
		{ 0.65, 0.25, 0.25, 1 },
		{ 0, 1, 0 },
		{ -1.5, -EPSILON, 1.5 },
	},
};
GEtriangle const planeFaces[] = {
	{ 3, 1, 0 },
	{ 1, 3 ,2 },
};

CompositeEntity* TestEntity::testEntity(const GEvector& position, const GEvector& rotation, const GEvector& scaling) {
	Modeling::Model *testCube = new Modeling::ModelCNV(cubeSpec,
			{new Modeling::TriangleGeometry(cubeFaces,
				sizeof(cubeFaces)/sizeof(GEtriangle))});
	Modeling::Model *testPlane = new Modeling::ModelCNV(planeSpec,
			{new Modeling::TriangleGeometry(planeFaces,
				sizeof(planeFaces)/sizeof(GEtriangle))});
	Entities::SimpleEntity *cubeEntity = new Entities::SimpleEntity(testCube, {0, 0.5, 0});
	Entities::SimpleEntity *planeEntity = new Entities::SimpleEntity(testPlane);
	return new CompositeEntity({cubeEntity, planeEntity}, position, rotation, scaling);
}
