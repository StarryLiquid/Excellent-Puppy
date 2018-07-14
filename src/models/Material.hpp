#ifndef MODELS_MATERIAL_HPP_
#define MODELS_MATERIAL_HPP_

#include "../types.hpp"

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

		/**
		 * Color material for a model
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

#endif /* MODELS_MATERIAL_HPP_ */
