#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace Snicker {
	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}

	GLTexture TextureCache::getTexture(std::string texturePath)
	{
		//check if texture is in the map
		auto mit = _textureMap.find(texturePath);

		//If texture is not in the map
		if (mit == _textureMap.end()) {
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			_textureMap.insert(make_pair(texturePath, newTexture));

			std::cout << "stored new sprite" << std::endl;
			return newTexture;
		}
		std::cout << "used existing sprite" << std::endl;
		return mit->second;
	}
}
