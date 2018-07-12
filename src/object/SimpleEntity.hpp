#ifndef OBJECT_SIMPLEENTITY_HPP_
#define OBJECT_SIMPLEENTITY_HPP_

#include "Entity.hpp"

namespace ExcellentPuppy {
namespace Modeling {
	class Model;
}
namespace Entities {
	class SimpleEntity : virtual public Entity {
		private:
			ExcellentPuppy::Modeling::Model const *_model;

		public:
			SimpleEntity(GEvector position, GEvector rotation, ExcellentPuppy::Modeling::Model const *model);
			virtual ~SimpleEntity();

			virtual void subrender();
	};

} /* namespace Objects */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_SIMPLEENTITY_HPP_ */
