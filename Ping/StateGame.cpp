#include "StateGame.hpp"


StateGame::StateGame(sf::RenderWindow* window)
	:mBall{10.0f, 10.0f, 40.0f, 100.0f, 0.1, 0.2}
{
	mWindow = window;
}

StateGame::~StateGame()
{
}

void StateGame::handleEvent()
{
	mBall.isRun = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void StateGame::update(float ft)
{
	mBall.update(mWindow);
}

void StateGame::render()
{
	mWindow->draw(mBall.shape);
}
