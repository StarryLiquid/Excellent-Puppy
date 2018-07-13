#ifndef OBJECT_ENTITY_HPP_
#define OBJECT_ENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Entities {
		/**
		 * An entity in a scene, with a position and basic rotation.
		 * Represents an object in the scene, usually displayed by a model.
		 */
		class Entity {
			private:
				// The position of the entity
				GEvector _position;
				// The angles of this entity around each axis
				GEvector _rotation;

			public:
				Entity(
						GEvector position = {},
						GEvector rotation = {});
				virtual ~Entity();

				inline void setPosition(GEvector position);
				virtual GEvector& getPosition();
				inline void setRotation(GEvector rotation);
				virtual GEvector& getRotation();

				// Sets up translation and rotation and renders using the subrender method
				void render();
				// The actual rendering of this entity
				virtual void subrender()=0;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_ENTITY_HPP_ */
