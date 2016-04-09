#include "StateGame.hpp"


StateGame::StateGame(sf::RenderWindow* window)
{
	mBall = std::make_shared<Ball>();
	mBall->setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
	mBall->setVelocity(0.1f, 0.2f);
	mBall->Load("ball.png");

	mPlayer1 = std::make_shared<Paddle>();
	mPlayer1->setPosition(50.0f, window->getSize().y / 2.0f);
	mPlayer1->setSpeed(0.3f);
	mPlayer1->Load("paddle1.png");

	mPlayer2 = std::make_shared<Paddle>(window->getSize().x - 50.0f, window->getSize().y / 2.0f, 0.3f);
	mPlayer2->Load("paddle2.png");
	
	mActors.push_back(mBall);
	mActors.push_back(mPlayer1);
	mActors.push_back(mPlayer2);

	mWindow = window;
}

StateGame::~StateGame()
{
}

void StateGame::handleEvent()
{
	mPlayer1->isUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	mPlayer1->isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	mPlayer2->isUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	mPlayer2->isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void StateGame::update(float ft)
{
	for (auto& a : mActors)
		a->update(mWindow, ft);

	Physics::Collision(mBall, mPlayer1);
	Physics::Collision(mBall, mPlayer2);
}

void StateGame::render()
{
	for (auto& a : mActors)
		mWindow->draw(*a);
}
