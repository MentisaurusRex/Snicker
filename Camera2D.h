#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Snicker {
	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();

		void init(int screenWidth, int screenHeight);

		void update();

		glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

		bool isBoxInView(const glm::vec2& position, const glm::vec2& dimensions);

		//setters
		void setPosition(const glm::vec2& newPosition) {
			_position = newPosition; 
			_needsMatrixUpdate = true;
		}
		void setScale(float newScale) {
			_scale = newScale; 
			_needsMatrixUpdate = true;
		}

		//getters
		glm::vec2 getPosition() { return _position; }
		float getScale() { return _scale; }
		glm::mat4 getCameraMatrix() { return _cameraMatrix; }

	private:
		int _screenWidth = 500;
		int _screenHeight = 500;
		bool _needsMatrixUpdate = true;
		float _scale = 1.0f;
		glm::vec2 _position = glm::vec2(0.0f, 0.0f);
		glm::mat4 _cameraMatrix = glm::mat4(1.0f);
		glm::mat4 _orthoMatrix = glm::mat4(1.0f);
		
	};
}
