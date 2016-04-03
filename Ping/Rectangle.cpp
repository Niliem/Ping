#include "Rectangle.hpp"


float Rectangle::x() const noexcept
{
	return this->mShape.getPosition().x;
}

float Rectangle::y() const noexcept
{
	return this->mShape.getPosition().y;
}

float Rectangle::left() const noexcept
{
	return (this->x() - this->mShape.getSize().x / 2.0f);
}

float Rectangle::right() const noexcept
{
	return (this->x() + this->mShape.getSize().x / 2.0f);
}

float Rectangle::top() const noexcept
{
	return (this->y() - this->mShape.getSize().y / 2.0f);
}

float Rectangle::bottom() const noexcept
{
	return (this->y() + this->mShape.getSize().y / 2.0f);
}

sf::RectangleShape Rectangle::getShape() const noexcept
{
	return mShape;
}
