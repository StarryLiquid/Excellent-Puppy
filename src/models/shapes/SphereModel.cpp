#include "SphereModel.hpp"

#include "../geometries/QuadGeometry.hpp"
#include "../geometries/FanGeometry.hpp"
#include <math.h>

using namespace ExcellentPuppy::Modeling;

const GLfloat& SphereModel::getMajorYArc() const {
	return _majorYArc;
}
const GLfloat& SphereModel::getMinorXArc() const {
	return _minorXArc;
}
const unsigned int& SphereModel::getYSlices() const {
	return _ySlices;
}
const unsigned int& SphereModel::getXStacks() const {
	return _xStacks;
}

SphereModel::SphereModel(
		GEnv const * const specs,
		GLfloat const & majorYArc,
		GLfloat const & minorXArc,
		unsigned int const& ySlices,
		unsigned int const& xStacks,
		GEquad const * const quadIndices,
		QuadGeometry const * const quads,
		GLuint const * const fanIndices1,
		FanGeometry const * const fan1,
		GLuint const * const fanIndices2,
		FanGeometry const * const fan2) :
		ModelNV(specs, {quads, fan1, fan2}),
		_majorYArc(majorYArc),
		_minorXArc(minorXArc),
		_ySlices(ySlices),
		_xStacks(xStacks),
		_specs(specs),
		_quadIndices(quadIndices),
		_quads(quads),
		_fanIndices1(fanIndices1),
		_fan1(fan1),
		_fanIndices2(fanIndices2),
		_fan2(fan2) { }
SphereModel::SphereModel(
		GEnv const * const specs,
		GLfloat const & majorYArc,
		GLfloat const & minorXArc,
		unsigned int const& ySlices,
		unsigned int const& xStacks,
		GEquad const * const quadIndices,
		QuadGeometry const * const quads,
		GLuint const * const fanIndices1,
		FanGeometry const * const fan1) :
		ModelNV(specs, {quads, fan1}),
		_majorYArc(majorYArc),
		_minorXArc(minorXArc),
		_ySlices(ySlices),
		_xStacks(xStacks),
		_specs(specs),
		_quadIndices(quadIndices),
		_quads(quads),
		_fanIndices1(fanIndices1),
		_fan1(fan1),
		_fanIndices2(NULL),
		_fan2(NULL) { }
SphereModel::~SphereModel() {
	delete[](_specs);
	delete[](_quadIndices);
	delete(_quads);
	delete[](_fanIndices1);
	delete(_fan1);
	if(_fan2 != NULL) {
		delete[](_fanIndices2);
		delete(_fan2);
	}
}

SphereModel* SphereModel::generate(const GLfloat& majorYArc,
		GLfloat const & minorXArc,
		unsigned int const & ySlices,
		unsigned int const & xStacks) {
	// Radians of every slice
	GLfloat ySliceRadians = (majorYArc / ySlices / 360)*(2*3.14);
	// Radians of every stack
	GLfloat xStackRadians = (minorXArc / xStacks / 360)*(2*3.14);
	// Number of total vertices
	GLuint vertexCount;
	// Number of lines between slices
	unsigned int yLines;
	if(majorYArc != 360)
		yLines = ySlices+1; // One line for every slice plus 1 at the end
	else
		yLines = ySlices; // Compelte circle of slices
	// Number of lines between stacks
	unsigned int xLines;
	if(minorXArc == 180)
		xLines = xStacks - 1;
	else
		xLines = xStacks;
	// The number of vertices
	vertexCount = yLines*xLines + 2;

	// Generate vertices
	GEnv *specs = new GEnv[vertexCount];
	// Bottom vertex
	specs[0] = {
		{0, -1, 0},
		{0, -1, 0}
	};
	// The current radians around the x, with the bottom already taken care of
	GLfloat xCurrentRadians = xStackRadians - (90*2*3.14/360);
	int currentVertexIndex = 1;
	for(unsigned int i=0; i<xLines; i++) {
		GLfloat yCurrentRadians = 0;
		GLfloat cosX = cos(xCurrentRadians);
		GLfloat sinX = sin(xCurrentRadians);
		// Render the stack
		for(unsigned int j=0; j<yLines; j++) {
			specs[currentVertexIndex].normal = {cosX*cos(yCurrentRadians), sinX, -cosX*sin(yCurrentRadians)};
			specs[currentVertexIndex].vertex = specs[currentVertexIndex].normal;
			currentVertexIndex++;
			yCurrentRadians += ySliceRadians;
		}
		// Advance to next stack
		xCurrentRadians += xStackRadians;
	}
	// Top vertex
	specs[vertexCount - 1] = {
		{0, 1, 0},
		{0, 1, 0}
	};

	// Generate the quadrilaterals on the face of the sphere
	const size_t indices = ySlices*(xLines - 1);
	auto quadIndices = new GEquad[indices];
	unsigned int col1 = 1;
	unsigned int col2 = col1 + 1;
	// For each slice
	for(unsigned int i=0; i<ySlices; i++) {
		// For each stack
		for(unsigned int j=0; j<xLines - 1; j++) {
			quadIndices[i*(xLines-1) + j] = {col1 + j*ySlices, col2 + j*ySlices, col2 + (j + 1)*ySlices, col1 + (j + 1)*ySlices};
		}
		col1 +=1;
		col2 = col1 + 1;
		if(col1 == ySlices) // Select the first column as next if circular
			col2 = 1;
	}
	auto quads = new QuadGeometry(quadIndices, indices);

	// Generate the fan at the bottom of the sphere
	auto *fanIndices1 = new GLuint[ySlices+2];
	fanIndices1[0] = 0;
	if(majorYArc != 360)
		fanIndices1[1] = ySlices + 1; // ySlice + 1 vertices, starting from 1
	else
		fanIndices1[1] = 1; // Roll back to first vertex
	for(unsigned int i=0; i<ySlices; i++)
		fanIndices1[i+2] = ySlices-i;
	FanGeometry *fanBottom = new FanGeometry(fanIndices1, sizeof(fanIndices1)/sizeof(GLuint));


	// Generate the fan at the top of the sphere, if needed
	GLuint *fanIndices2 = NULL;
	FanGeometry *fanTop = NULL;
	if(minorXArc == 180) {
		GLuint lastRowBaseIndex = vertexCount - 1 - yLines;
		fanIndices2 = new GLuint[ySlices+2]; // ySlices triangles, ySlice +1 vertex indices
		fanIndices2[0] = vertexCount - 1;
		for(unsigned int i=0; i<ySlices; i++)
			fanIndices2[i+1] = lastRowBaseIndex + i;
		if(majorYArc != 360)
			fanIndices2[ySlices+1] = vertexCount - 2; // Last vertex in fan is the vertex before the last vertex in the model
		else
			fanIndices2[ySlices+1] = lastRowBaseIndex; // Last vertex is the first vertex in the fan line
		fanTop = new FanGeometry(fanIndices2, sizeof(fanIndices2)/sizeof(GLuint));
	}

	if(fanTop != NULL)
		return new SphereModel(specs, majorYArc, minorXArc, ySlices, xStacks, quadIndices, quads, fanIndices1, fanBottom, fanIndices2, fanTop);
	else
		return new SphereModel(specs, majorYArc, minorXArc, ySlices, xStacks, quadIndices, quads, fanIndices1, fanBottom);
}
