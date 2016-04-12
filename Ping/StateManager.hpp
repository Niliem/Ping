#pragma once

#include "State.hpp"
#include <memory>

class StateManager
{
public:
	static void setState(std::shared_ptr<State> newState);

	static void handleEvent();
	static void update(float deltaTime);
	static void render();

private:
	static std::shared_ptr<State> mCurrentState;
};


