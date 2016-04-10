#pragma once

#include "Entity.hpp"

class Paddle 
	: public Entity
{
public:
	Paddle();
	Paddle(float x, float y, float speed);
	~Paddle();

	void setSpeed(float speed);

	void update(sf::RenderWindow* window, float ft);
	void reset();

	bool isUp;
	bool isDown;

private:
	float mSpeed;
};

