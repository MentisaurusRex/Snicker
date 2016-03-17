#include "SnickerErrors.h"
#include <iostream>
#include <SDL/SDL.h>
namespace Snicker {
	void fatalError(std::string errorString) {
		std::cout << errorString << std::endl;
		std::cout << "Press any key to exit... ";
		int temp;
		std::cin >> temp;
		SDL_Quit();
		exit(1);
	}
}