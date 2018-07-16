#ifndef ENGINE_LIGHT_HPP_
#define ENGINE_LIGHT_HPP_

#include "../types.hpp"

namespace ExcellentPuppy {
	namespace Engine {
		/**
		 * A light source in the scene
		 */
		class Light {
			private:
				// The name of the light in opengl
				const GLenum _name;
				// The position of the light
				GEvector _position;
				// The ambient constant color of the light
				GEcolor _ambient;
				// The diffuse color of the light
				GEcolor _diffuse;
				// The specular  color of the light
				GEcolor _specualr;
				// The constant radial intesity attenuation
				GLfloat _constantAttenuation;
				// The linear radial intesity attenuation
				GLfloat _linearAttenuation;
				// The quadratic radial intesity attenuation
				GLfloat _quadraticAttenuation;

			public:
				const GLenum& getName();
				const GEvector& getPosition();
				void setPosition(const GEvector& position);
				const GEcolor& getAmbient();
				void setAmbient(const GEcolor& ambient);
				const GEcolor& getDiffuse();
				void setDiffuse(const GEcolor& diffuse);
				const GEcolor& getSpecular();
				void setSpecular(const GEcolor& specular);
				const GLfloat& getConstantAttenuation();
				void setConstantAttenuation(const GLfloat& constantAttenuation);
				const GLfloat& getLinearAttenuation();
				void setLinearAttenuation(const GLfloat& linearAttenuation);
				const GLfloat& getQuadraticAttenuation();
				void setQuadraticAttenuation(const GLfloat& quadraticAttenuation);

				Light(
						const GLenum& _name,
						const GEvector& position = {});
				virtual ~Light();

				// Enables the light
				void load() const;

				// Helper methods for setting properties for this light
				void setProperty(const GLenum& property, const GLfloat& value);
				void setProperty(const GLenum& property, const GLfloat* const & value);
				void setProperty(const GLenum& property, const GLint& value);
				void setProperty(const GLenum& property, const GLint* const & value);
				// Helper methods for setting light model properties
				static void setModelProperty(const GLenum& property, const GLfloat& value);
				static void setModelProperty(const GLenum& property, const GLfloat* const & value);
				static void setModelProperty(const GLenum& property, const GLint& value);
				static void setModelProperty(const GLenum& property, const GLint* const & value);
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_LIGHT_HPP_ */
