#include "Rectangle.hpp"


float Rectangle::x() const noexcept
{
	return this->shape.getPosition().x;
}

float Rectangle::y() const noexcept
{
	return this->shape.getPosition().y;
}

float Rectangle::left() const noexcept
{
	return (this->x() - this->shape.getSize().x / 2.0f);
}

float Rectangle::right() const noexcept
{
	return (this->x() + this->shape.getSize().x / 2.0f);
}

float Rectangle::top() const noexcept
{
	return (this->y() - this->shape.getSize().y / 2.0f);
}

float Rectangle::bottom() const noexcept
{
	return (this->y() + this->shape.getSize().y / 2.0f);
}

