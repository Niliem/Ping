#include "Application.hpp"



Application::Application()
	: mWindow{ {640, 480}, "Ping pong" }
{
	StateManager::setState(std::shared_ptr<StateMenu>(new StateMenu));
}


Application::~Application()
{
}

void Application::run()
{
	mApplicationRunning = true;
	while (mApplicationRunning || mWindow.isOpen())
	{
		processEvents();
		update();
		render();
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
	StateManager::update(0);
}

void Application::render()
{
	mWindow.clear();

	StateManager::render(&mWindow);

	mWindow.display();
}
