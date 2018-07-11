#ifndef OBJECT_ENTITY_HPP_
#define OBJECT_ENTITY_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
namespace Objects {

	class Entity {
		private:
			GEvertex3D _position;
			GEvec3D _rotation;

		public:
			Entity(GEvertex3D position, GEvec3D rotation);
			virtual ~Entity();

			inline void setPosition(GEvertex3D position);
			virtual GEvertex3D *getPosition();
			inline void setRotation(GEvec3D rotation);
			virtual GEvec3D *getRotation();

			void render();
			virtual void subrender()=0;
	};

} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* OBJECT_ENTITY_HPP_ */
