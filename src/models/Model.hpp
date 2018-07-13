#ifndef MODELS_MODEL_HPP_
#define MODELS_MODEL_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model that can be rendered
		 */
		class Model {
			public:
				Model();
				virtual ~Model();

				// A method for any one time loading requirements for the model
				virtual void load() const=0;
				// Render the model into the scene
				virtual void render() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODEL_HPP_ */
