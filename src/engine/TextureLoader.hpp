#ifndef ENGINE_TEXTURELOADER_HPP_
#define ENGINE_TEXTURELOADER_HPP_

#include "../Base.hpp"

#include <string>
#include <list>

namespace ExcellentPuppy {
	namespace Modeling {
		class Texture;
	}
	namespace Engine {
		class TextureLoader : public Base {
			private:
				static std::list<Modeling::Texture*> _textures;

			public:
				static Modeling::Texture* createTexture(std::string fileName);
				static void loadTexture(Modeling::Texture const * texture);
				static void loadTextures();
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_TEXTURELOADER_HPP_ */
