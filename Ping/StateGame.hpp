#pragma once

#include <iostream>
#include "State.hpp"
#include "Ball.hpp"


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
	Ball actor;

};

