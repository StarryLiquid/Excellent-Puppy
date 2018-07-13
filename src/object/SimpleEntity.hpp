#ifndef OBJECT_SIMPLEENTITY_HPP_
#define OBJECT_SIMPLEENTITY_HPP_

#include "Entity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Model;
	} /* namespace Model */
	namespace Entities {
		class SimpleEntity : virtual public Entity {
			private:
				ExcellentPuppy::Modeling::Model const *_model;

			public:
				SimpleEntity(
					ExcellentPuppy::Modeling::Model const *model,
					const GEvector& position = {},
					const GEvector& rotation = {});
				virtual ~SimpleEntity();

				virtual void subrender();
		};

	} /* namespace Objects */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_SIMPLEENTITY_HPP_ */
