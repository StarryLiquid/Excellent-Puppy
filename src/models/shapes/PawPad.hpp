#ifndef MODELS_SHAPES_PAWPAD_HPP_
#define MODELS_SHAPES_PAWPAD_HPP_

#include "../ModelNV.hpp"
#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		class PawPad: public ModelNV {
			public:
				// The height of the paw pads
				static constexpr GLfloat PAD_HEIGHT = 0.1;

			private:
				// Geometries to delete with this model
				std::list<Geometry*> _geometriesToDelete;

			public:
				PawPad(const GEnv* specs,
						std::list<Geometry*> geometries,
						std::list<Geometry*> geometriesToDelete);
				virtual ~PawPad();

				// Create a dog paw pad model
				static PawPad* create();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_PAWPAD_HPP_ */
