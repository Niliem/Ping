#include "Paddle.hpp"


Paddle::Paddle()
	: isUp{ false }
	, isDown{ false }
	, mSpeed{ 0.0f }
{
	this->setPosition(0.0f, 0.0f);
	this->velocity = { 0, 0 };
}

Paddle::Paddle(float x, float y, float speed)
	: isUp{ false }
	, isDown{false}
	, mSpeed{ speed }
{
	this->setPosition(x, y);
	this->velocity = { 0, 0 };

	this->mStartX = x;
	this->mStartY = y;
	this->mStartVelocity = { 0, 0 };
}

Paddle::~Paddle()
{
}

void Paddle::setSpeed(float speed)
{
	mSpeed = speed;
}

void Paddle::update(sf::RenderWindow* window, float deltaTime)
{
	this->move(this->velocity * deltaTime);

	if (isUp && this->top() > 0)
		this->velocity.y = -mSpeed;
	else if (isDown && this->bottom() < window->getSize().y)
		this->velocity.y = mSpeed;
	else this->velocity.y = 0;


}

void Paddle::reset()
{
	this->setPosition(this->mStartX, this->mStartY);
}
