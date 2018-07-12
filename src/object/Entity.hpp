#ifndef OBJECT_ENTITY_HPP_
#define OBJECT_ENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
namespace Entities {
	class Entity {
		private:
			GEvector _position;
			GEvector _rotation;

		public:
			Entity(
					GEvector position = {0, 0, 0},
					GEvector rotation = {0, 0, 0});
			virtual ~Entity();

			inline void setPosition(GEvector position);
			virtual GEvector *getPosition();
			inline void setRotation(GEvector rotation);
			virtual GEvector *getRotation();

			void render();
			virtual void subrender()=0;
	};
} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_ENTITY_HPP_ */
