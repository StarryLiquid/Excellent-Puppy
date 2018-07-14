#ifndef MODELS_MODEL_HPP_
#define MODELS_MODEL_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;

		/**
		 * A model that can be rendered
		 */
		class Model {
			private:
				 Material *_material;

			public:
				Model();
				virtual ~Model();

				Material* const & getMaterial() const;
				void setMaterial(Material* material);

				// A method for any one time loading requirements for the model
				virtual void load() const=0;
				// Render the model into the scene
				void render() const;
			private:
				// Render the model into the scene
				void applyMaterials() const;
			protected:
				// Draw the model
				virtual void draw() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODEL_HPP_ */
