#pragma once

#include "Entity.hpp"

class Ball
	: public Entity
{
public:
	Ball(float w, float h, float x, float y, float vx, float vy);
	~Ball();

	void update(sf::RenderWindow* window, float ft);
};

