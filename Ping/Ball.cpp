#include "Ball.hpp"


Ball::Ball(float w, float h, float x, float y, float vx, float vy)
{
	this->shape.setPosition(x, y);
	this->shape.setSize({ w, h });
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setOrigin(w / 2.0f, h / 2.0f);
	this->mVelocity = { vx, vy };
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow* window, float ft)
{
	this->shape.move(this->mVelocity * ft);

	if (this->x() < 0 || this->x() > window->getSize().x)
		this->mVelocity.x *= -1;
	if (this->y() < 0 || this->y() > window->getSize().y)
		this->mVelocity.y *= -1;
}
