#pragma once
#include <vector>
namespace Snicker {
	class IOManager
	{
	public:
		static bool readFileToBuffer(std::string filepath, std::vector<unsigned char>& buffer);
	};
}

