#ifndef MODELS_WALLMODEL_HPP_
#define MODELS_WALLMODEL_HPP_

#include "Model.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class WallModel : public Model {
			public:
				WallModel();
				virtual ~WallModel();

				virtual void load() const;
			protected:
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_WALLMODEL_HPP_ */
