#include "StateGame.hpp"


StateGame::StateGame(sf::RenderWindow* window)
	: mBall{20.0f, 20.0f, window->getSize().x / 2.0f,  window->getSize().y / 2.0f, 0.1, 0.2}
	, mPlayer1{ 15.0f, 70.0f, 50.0f,  window->getSize().y / 2.0f, 0.3 }
	, mPlayer2{ 15.0f, 70.0f, window->getSize().x - 50.0f,  window->getSize().y / 2.0f, 0.3 }
{
	//mActors.push_back(mBall);
	//mActors.push_back(mPlayer1);
	//mActors.push_back(mPlayer2);

	mWindow = window;
}

StateGame::~StateGame()
{
}

void StateGame::handleEvent()
{
	mPlayer1.isUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	mPlayer1.isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	mPlayer2.isUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	mPlayer2.isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void StateGame::update(float ft)
{
	mBall.update(mWindow, ft);
	mPlayer1.update(mWindow, ft);
	mPlayer2.update(mWindow, ft);

	//for (auto& a : mActors)
	//	a.update(mWindow, ft);

	Physics::Collision(mBall, mPlayer1);
	Physics::Collision(mBall, mPlayer2);
}

void StateGame::render()
{
	mWindow->draw(mBall.shape);
	mWindow->draw(mPlayer1.shape);
	mWindow->draw(mPlayer2.shape);
	
	//for (auto& a : mActors)
	//	mWindow->draw(a.);

}
