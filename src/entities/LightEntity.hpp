#ifndef ENTITIES_LIGHTENTITY_HPP_
#define ENTITIES_LIGHTENTITY_HPP_

#include "Entity.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		class Light;
	}
	namespace Entities {
		/**
		 * An entity representing a light in the scene
		 */
		class LightEntity: public Entities::Entity {
			private:
				// The light attached to this entity
				Engine::Light *_light;

			public:
				LightEntity(
						Engine::Light* const & light,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling  = {1, 1, 1});
				virtual ~LightEntity();

				// Enables the light
				virtual void load();
				// Set the position of the light with entity's transformations
				// Will only take effect next frame
				virtual void subrender();
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_LIGHTENTITY_HPP_ */
