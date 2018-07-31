#ifndef ENTITIES_ENTITY_HPP_
#define ENTITIES_ENTITY_HPP_

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
				// The scaling of this entity
				GEvector _scaling;
				// A generalized radius of the entity for collision checks
				GLfloat _collisionRadius = 0;

			public:
				Entity(
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling  = {1, 1, 1});
				virtual ~Entity();

				void setPosition(GEvector position);
				virtual GEvector& getPosition();
				void setRotation(GEvector rotation);
				virtual GEvector& getRotation();
				void setScaling(GEvector scaling);
				virtual GEvector& getScaling();
				void setCollisionRadius(GLfloat radius);
				virtual GLfloat& getCollisionRadius();

				// Sets up translation and rotation and renders using the subrender method
				void render();
				// Load the entity and possibly models in the entity
				virtual void load()=0;
				// The actual rendering of this entity
				virtual void subrender()=0;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* ENTITIES_ENTITY_HPP_ */
