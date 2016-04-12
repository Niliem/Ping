#include "Application.hpp"
#include "StateGame.hpp"
#include <chrono>


Application::Application()
	: mWindow{ { WINDOW_WIDTH, WINDOW_HEIGHT}, "Ping pong" }
	, mApplicationRunning(false)
	, mLastDeltaTime{ 0.0f }
	, mCurrentSlice{ 0.0f }
	, mDeltaTimeStep{ 1.0f }
	, mDeltaTimeSlice{ 1.0f }
	, mFont()
	, mStatisticsText()
{
	mWindow.setFramerateLimit(60);

	mFont.loadFromFile("Data/Graphics/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(14);

	StateManager::setState(std::make_shared<StateGame>(&mWindow));
}

Application::~Application()
{
}

void Application::run()
{
	mApplicationRunning = true;
	while (mApplicationRunning || mWindow.isOpen())
	{
		auto timePoint1 = std::chrono::high_resolution_clock::now();

		processEvents();
		update();
		render();

		auto timePoint2 = std::chrono::high_resolution_clock::now();

		auto elapsedTime = timePoint2 - timePoint1;
		mLastDeltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(elapsedTime).count();

		calculateFPS();
	}
}

void Application::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		StateManager::handleEvent();

		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
		default:
			break;
		}
	}
}

void Application::update()
{
	mCurrentSlice += mLastDeltaTime;
	for (; mCurrentSlice >= mDeltaTimeSlice; mCurrentSlice -= mDeltaTimeSlice)
	{
		StateManager::update(mDeltaTimeStep);
	}
}

void Application::render()
{
	mWindow.clear();	

	StateManager::render();	
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Application::calculateFPS()
{
	auto ftSeconds = mLastDeltaTime / 1000.0f;
	auto fps = 1.0f / ftSeconds;
	mStatisticsText.setString("FT: " + std::to_string(mLastDeltaTime) + "\tFPS: " + std::to_string(fps));
}
