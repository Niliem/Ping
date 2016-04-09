#pragma once

#include "Entity.hpp"

class Ball
	: public Entity
{
public:
	Ball();
	Ball(float x, float y, float vx, float vy);
	//void setPosition(float x, float y);
	void setVelocity(float vx, float vy);
	~Ball();

	void update(sf::RenderWindow* window, float ft);
};

