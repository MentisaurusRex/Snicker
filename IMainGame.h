#pragma once
#include <memory>
#include "Snicker.h"
#include "Window.h"
#include "InputManager.h"
#include "AudioEngine.h"

namespace Snicker {

	class ScreenList;
	class IGameScreen;

	class IMainGame
	{
	public:
		IMainGame();
		virtual ~IMainGame();

		void run();
		void exitGame();

		virtual void onInit() = 0;
		virtual void addScreens() = 0;
		virtual void onExit() = 0;

		const float getFPS() const {
			return m_fps;
		}

		void onSDLEvent(SDL_Event& evnt);

		InputManager m_inputManager;

	protected:
		virtual void update();
		virtual void draw();		

		bool init();
		bool initSystems();
		std::unique_ptr<ScreenList> m_screenList = nullptr;
		IGameScreen* m_currentScreen = nullptr;
		bool m_isRunning = false;
		float m_fps = 0;
		Window m_window;
		AudioEngine m_audioEngine;
		
	};
}

