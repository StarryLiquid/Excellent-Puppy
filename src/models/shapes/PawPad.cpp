#include "PawPad.hpp"

#include "../geometries/Geometry.hpp"
#include "../geometries/FanGeometry.hpp"
#include "../geometries/QuadGeometry.hpp"
#include "../geometries/TriangleGeometry.hpp"
#include "../geometries/CompositeGeometry.hpp"
#include "../geometries/ScaleGeometry.hpp"
#include <math.h>

using namespace ExcellentPuppy::Modeling;

const GLfloat PI = 3.141592653589793238462643383279502884197169399;
const GEnv padVertex[] = {
	{	// Paw pad base mid point							// 0
		{0, -1, 1},
		{0, 0, -0.12}
	},
	{	// Start curve
		{0, -1, 1},
		{-0.3, 0, -0.12}
	},
	{
		{(GLfloat)(std::cos(PI*(1.5 - 1./6))), -1, (GLfloat)(std::sin(PI*(1.5 - 1./6)))},
		{-0.3F + (GLfloat)(std::cos(PI*(1.5 - 1./6))*0.1), 0, -0.12F - (GLfloat)(std::sin(PI*(1.5 - 1./6))*0.1) - 0.1F}
	},
	{
		{(GLfloat)(std::cos(PI*(1.5 - 2./6))), -1, (GLfloat)(std::sin(PI*(1.5 - 2./6)))},
		{-0.3F + (GLfloat)(std::cos(PI*(1.5 - 2./6))*0.1), 0, -0.12F - (GLfloat)(std::sin(PI*(1.5 - 2./6))*0.1) - 0.1F}
	},
	{
		{-1, -1, 0},
		{-0.3 - 0.1, 0, -0.12 - 0.1}
	},
	{	// Curve back and upwards							// 5
		{-1, -1, 0},
		{-0.35, 0, -0.33}
	},
	{
		{-1, -1, -1},
		{-0.3, 0, -0.42}
	},
	{
		{-1, -1, -1},
		{-0.2, 0, -0.54}
	},
	{
		{-1, -1, -0.75},
		{-0.11, 0, -0.69}
	},
	{
		{-0.25, -1, -1},
		{-0.07, 0, -0.74}
	},
	{	// End half curve at top midpoint					// 10
		{0, -1, -1},
		{-0, 0, -0.78}
	},
	{	// Paw pad base mid point - INNER
		{0, -1, 0},
		{0, -PawPad::PAD_HEIGHT, -0.2}
	},
	{	// Curve focal point - INNER
		{0, -1, 0},
		{-0.3, -PawPad::PAD_HEIGHT, -0.22}
	},
	{	// Curve back and upwards - INNER
		{0, -1, 0},
		{-0.3, -PawPad::PAD_HEIGHT, -0.31}
	},
	{
		{0, -1, 0},
		{-0.23, -PawPad::PAD_HEIGHT, -0.4}
	},
	{														// 15
		{0, -1, 0},
		{-0.13, -PawPad::PAD_HEIGHT, -0.51}
	},
	{
		{0, -1, 0},
		{-0.07, -PawPad::PAD_HEIGHT, -0.625}
	},
	{	// End half curve at top midpoint - INNER
		{0, -1, 0},
		{-0, -PawPad::PAD_HEIGHT, -0.68}
	},
};
const GEfan padInnerIndices = {
		new GLuint[7] {11, 12, 13, 14, 15, 16, 17},
		7
};
const GEquad padBezelQuads[] = {
		{0, 1, 12, 11},
		{4, 5, 13, 12},
		{5, 6, 14, 13},
		{6, 7, 15, 14},
		{7, 8, 16, 15},
		{8, 9, 17, 16},
};
const GEtriangle padBezelTriangles[] = {
		{1, 2, 12},
		{2, 3, 12},
		{3, 4, 12},
		{9, 10, 17},
};
		
PawPad::PawPad(const GEnv* specs,
		std::list<Geometry*> geometries,
		std::list<Geometry*> geometriesToDelete) :
						ModelNV(specs, geometries),
						_geometriesToDelete(geometriesToDelete) { }
PawPad::~PawPad() {
	for(const Geometry *geometry : _geometriesToDelete)
		delete(geometry);
}

PawPad* PawPad::create() {
	// The inner paw fan geometry
	Geometry *padInnerGeometry = new FanGeometry(&padInnerIndices);
	// The quads of the bezel
	Geometry *padBezelQuadsGeometry = new QuadGeometry(padBezelQuads, sizeof(padBezelQuads)/sizeof(GEquad));
	// The triangles of the bezel
	Geometry *padBezelTrianglesGeometry = new TriangleGeometry(padBezelTriangles, sizeof(padBezelTriangles)/sizeof(GEtriangle));
	// Half the geometry of the paw pad
	Geometry *pawGeometry = new CompositeGeometry({padInnerGeometry, padBezelQuadsGeometry, padBezelTrianglesGeometry});
	// The other half of the paw pad geometry
	Geometry *padReverseGeometry = new ScaleGeometry(pawGeometry, {-1, 1, 1}, true);
	return new PawPad(padVertex,
			{padReverseGeometry, pawGeometry},
			{padReverseGeometry, pawGeometry, padBezelQuadsGeometry, padBezelTrianglesGeometry, padInnerGeometry});
}
