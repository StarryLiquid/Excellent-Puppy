#ifndef ENTITIES_OBJECTS_LEG_HPP_
#define ENTITIES_OBJECTS_LEG_HPP_

#include "../CompositeEntity.hpp"
#include "Dog.hpp"
#include "Foot.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		class Leg : public CompositeEntity {
			public:
				static constexpr GLfloat LEG_RADIUS = 0.1;
				static constexpr GLfloat FOOT_SCALE = 0.2;
				static constexpr GLfloat LEG_LINK_LENGTH = (Dog::BODY_HEIGHT - Foot::FOOT_HEIGHT*FOOT_SCALE)/2;

			private:
				CompositeEntity* _socketJoint;
				CompositeEntity* _kneeJoint;
				CompositeEntity* _footJoint;

			public:
				// The angle for the socket joint
				GLfloat const & getSocketJointAngle() const;
				// The angle for the knee joint
				GLfloat const & getFootJointAngle() const;
				// The angle for the foot joint
				GLfloat const & getKneeJointAngle() const;

				void setFootJointAngle(GLfloat const & footJointAngle);
				void setKneeJointAngle(GLfloat const & kneeJointAngle);
				void setSocketJointAngle(GLfloat const & socketJointAngle);

				Leg(Modeling::Material *dogMaterial,
						Modeling::Material *pawMaterial,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Leg();
		};
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_LEG_HPP_ */
