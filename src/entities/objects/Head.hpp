#ifndef ENTITIES_OBJECTS_HEAD_HPP_
#define ENTITIES_OBJECTS_HEAD_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		// A scale to use on the head base model
		static constexpr GLfloat HEAD_SCALE = 0.3;
		static constexpr GLfloat NOSE_SCALE = 0.5091843605041504*HEAD_SCALE;
		/**
		 * The head of the dog.
		 * Made of a base modeled in blender, two eyes, a nose (also made in blender) and a tongue.
		 */
		class Head : public CompositeEntity {
			public:
				Head(Modeling::Material* dogMaterial,
						Modeling::Material* noseMaterial,
						Modeling::Material* eyeMaterial,
						Modeling::Material* tongueMaterial,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Head();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_HEAD_HPP_ */
