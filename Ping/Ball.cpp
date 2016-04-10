#include "Ball.hpp"


Ball::Ball()
{
	this->setPosition(0.0f, 0.0f);
	this->velocity = { 0.0f, 0.0f };

	this->mStartX = 0.0f;
	this->mStartY = 0.0f;
	this->mStartVelocity = { 0.0f, 0.0f };
}

Ball::Ball(float x, float y, float vx = 0.0f, float vy = 0.0f)
{
	this->setPosition(x, y);
	this->velocity = { vx, vy };

	this->mStartX = x;
	this->mStartY = y;
	this->mStartVelocity = { vx, vy };
}

void Ball::setVelocity(float vx, float vy)
{
	this->velocity = { vx, vy };
	this->mStartVelocity = { vx, vy };
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow* window, float ft)
{
	this->move(this->velocity * ft);

	if (this->left() < 0 || this->right() > window->getSize().x)
		this->velocity.x *= -1;
	if (this->top() < 0 || this->bottom() > window->getSize().y)
		this->velocity.y *= -1;
}

void Ball::reset()
{
	this->setPosition(this->mStartX, this->mStartY);
	this->velocity = this->mStartVelocity;
}
