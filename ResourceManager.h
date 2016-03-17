#pragma once
#include "TextureCache.h"
namespace Snicker {
	class ResourceManager
	{
	public:
		static GLTexture getTexture(std::string texturePath);
	private:
		static TextureCache _textureCache;
	};
}

