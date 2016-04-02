#pragma once

#include <chrono>

#include "StateManager.hpp"
#include "StateMenu.hpp"

constexpr unsigned int WINDOW_WIDTH{ 640 };
constexpr unsigned int WINDOW_HEIGHT{ 480 };

class Application
	: sf::NonCopyable
{
public:
	Application();
	~Application();

	void run();

private:
	void processEvents();
	void update();
	void render();

private:
	sf::RenderWindow mWindow;
	bool mApplicationRunning;

	float mLastFt;
	float mCurrentSlice;

	const float mFtStep;
	const float mFtSlice;
};

