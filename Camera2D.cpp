#include "Camera2D.h"
#include <algorithm>

namespace Snicker {
	Camera2D::Camera2D()
	{
	}


	Camera2D::~Camera2D()
	{
	}

	void Camera2D::init(int screenWidth, int screenHeight) {
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
	}

	void Camera2D::update() {

		if (_needsMatrixUpdate) {
			glm::vec3 translate(-_position.x + _screenWidth / 2, -_position.y + _screenHeight / 2, 0.0f);
			_cameraMatrix = glm::translate(_orthoMatrix, translate);

			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;

			
			_needsMatrixUpdate = false;
		}
	}

	glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords) {
		//make 0 the center of the screen
		screenCoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);
		//scale the coordinates
		screenCoords /= _scale;
		//translate with camera position
		screenCoords += _position;
		return screenCoords;
	}

	bool Camera2D::isBoxInView(const glm::vec2& position, const glm::vec2& dimensions) {

		glm::vec2 scaledScreenDimensions = glm::vec2(_screenWidth, _screenHeight) / _scale;
		//Minimum distance before collision occurs
		const float MIN_DISTANCE_X = dimensions.x / 2.0f + scaledScreenDimensions.x / 2.0f;
		const float MIN_DISTANCE_Y = dimensions.y / 2.0f + scaledScreenDimensions.y / 2.0f;
		//Center position of the parameters
		glm::vec2 centerPosition = _position + dimensions / 2.0f;
		//Center position of the camera
		glm::vec2 centerCameraPos = _position;
		//Vector from input to camera
		glm::vec2 distVec = centerPosition - centerCameraPos;
		
		//Get depth of the collision
		float xDepth = MIN_DISTANCE_X - abs(distVec.x);
		float yDepth = MIN_DISTANCE_Y - abs(distVec.y);

		//if either depths are > 0 then we collided
		if (xDepth > 0 && yDepth > 0) {
			//There was a collision
			return true;
		}
		return false;
	}
}