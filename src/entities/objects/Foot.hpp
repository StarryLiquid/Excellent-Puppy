#ifndef ENTITIES_OBJECTS_FOOT_HPP_
#define ENTITIES_OBJECTS_FOOT_HPP_

#include "../CompositeEntity.hpp"
#include "../../models/shapes/FootFrame.hpp"
#include "../../models/shapes/PawPad.hpp"

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
		class Foot : public CompositeEntity {
			public:
				static constexpr GLfloat FOOT_HEIGHT = Modeling::FootFrame::FEET_HEIGHT + Modeling::PawPad::PAD_HEIGHT;

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
