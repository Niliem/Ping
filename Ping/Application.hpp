#pragma once

#include "StateManager.hpp"

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

	void calculateFPS();

	sf::RenderWindow mWindow;
	bool mApplicationRunning;

	float mLastDeltaTime;
	float mCurrentSlice;

	const float mDeltaTimeStep;
	const float mDeltaTimeSlice;

	sf::Font mFont;
	sf::Text mStatisticsText;
};

