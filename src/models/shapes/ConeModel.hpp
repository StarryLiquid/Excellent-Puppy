#ifndef MODELS_SHAPES_CONEMODEL_HPP_
#define MODELS_SHAPES_CONEMODEL_HPP_

#include "../Model.hpp"
#include <GL/freeglut.h>

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A simple cone model, based on the glut cone
		 */
		class ConeModel: public Model {
			private:
				// The radius of the cone base
				double _base;
				// The height of the cone to the positive z axis
				double _height;
				// Number of slices around the cone center
				GLint _slices;
				// Number of stacks up the cone
				GLint _stacks;

			public:
				double& getBase();
				double& getHeight();
				GLint& getSlices();
				GLint& getStacks();

				ConeModel(const double& base,
						const double& height,
						const GLint& slices,
						const GLint& stacks);
				virtual ~ConeModel();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_CONEMODEL_HPP_ */
