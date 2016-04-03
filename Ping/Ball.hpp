#pragma once

#include "Rectangle.hpp"

class Ball
	: public Rectangle
{
public:
	Ball(float w, float h, float x, float y, float vx, float vy);
	~Ball();

	void update(sf::RenderWindow* window);
	bool isRun;

private:
	sf::Vector2f mVelocity;
};

