#ifndef MODELS_MODEL_HPP_
#define MODELS_MODEL_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		class Model {
			public:
				Model();
				virtual ~Model();

				virtual void load() const=0;
				virtual void render() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_MODEL_HPP_ */
