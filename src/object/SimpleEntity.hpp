#ifndef OBJECT_SIMPLEENTITY_HPP_
#define OBJECT_SIMPLEENTITY_HPP_

#include "Entity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Model;
	} /* namespace Model */
	namespace Entities {
		/**
		 * A simple entity composed of a single model
		 */
		class SimpleEntity : virtual public Entity {
			private:
				// The model of the entity
				ExcellentPuppy::Modeling::Model const *_model;

			public:
				SimpleEntity(
					ExcellentPuppy::Modeling::Model const *model,
					const GEvector& position = {},
					const GEvector& rotation = {});
				virtual ~SimpleEntity();

				virtual void load();
				virtual void subrender();
		};

	} /* namespace Objects */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_SIMPLEENTITY_HPP_ */
