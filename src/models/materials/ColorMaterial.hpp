#ifndef MODELS_MATERIALS_COLORMATERIAL_HPP_
#define MODELS_MATERIALS_COLORMATERIAL_HPP_

#include "Material.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * Color material for a model
		 */
		class ColorMaterial : public Material {
			private:
				GEcolor _color;

			public:
				ColorMaterial(GEcolor color);
				virtual ~ColorMaterial();

				// Apply the material
				virtual void apply() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MATERIALS_COLORMATERIAL_HPP_ */
