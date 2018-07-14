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
				GEMaterial _material;

			public:
				LightMaterial(GEMaterial material);
				virtual ~LightMaterial();

				// Apply the material
				virtual void apply() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MATERIALS_LIGHTMATERIAL_HPP_ */
