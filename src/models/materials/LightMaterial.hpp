#ifndef MODELS_MATERIALS_LIGHTMATERIAL_HPP_
#define MODELS_MATERIALS_LIGHTMATERIAL_HPP_

#include "Material.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Light material for a model
		 */
		class LightMaterial : public Material {
			private:
				GEMaterial const _material;

			public:
				LightMaterial(GEMaterial const & material);
				virtual ~LightMaterial();

				// Apply the material
				virtual void apply() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MATERIALS_LIGHTMATERIAL_HPP_ */
