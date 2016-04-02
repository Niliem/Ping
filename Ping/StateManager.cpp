#include "StateManager.hpp"

std::shared_ptr<State> StateManager::mCurrentState = nullptr;

void StateManager::setState(std::shared_ptr<State> newState)
{
	mCurrentState = newState;
}

void StateManager::handleEvent()
{
	if(mCurrentState != nullptr)
		mCurrentState->handleEvent();
}

void StateManager::update(float ft)
{
	if (mCurrentState != nullptr)
		mCurrentState->update(ft);
}

void StateManager::render(sf::RenderWindow* window)
{
	if (mCurrentState != nullptr)
		mCurrentState->render(window);
}
