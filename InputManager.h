#pragma once
#include <unordered_map>
#include <glm\glm.hpp>

namespace Snicker {
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void update();

		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);

		void setMouseCoords(float x, float y);

		//returns true if key is held down
		bool isKeyDown(unsigned int keyID);

		//returns true is key was just pressed
		bool isKeyPressed(unsigned int keyID);

		glm::vec2 getMouseCoords() {return _mouseCoords;}
	private:
		bool wasKeyDown(unsigned int keyID);

		std::unordered_map<unsigned int, bool> _keyMap;
		std::unordered_map<unsigned int, bool> _previousKeyMap;
		glm::vec2 _mouseCoords = glm::vec2(0.0f, 0.0f);
	};
}

