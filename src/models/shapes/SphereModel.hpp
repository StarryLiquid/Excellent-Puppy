#ifndef MODELS_SHAPES_SPHEREMODEL_HPP_
#define MODELS_SHAPES_SPHEREMODEL_HPP_

#include "../ModelNV.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model of a sphere or part of a sphere
		 */
		class SphereModel: public ModelNV {
			private:
				// The major arc in degrees around the Y axle
				// From 0 to 360
				const GLfloat _majorYArc;
				// The minor arc in degrees around the X axle
				// From 0 to 180
				const GLfloat _minorXArc;
				// The number of slices around the Y axle
				const unsigned int _ySlices;
				// The number of stacks along the Y axle and around the X axle
				const unsigned int _xStacks;

			public:
				inline const GLfloat& getMajorYArc() const;
				inline const GLfloat& getMinorXArc() const;
				inline const unsigned int& getYSlices() const;
				inline const unsigned int& getXStacks() const;

			private:
				SphereModel(GEnv* const & specs,
					std::list<Geometry*> const & geometries,
					const GLfloat& majorYArc,
					const GLfloat& minorXArc,
					const unsigned int& ySlices,
					const unsigned int& xStacks);
			public:
				virtual ~SphereModel();

				// Generate a sphere section with the given paramters
				static SphereModel* generate(const GLfloat& majorYArc,
					const GLfloat& minorXArc,
					const unsigned int& ySlices,
					const unsigned int& xStacks);
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_SPHEREMODEL_HPP_ */
