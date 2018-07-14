#ifndef MODELS_MATERIAL_HPP_
#define MODELS_MATERIAL_HPP_

#include "../../types.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Material options that can be attached to a model.
		 */
		class Material {
			public:
				Material();
				virtual ~Material();

				// Apply the material
				virtual void apply() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MATERIAL_HPP_ */
