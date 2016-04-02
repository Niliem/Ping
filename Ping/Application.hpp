#pragma once

#include "StateManager.hpp"
#include "StateMenu.hpp"

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
};

