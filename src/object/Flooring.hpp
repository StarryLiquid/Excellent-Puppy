#ifndef OBJECT_FLOORING_HPP_
#define OBJECT_FLOORING_HPP_

#include "Entity.hpp"

struct GEvector;

namespace ExcellentPuppy {
	namespace Modeling {
		class ModelNV;
	}
	namespace Entities {
		class Flooring: public Entity {
			private:
				int _flooringWidth, _flooringHeight;

			public:
				Flooring(unsigned int flooringWidth,
						 unsigned int flooringHeight,
						 const GEvector& position = {},
						 const GEvector& rotation = {});
				virtual ~Flooring();

				virtual void subrender();
				GEvector extent();
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_FLOORING_HPP_ */
