#pragma once
namespace Snicker {

	class FPSLimiter {
	public:
		FPSLimiter();
		void setMaxFPS(float maxFPS);
		void begin();
		//end returns fps
		float end();
	private:
		void calculateFPS();

		float _maxFPS;
		unsigned int _startTicks;
		float _fps;
		float _frameTime;
	};
}