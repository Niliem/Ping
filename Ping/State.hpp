#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class State
{
public:
	virtual void handleEvent() = 0;
	virtual void update(float ft) = 0;
	virtual void render() = 0;

	sf::RenderWindow* mWindow;
};