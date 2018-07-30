#ifndef MODELS_CUBEMODEL_HPP_
#define MODELS_CUBEMODEL_HPP_

#include "../Model.hpp"
#include "../../types.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		struct GEcubeSide {
			Material *bottom = NULL; // y0
			Material *top    = NULL; // y+
			Material *left   = NULL; // x0
			Material *right  = NULL; // x+
			Material *front  = NULL; // z0
			Material *back   = NULL; // z-

			inline unsigned int sidesCount() const;
		};

		/**
		 * A model of a cube, from model origins to positive x,y and negative z.
		 */
		class CubeModel : public Model {
			private:
				// The dimensions of the cube
				const GEvector _dimensions;
				// The material sides of the cube to render
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
