#pragma once

#include <iostream>
#include "State.hpp"


class StateMenu :
	public State
{
public:
	StateMenu();
	~StateMenu();

	void handleEvent();
	void update(float ft);
	void render(sf::RenderWindow* window);

private:

};

