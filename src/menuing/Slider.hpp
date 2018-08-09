#ifndef MENUING_SLIDER_HPP_
#define MENUING_SLIDER_HPP_

#include "MenuControl.hpp"
#include "../models/shapes2d/RhombusModel.hpp"
#include "../models/shapes2d/SquareModel.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class RhombusModel;
		class SquareModel;
	}
	namespace Menuing {
		/**
		 * A slider control that sets some float value when clicked on.
		 */
		class Slider: public MenuControl {
			public:
				// Dimensions of this control and models
				static const GE2Dvector SLIDER_DIMENSIONS;
				static const GE2Dvector KNOB_DIMENSIONS;
				static const GE2Dvector TRACK_DIMENSIONS;

			private:
				// The current value of the slider, from 0 to 1
				GLfloat _value;
				// An action to update the value associated with this slider
				void (*_update)(void* context, GLfloat value);
				// The context to attach to the action
				void* _context;
				// The knob moving along the slider
				Modeling::RhombusModel _knob;
				// The track that the knob moves along
				Modeling::SquareModel _track;

			public:
				GLfloat const & getValue();

				Slider(GE2Dvector position, GLfloat value, void (*update)(void* context, GLfloat value), void* context = NULL);
				virtual ~Slider();

				virtual bool testCollision(const GE2Dvector& point) const;
				virtual bool handleClick(const GE2Dvector& position);
			private:
				virtual void draw() const;
		};
	
	} /* namespace Menuing */
} /* namespace ExcellentPuppy */

#endif /* MENUING_SLIDER_HPP_ */
