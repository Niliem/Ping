#pragma once
#include "Entity.hpp"
class Paddle 
	: public Entity
{
public:
	Paddle(float w, float h, float x, float y, float speed);
	~Paddle();

	void update(sf::RenderWindow* window, float ft);
	bool isUp;
	bool isDown;

private:
	float mSpeed;
};

