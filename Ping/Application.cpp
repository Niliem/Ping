#include "Application.hpp"



Application::Application()
	: mWindow{ {640, 480}, "Ping pong" }
{
}


Application::~Application()
{
}

void Application::run()
{
	while (mWindow.isOpen())
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
}

void Application::render()
{
	mWindow.clear();

	mWindow.display();
}
