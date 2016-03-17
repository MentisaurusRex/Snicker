#include "Timing.h"
#include <SDL/SDL.h>
namespace Snicker {

	FPSLimiter::FPSLimiter() {

	}
	void FPSLimiter::setMaxFPS(float maxFPS) {
		_maxFPS = maxFPS;
	}
	void FPSLimiter::begin() {
		_startTicks = SDL_GetTicks();
	}
	float FPSLimiter::end() {
		calculateFPS();

		float frameTicks = (float)SDL_GetTicks() - _startTicks;
		if (1000.0f / _maxFPS > frameTicks) {
			SDL_Delay((Uint32)(1000.0f / _maxFPS - frameTicks));
		}

		return _fps;
	}

	void FPSLimiter::calculateFPS() {
		static const int NUM_SAMPLES = 100;
		static float frameTimes[NUM_SAMPLES];
		static int currentFrame = 0;

		static float previousTicks = (float)SDL_GetTicks();
		float currentTicks;

		currentTicks = (float)SDL_GetTicks();

		_frameTime = currentTicks - previousTicks;
		frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

		previousTicks = currentTicks;
		int count;
		currentFrame++;

		if (currentFrame < NUM_SAMPLES) {
			count = currentFrame;
		}
		else {
			count = NUM_SAMPLES;
		}
		float frameTimeAverage = 0;

		for (int i = 0; i < count; i++) {
			frameTimeAverage += frameTimes[i];
		}

		frameTimeAverage /= count;

		if (frameTimeAverage > 0) {
			_fps = 1000.0f / frameTimeAverage;
		}
		else
		{
			_fps = -1.0f;
		}
	}

}