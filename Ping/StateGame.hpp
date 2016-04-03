#pragma once

#include <iostream>
#include <vector>
#include "State.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Physics.hpp"

class StateGame :
	public State
{
public:
	StateGame(sf::RenderWindow* window);
	~StateGame();

	void handleEvent();
	void update(float ft);
	void render();

private:
	Ball mBall;
	Paddle mPlayer1;
	Paddle mPlayer2;
};

