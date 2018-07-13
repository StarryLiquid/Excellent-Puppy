#ifndef OBJECT_FLOORING_HPP_
#define OBJECT_FLOORING_HPP_

#include "../models/ModelNV.hpp"
#include "Entity.hpp"

namespace ExcellentPuppy {
namespace Entities {
	class Flooring: public Entity {
		private:
			int _flooringWidth, _flooringHeight;
			Modeling::ModelNV _model;

		public:
			Flooring(int flooringWidth, int flooringHeight);
			virtual ~Flooring();

			virtual void subrender();
	};

} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* OBJECT_FLOORING_HPP_ */
