#ifndef MODELS_SHAPES_CHAIR_HPP_
#define MODELS_SHAPES_CHAIR_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		class SimpleEntity;

		/**
		 * A simple chair model.
		 */
		class Chair {
			public:
				// Creates a chair entity
				static SimpleEntity* createChair(Modeling::Material* chairMaterial);
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_SHAPES_CHAIR_HPP_ */
