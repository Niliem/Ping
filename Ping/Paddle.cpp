#include "Paddle.hpp"


Paddle::Paddle()
	: isUp{ false }
	, isDown{ false }
	, mSpeed{ 0.0f }
{
	setPosition(0.0f, 0.0f);
	velocity = { 0, 0 };
}

Paddle::Paddle(float x, float y, float speed)
	: isUp{ false }
	, isDown{false}
	, mSpeed{ speed }
{
	setPosition(x, y);
	velocity = { 0, 0 };

	mStartX = x;
	mStartY = y;
	mStartVelocity = { 0, 0 };
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
	move(velocity * deltaTime);

	if (isUp && top() > 0)
		velocity.y = -mSpeed;
	else if (isDown && bottom() < window->getSize().y)
		velocity.y = mSpeed;
	else velocity.y = 0;
}

void Paddle::reset()
{
	setPosition(mStartX, mStartY);
}
