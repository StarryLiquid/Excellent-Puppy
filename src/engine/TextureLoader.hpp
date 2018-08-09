#ifndef ENGINE_TEXTURELOADER_HPP_
#define ENGINE_TEXTURELOADER_HPP_

#include "../Base.hpp"

#include <string>
#include <unordered_set>

namespace ExcellentPuppy {
	namespace Modeling {
		class Texture;
	}
	namespace Engine {
		class TextureLoader : public Base {
			private:
				static std::unordered_set<Modeling::Texture*> _textures;

			public:
				static Modeling::Texture* createTexture(std::string fileName);
				static void deleteTexture(Modeling::Texture* texture, bool deleteRef=true);
				static void loadTexture(Modeling::Texture const * texture);
				static void loadTextures();
		};
	} /* namespace Engine */
} /* namespace ExcellentPuppy */

#endif /* ENGINE_TEXTURELOADER_HPP_ */
