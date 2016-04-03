#include "Paddle.hpp"



Paddle::Paddle(float w, float h, float x, float y, float speed)
	: isUp{ false }
	, isDown{false}
	, mSpeed{ speed }
{
	this->shape.setPosition(x, y);
	this->shape.setSize({ w, h });
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setOrigin(w / 2.0f, h / 2.0f);
	this->mVelocity = { 0, 0 };
}

Paddle::~Paddle()
{
}

void Paddle::update(sf::RenderWindow * window, float ft)
{
	this->shape.move(this->mVelocity * ft);

	if (isUp && this->top() > 0)
		this->mVelocity.y = -mSpeed;
	else if (isDown && this->bottom() < window->getSize().y)
		this->mVelocity.y = mSpeed;
	else this->mVelocity.y = 0;


}
