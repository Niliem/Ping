#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class State
{
public:
	virtual void handleEvent() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;

protected:
	sf::RenderWindow* mWindow;
};