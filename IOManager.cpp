#include "IOManager.h"
#include <fstream>
namespace Snicker {
	bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		//Seek to file's end
		file.seekg(0, std::ios::end);

		//Get file size
		int fileSize = (int)file.tellg();

		//Back to the beginning
		file.seekg(0, std::ios::beg);

		//Ignore header
		//!!May not matter!!
		fileSize -= (int)file.tellg();

		buffer.resize(fileSize);
		file.read((char*)&(buffer[0]), fileSize);

		return true;
	}
}

