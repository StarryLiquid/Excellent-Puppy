#ifndef MODELS_SHAPES_FOOTFRAME_HPP_
#define MODELS_SHAPES_FOOTFRAME_HPP_

#include "../ModelNV.hpp"
#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * The foot of a dog, minus the paw pads
		 */
		class FootFrame : public ModelNV {
			public:
				static constexpr GLfloat FEET_HEIGHT = 0.5;
				static constexpr GLfloat FEET_CURVE_HEIGHT = 0.1;
				static constexpr GLfloat FEET_WALL_HEIGHT = FEET_HEIGHT - FEET_CURVE_HEIGHT*2;

			private:
				// Geometries to delete with this model
				std::list<Geometry*> _geometriesToDelete;

				FootFrame(const GEnv* specs,
						std::list<Geometry*> geometries,
						std::list<Geometry*> geometriesToDelete);
			public:
				virtual ~FootFrame();

				// Create a dog feet model
				static FootFrame* create();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_FOOTFRAME_HPP_ */
