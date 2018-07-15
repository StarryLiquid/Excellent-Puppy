#ifndef MODELS_SHAPES_CYLINDERMODEL_HPP_
#define MODELS_SHAPES_CYLINDERMODEL_HPP_

#include "../Model.hpp"
#include <GL/freeglut.h>

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A simple cylinder model, based on the glut cylinder
		 */
		class CylinderModel: public Model {
			private:
				// The radius of the cylinder
				double _radius;
				// The height along the positive z axis of the cylinder
				double _height;
				// Slices across the cylinder
				GLint _slices;
				// Stacks along the cylinder
				GLint _stacks;

			public:
				double& getRadius();
				double& getHeight();
				GLint& getSlices();
				GLint& getStacks();

				CylinderModel(
						const double& radius,
						const double& height,
						const GLint& slices,
						const GLint& stacks);
				virtual ~CylinderModel();

				virtual void load() const;
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_CYLINDERMODEL_HPP_ */
