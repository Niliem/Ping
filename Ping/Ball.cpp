#include "Ball.hpp"
#include "Score.hpp"


Ball::Ball()
	: resetGame{false}
{
	setPosition(0.0f, 0.0f);
	velocity = { 0.0f, 0.0f };

	mStartX = 0.0f;
	mStartY = 0.0f;
	mStartVelocity = { 0.0f, 0.0f };
}

Ball::Ball(float x, float y, float vx = 0.0f, float vy = 0.0f)
	: resetGame{ false }
{
	setPosition(x, y);
	velocity = { vx, vy };

	mStartX = x;
	mStartY = y;
	mStartVelocity = { vx, vy };
}

void Ball::setVelocity(float vx, float vy)
{
	velocity = { vx, vy };
	mStartVelocity = { vx, vy };
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow* window, float deltaTime)
{
	move(velocity * deltaTime);

	if (left() < 0)
	{
		velocity.x *= -1;
		Score::addScore(SCORE::FIRST);
		resetGame = true;
	}
	else if (right() > window->getSize().x)
	{
		velocity.x *= -1;
		Score::addScore(SCORE::SECOND);
		resetGame = true;
	}

	if (top() < 0 || bottom() > window->getSize().y)
		velocity.y *= -1;
}

void Ball::reset()
{
	setPosition(mStartX, mStartY);
	velocity = mStartVelocity;
}
