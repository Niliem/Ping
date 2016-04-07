#pragma once

#include "Rectangle.hpp"

class Entity
	: public Rectangle
{
public:
	virtual void update(sf::RenderWindow* window, float ft) = 0;
	sf::Vector2f mVelocity;
};

