#include "Ball.hpp"


Ball::Ball(float w, float h, float x, float y, float vx, float vy)
{
	this->getShape().setPosition(x, y);
	this->getShape().setSize({ w, h });
	this->getShape().setFillColor(sf::Color::Red);
	this->getShape().setOrigin(w / 2.0f, h / 2.0f);
	this->mVelocity = { vx, vy };
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow* window)
{
	if (this->isRun)
	{
		this->getShape().move(this->mVelocity);

		if (this->x() < 0 || this->x() > window->getSize().x)
			this->mVelocity.x *= -1;
		if (this->y() < 0 || this->y() > window->getSize().y)
			this->mVelocity.y *= -1;
	}
}
