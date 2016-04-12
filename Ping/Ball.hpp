#pragma once

#include "Entity.hpp"
#include "Score.hpp"

class Ball
	: public Entity
{
public:
	Ball();
	Ball(float x, float y, float vx, float vy);	
	~Ball();

	void setVelocity(float vx, float vy);

	void update(sf::RenderWindow* window, float deltaTime);
	void reset();

	bool resetGame;
};

