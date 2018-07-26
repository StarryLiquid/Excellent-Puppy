#ifndef ENTITIES_OBJECTS_TAIL_HPP_
#define ENTITIES_OBJECTS_TAIL_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		/**
		 * The dog's tail.
		 * Made of links that can be rotated individually so the tail will wag.
		 */
		class Tail : public CompositeEntity {
			public:
				static constexpr GLfloat TAIL_RADIUS = 0.1;
				static constexpr GLfloat TAIL_LINK_LENGTH = 0.3;

			private:
				CompositeEntity* _baseJoint;
				CompositeEntity* _firstJoint;
				CompositeEntity* _secondJoint;
				CompositeEntity* _tailEndJoint;

			public:
				// The angle for the base joint
				GLfloat const & getBaseJointAngle() const;
				// The angle for the first tail joint
				GLfloat const & getFirstJointAngle() const;
				// The angle for the second tail joint
				GLfloat const & getSecondJointAngle() const;
				// The angle for the tail end joint
				GLfloat const & getTailEndJointAngle() const;

				void setBaseJointAngle(GLfloat const & baseJointAngle);
				void setFirstJointAngle(GLfloat const & firstJointAngle);
				void setSecondJointAngle(GLfloat const & secondJointAngle);
				void setTailEndJointAngle(GLfloat const & tailEndJointAngle);

				Tail(ExcellentPuppy::Modeling::Material *material,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Tail();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_TAIL_HPP_ */
