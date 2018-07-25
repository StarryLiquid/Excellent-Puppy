#ifndef ENTITIES_OBJECTS_FOOT_HPP_
#define ENTITIES_OBJECTS_FOOT_HPP_

#include "../CompositeEntity.hpp"

#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		class Model;
		class Material;
	}
	namespace Entities {
		/**
		 * A dog's foot
		 */
		class Foot: public CompositeEntity {
			private:
				std::list<Modeling::Model*> _toDelete;

			public:
				Foot(ExcellentPuppy::Modeling::Material *dogMaterial,
						ExcellentPuppy::Modeling::Material *pawMaterial,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Foot();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_FOOT_HPP_ */
