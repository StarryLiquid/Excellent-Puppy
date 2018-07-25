#include "CompositeGeometry.hpp"

using namespace ExcellentPuppy::Modeling;
		
CompositeGeometry::CompositeGeometry(std::list<const Geometry*> const & geometries) :
	Geometry(),
	_geometries(geometries) { }
CompositeGeometry::~CompositeGeometry() { }

void CompositeGeometry::render() const {
	for(const Geometry* geometry : _geometries) {
		geometry->render();
	}
}
