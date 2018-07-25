#include "FootFrame.hpp"

#include "../geometries/Geometry.hpp"
#include "../geometries/FanGeometry.hpp"
#include "../geometries/QuadGeometry.hpp"
#include "../geometries/TriangleGeometry.hpp"
#include "../geometries/CompositeGeometry.hpp"
#include "../geometries/ScaleGeometry.hpp"
#include "../geometries/TranslateGeometry.hpp"

using namespace ExcellentPuppy::Modeling;

const GEnv footVertex[] = {
	{ // Paw base mid point								// 0
		{0, -1, 1},
		{0, FootFrame::FEET_CURVE_HEIGHT, 0}
	},
	{ // Start paw curve
		{0, -1, 1},
		{-0.4, FootFrame::FEET_CURVE_HEIGHT, 0}
	},
	{
		{-0.3, -1, 0.2},
		{-0.47, FootFrame::FEET_CURVE_HEIGHT, -0.07}
	},
	{ // Reach first toe curve
		{-1, -1, 0},
		{-0.6, FootFrame::FEET_CURVE_HEIGHT, -0.7}
	},
	{
		{-1, -1, -1},
		{-0.55, FootFrame::FEET_CURVE_HEIGHT, -0.9}
	},
	{													// 5
		{0, -1, -1},
		{-0.48, FootFrame::FEET_CURVE_HEIGHT, -0.95}
	},
	{
		{0.1, -1, -1},
		{-0.39, FootFrame::FEET_CURVE_HEIGHT, -0.94}
	},
	{ // Reach second toe curve
		{-1, -1, -1},
		{-0.305, FootFrame::FEET_CURVE_HEIGHT, -0.9}
	},
	{
		{-1, -1, -0.7},
		{-0.31, FootFrame::FEET_CURVE_HEIGHT, -1.1}
	},
	{
		{-0.7, -1, -1},
		{-0.26, FootFrame::FEET_CURVE_HEIGHT, -1.25}
	},
	{													// 10
		{0, -1, -1},
		{-0.11, FootFrame::FEET_CURVE_HEIGHT, -1.3}
	},
	{ // End toe curve
		{0, -1, 0},
		{0, FootFrame::FEET_CURVE_HEIGHT, -1.2}
	},
	{ // Paw base mid point - INNER
		{0, -1, 0},
		{0, 0, -0.1}
	},
	{ // Start paw curve - INNER
		{0, -1, 0},
		{-0.4, 0, -0.1}
	},
	{ // Reach first toe curve - INNER
		{0, -1, 0},
		{-0.55, 0, -0.7}
	},
	{													// 15
		{0, -1, 0},
		{-0.5, 0, -0.81}
	},
	{
		{0, -1, 0},
		{-0.45, 0, -0.82}
	},
	{
		{0, -1, 0},
		{-0.35, 0, -0.82}
	},
	{ // Reach second toe curve - INNER
		{0, -1, 0},
		{-0.25, 0, -0.85}
	},
	{
		{0, -1, 0},
		{-0.25, 0, -1.05}
	},
	{													// 20
		{0, -1, 0},
		{-0.2, 0, -1.15}
	},
	{
		{0, -1, 0},
		{-0.13, 0, -1.13}
	},
	{
		{0, -1, 0},
		{0, 0, -1.1}
	},
	{ // The higher ends of the foot wall
		{0, 0, 1},
		{0, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, 0}
	},
	{
		{0, 0, 1},
		{-0.4, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, 0}
	},
	{													// 25
		{-0.3, 0, 0.2},
		{-0.47, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.07}
	},
	{
		{-1, 0, 0},
		{-0.6, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.7}
	},
	{
		{-1, 0, -1},
		{-0.55, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.9}
	},
	{
		{0, 0, -1},
		{-0.48, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.95}
	},
	{
		{0.1, 0, -1},
		{-0.39, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.94}
	},
	{													// 30
		{-1, 0, -1},
		{-0.305, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -0.9}
	},
	{
		{-1, 0, -0.7},
		{-0.31, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -1.1}
	},
	{
		{-0.7, 0, -1},
		{-0.26, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -1.25}
	},
	{
		{0, 0, -1},
		{-0.11, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -1.3}
	},
	{
		{0, 0, 0},
		{0, FootFrame::FEET_CURVE_HEIGHT+FootFrame::FEET_WALL_HEIGHT, -1.2}
	},
};
const GEfan footPawIndices = {
		new GLuint[11] {12,13,14,15,16,17,18,19,20,21,22},
		11
};
const GEquad footWallIndices[] = {
		{1,   0,  0+23,  1+23},
		{2,   1,  1+23,  2+23},
		{3,   2,  2+23,  3+23},
		{4,   3,  3+23,  4+23},
		{5,   4,  4+23,  5+23},
		{6,   5,  5+23,  6+23},
		{7,   6,  6+23,  7+23},
		{8,   7,  7+23,  8+23},
		{9,   8,  8+23,  9+23},
		{10,  9,  9+23, 10+23},
		{11, 10, 10+23, 11+23},
};
const GEquad footBezelQuads[] = {
		{0,   1, 13, 12},
		{2,   3, 14, 13},
		{3,   4, 15, 14},
		{4,   5, 16, 15},
		{5,   6, 17, 16},
		{6,   7, 18, 17},
		{7,   8, 19, 18},
		{8,   9, 20, 19},
		{9,  10, 21, 20},
		{10, 11, 22, 21},
};
const GEtriangle footBezelTriangles[] = {
		{1, 2, 13},
};
		
FootFrame::FootFrame(const GEnv* specs,
		std::list<Geometry*> geometries,
		std::list<Geometry*> geometriesToDelete) :
				ModelNV(specs, geometries),
				_geometriesToDelete(geometriesToDelete) { }
FootFrame::~FootFrame() {
	for(const Geometry *geometry : _geometriesToDelete)
		delete(geometry);
}

FootFrame* FootFrame::create() {
	// The base paw geometries
	Geometry *pawFlatGeometry = new FanGeometry(&footPawIndices);
	// The quads of the bezel
	Geometry *pawBezelQuads = new QuadGeometry(footBezelQuads, sizeof(footBezelQuads)/sizeof(GEquad));
	// The triangles of the bezel
	Geometry *pawBezelTriangles = new TriangleGeometry(footBezelTriangles, sizeof(footBezelTriangles)/sizeof(GEtriangle));
	// Half the geometry of the paw
	Geometry *pawGeometry = new CompositeGeometry({pawFlatGeometry, pawBezelQuads, pawBezelTriangles});
	// The upper half of the
	Geometry *pawReverseGeometry = new ScaleGeometry(pawGeometry, {1, -1, 1});
	Geometry *pawTranslateGeometry = new TranslateGeometry(pawReverseGeometry, {0, FEET_HEIGHT, 0});
	// Wall around the foot
	Geometry *footWall = new QuadGeometry(footWallIndices, sizeof(footWallIndices)/sizeof(GEquad));
	// Half the entire geometry of the foot
	Geometry *footHalfGeometry = new CompositeGeometry({pawGeometry, footWall, pawTranslateGeometry});
	// The other half of the paw geometry
	Geometry *footReverseGeometry = new ScaleGeometry(footHalfGeometry, {-1, 1, 1}, true);
	return new FootFrame(footVertex,
			{footHalfGeometry, footReverseGeometry},
			{pawFlatGeometry, pawBezelQuads, pawBezelTriangles, pawGeometry, footWall, pawTranslateGeometry, pawReverseGeometry, footHalfGeometry, footReverseGeometry});
}
