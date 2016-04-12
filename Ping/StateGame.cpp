#include "StateGame.hpp"
#include "Score.hpp"
#include <sstream>
#include "Physics.hpp"


StateGame::StateGame(sf::RenderWindow* window)
	: State(window)
	, reset{false}
{
	mBall = std::make_shared<Ball>(window->getSize().x / 2.0f, window->getSize().y / 2.0f, 0.1f, 0.2f);
	mBall->Load("ball.png");

	mPlayer1 = std::make_shared<Paddle>(50.0f, window->getSize().y / 2.0f, 0.3f);
	mPlayer1->Load("paddle1.png");

	mPlayer2 = std::make_shared<Paddle>(window->getSize().x - 50.0f, window->getSize().y / 2.0f, 0.3f);
	mPlayer2->Load("paddle2.png");
	
	mActors.push_back(mBall);
	mActors.push_back(mPlayer1);
	mActors.push_back(mPlayer2);

	mWindow = window;
	Score::resetScore();
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

void StateGame::update(float deltaTime)
{
	if (mBall->resetGame)
	{
		for (auto& a : mActors)
			a->reset();
		mBall->resetGame = false;

		std::stringstream s;
		s << "Player 1: " << Score::getScore(SCORE::FIRST) << " - Player 2: " << Score::getScore(SCORE::SECOND);
		mWindow->setTitle(s.str());
	}

	for (auto& a : mActors)
		a->update(mWindow, deltaTime);

	Physics::Collision(mBall, mPlayer1);
	Physics::Collision(mBall, mPlayer2);	
}

void StateGame::render()
{
	for (auto& a : mActors)
		mWindow->draw(*a);
}
