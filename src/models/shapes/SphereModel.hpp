#ifndef MODELS_SHAPES_SPHEREMODEL_HPP_
#define MODELS_SHAPES_SPHEREMODEL_HPP_

#include "../ModelNV.hpp"

struct GEquad;

namespace ExcellentPuppy {
	namespace Modeling {
		class QuadGeometry;
		class FanGeometry;

		/**
		 * A model of a sphere or part of a sphere
		 */
		class SphereModel: public ModelNV {
			private:
				// The major arc in degrees around the Y axle
				// From 0 to 360
				GLfloat const _majorYArc;
				// The minor arc in degrees around the X axle
				// From 0 to 180
				GLfloat const _minorXArc;
				// The number of slices around the Y axle
				unsigned int const  _ySlices;
				// The number of stacks along the Y axle and around the X axle
				unsigned int const _xStacks;

				// Pointer to the specs for deletion
				GEnv const * const _specs;
				// The indices for quads around the sphere
				GEquad const * const _quadIndices;
				// The quad geometry
				QuadGeometry const * const _quads;
				// The indices for the bottom fan
				GLuint const * const _fanIndices1;
				// The bottom fan
				FanGeometry const * const _fan1;
				// The indices for the top fan
				GLuint const * const _fanIndices2;
				// The top fan
				FanGeometry const * const _fan2;

			public:
				inline const GLfloat& getMajorYArc() const;
				inline const GLfloat& getMinorXArc() const;
				inline const unsigned int& getYSlices() const;
				inline const unsigned int& getXStacks() const;

			private:
				SphereModel(
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
					FanGeometry const * const fan2);
				SphereModel(
					GEnv const * const specs,
					GLfloat const & majorYArc,
					GLfloat const & minorXArc,
					unsigned int const& ySlices,
					unsigned int const& xStacks,
					GEquad const * const quadIndices,
					QuadGeometry const * const quads,
					GLuint const * const fanIndices1,
					FanGeometry const * const fan1);
			public:
				virtual ~SphereModel();

				// Generate a sphere section with the given paramters
				static SphereModel* generate(const GLfloat& majorYArc,
					GLfloat const & minorXArc,
					unsigned int const & ySlices,
					unsigned int const & xStacks);
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_SPHEREMODEL_HPP_ */
