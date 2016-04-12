#pragma once

#include <SFML/Graphics.hpp>

class State
{
public:
	explicit State(sf::RenderWindow* m_window);
	virtual ~State(){};

	virtual void handleEvent() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;

protected:
	sf::RenderWindow* mWindow;
};