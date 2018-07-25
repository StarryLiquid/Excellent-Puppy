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
