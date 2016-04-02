#pragma once

#include "State.hpp"

class StateManager
{
public:
	static void setState(std::shared_ptr<State> newState);

	static void handleEvent();
	static void update(float ft);
	static void render(sf::RenderWindow* window);

private:
	static std::shared_ptr<State> mCurrentState;
};


