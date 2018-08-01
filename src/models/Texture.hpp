#ifndef ENGINE_TEXTURE_HPP_
#define ENGINE_TEXTURE_HPP_

#include <GL/freeglut.h>
#include <string>

namespace ExcellentPuppy {
	namespace Engine {
		class TextureLoader;
	}
	namespace Modeling {
		class Texture {
				friend class ExcellentPuppy::Engine::TextureLoader;
			private:
				// The name of the file to load
				std::string _filename;
				// The GL id of the texture
				GLuint _id;
				// Whether the texture was loaded or not
				bool _isLoaded = false;

				Texture(std::string filename, GLuint id);
			public:
				virtual ~Texture();

				// Load the texture if needed
				void loadTexture();
				// Bind the texture as the current texture
				void selectTexture() const;
		};
	
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_TEXTURE_HPP_ */
