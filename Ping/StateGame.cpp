#include "StateGame.hpp"


StateGame::StateGame(sf::RenderWindow* window)
	:actor{10.0f, 10.0f, 40.0f, 100.0f, 0.1, 0.2}
{
	mWindow = window;
}

StateGame::~StateGame()
{
}

void StateGame::handleEvent()
{
	actor.isRun = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void StateGame::update(float ft)
{
	actor.update(mWindow);
}

void StateGame::render()
{
	mWindow->draw(actor.getShape());
}
