#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "State.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Physics.hpp"
#include "Score.hpp"

class StateGame :
	public State
{
public:
	StateGame(sf::RenderWindow* window);
	~StateGame();

	void handleEvent();
	void update(float deltaTime);
	void render();

private:
	std::shared_ptr<Ball> mBall;
	std::shared_ptr<Paddle> mPlayer1;
	std::shared_ptr<Paddle> mPlayer2;

	std::vector<std::shared_ptr<Entity>> mActors;

	bool reset;
};

