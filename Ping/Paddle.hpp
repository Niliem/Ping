#pragma once
#include "Entity.hpp"
class Paddle 
	: public Entity
{
public:
	Paddle();
	Paddle(float x, float y, float speed);
	~Paddle();

	//void setPosition(float x, float y);
	void setSpeed(float speed);
	void update(sf::RenderWindow* window, float ft);
	bool isUp;
	bool isDown;

private:
	float mSpeed;
};

