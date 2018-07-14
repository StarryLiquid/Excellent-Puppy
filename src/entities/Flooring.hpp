#ifndef ENTITIES_FLOORING_HPP_
#define ENTITIES_FLOORING_HPP_

#include "../entities/Entity.hpp"

struct GEvector;

namespace ExcellentPuppy {
	namespace Modeling {
		class ModelNV;
	}
	namespace Entities {
		/**
		 * Black and white tiling with gray in-between.
		 * The tiles are spread from the entity's origin towards the positive directions of x and z.
		 */
		class Flooring: public Entity {
			private:
				// Number of tiles along the x and y axis
				int _flooringWidth, _flooringHeight;

			public:
				Flooring(unsigned int flooringWidth,
						 unsigned int flooringHeight,
						 const GEvector& position = {},
						 const GEvector& rotation = {});
				virtual ~Flooring();

				virtual void load();
				virtual void subrender();
				// The 2d size of the entire tile flooring
				GEvector extent();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_FLOORING_HPP_ */
