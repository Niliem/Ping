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
	std::shared_ptr<Ball> mBall;
	std::shared_ptr<Paddle> mPlayer1;
	std::shared_ptr<Paddle> mPlayer2;

	std::vector<std::shared_ptr<Entity>> mActors;
};

