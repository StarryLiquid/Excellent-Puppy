#ifndef ENGINE_LIGHT_HPP_
#define ENGINE_LIGHT_HPP_

#include "../Base.hpp"

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		/**
		 * A light source in the scene
		 */
		class Light : public Base {
			private:
				// The name of the light in opengl
				const GLenum _name;
				// The position of the light
				GEvector _position;

			public:
				const GLenum& getName();
				GEvector& getPosition();
				virtual void setPosition(const GEvector& position);
				// The ambient constant color of the light
				virtual void setAmbient(const GEcolor& ambient);
				// The diffuse color of the light
				virtual void setDiffuse(const GEcolor& diffuse);
				// The specular  color of the light
				virtual void setSpecular(const GEcolor& specular);
				// The constant radial intesity attenuation
				virtual void setConstantAttenuation(const GLfloat& constantAttenuation);
				// The linear radial intesity attenuation
				virtual void setLinearAttenuation(const GLfloat& linearAttenuation);
				// The quadratic radial intesity attenuation
				virtual void setQuadraticAttenuation(const GLfloat& quadraticAttenuation);

				Light(
						const GLenum& name,
						const GEvector& position = {});
				virtual ~Light();

				// Enables the light
				void load() const;
				// Set light in the scene
				virtual void setLight() const;

				// Helper methods for setting properties for this light
				void setProperty(const GLenum& property, const GLfloat& value) const;
				void setProperty(const GLenum& property, const GLfloat* const & value) const;
				void setProperty(const GLenum& property, const GLint& value) const;
				void setProperty(const GLenum& property, const GLint* const & value) const;
				// Helper methods for setting light model properties
				static void setModelProperty(const GLenum& property, const GLfloat& value);
				static void setModelProperty(const GLenum& property, const GLfloat* const & value);
				static void setModelProperty(const GLenum& property, const GLint& value);
				static void setModelProperty(const GLenum& property, const GLint* const & value);
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_LIGHT_HPP_ */
