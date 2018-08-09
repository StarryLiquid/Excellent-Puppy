#ifndef ENGINE_DIRECTIONALLIGHT_HPP_
#define ENGINE_DIRECTIONALLIGHT_HPP_

#include "Light.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		class DirectionalLight: public Light {
			public:
				DirectionalLight(const GLenum& _name,
						const GEvector& direction = {});
				virtual ~DirectionalLight();

				// Sets the direction of the light source
				virtual void setDirection(const GEvector& direction);
				// Sets the angle to cutoff the spotlight on
				virtual void setSpotlightCutoff(const GLfloat& angle);
				// Sets the exponent of the spotlight
				virtual void setSpotlightExponent(const GLfloat& exponent);
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_DIRECTIONALLIGHT_HPP_ */
