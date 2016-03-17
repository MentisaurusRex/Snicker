#pragma once
#include "GLTexture.h"
#include <string>
namespace Snicker {
	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);

	};
}

