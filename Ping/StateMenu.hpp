#pragma once

#include <iostream>
#include "State.hpp"
#include "TestActor.hpp"


class StateMenu :
	public State
{
public:
	StateMenu(sf::RenderWindow* window);
	~StateMenu();

	void handleEvent();
	void update(float ft);
	void render();

private:
	TestActor actor;

};

