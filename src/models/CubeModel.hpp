#ifndef MODELS_CUBEMODEL_HPP_
#define MODELS_CUBEMODEL_HPP_

#include "Model.hpp"
#include "../types.hpp"

struct GEcubeSide {
	bool bottom : 1; // y0
	bool top    : 1; // y+
	bool left   : 1; // x0
	bool right  : 1; // x+
	bool front  : 1; // z0
	bool back   : 1; // z-

	inline unsigned int sidesCount() const;
};

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * A model of a cube, from model origins to positive x,y and negative z.
		 */
		class CubeModel : public Model {
			private:
				// The dimensions of the cube
				const GEvector _dimensions;
				// The sides of the cube to render
				const GEcubeSide _sides;
				// Whether the cube faces are facing inside
				const bool _facingInside;

			public:
				const GEvector& getDimensions();
				const GEcubeSide& getSides();
				const bool& isFacingInside();

				CubeModel(const GEvector& dimensions,
				     const GEcubeSide& sides,
				     const bool& facingInside);
				virtual ~CubeModel();

				virtual void load() const;
				virtual void draw() const;
		};
	} /* namespace Modeling */
} /* namespace ExcellentPuppy */

#endif /* MODELS_CUBEMODEL_HPP_ */
