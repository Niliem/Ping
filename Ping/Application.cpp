#include "Application.hpp"


Application::Application()
	: mWindow{ { WINDOW_WIDTH, WINDOW_HEIGHT}, "Ping pong" }
	, mLastFt{ 0.0f }
	, mCurrentSlice{ 0.0f }
	, mFtStep{ 1.0f }
	, mFtSlice{ 1.0f }
{
	mWindow.setFramerateLimit(60);
	StateManager::setState(std::shared_ptr<StateMenu>(new StateMenu(&mWindow)));
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
		mLastFt = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(elapsedTime).count();
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
	mCurrentSlice += mLastFt;
	for (; mCurrentSlice >= mFtSlice; mCurrentSlice -= mFtSlice)
	{
		StateManager::update(mFtStep);
	}
}

void Application::render()
{
	mWindow.clear();

	StateManager::render();

	mWindow.display();
}
