#pragma once

#include <SFML/Graphics.hpp>

class Rectangle
{
public:
	float x() const noexcept;
	float y() const noexcept;
	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	sf::RectangleShape getShape() const noexcept;

private:
	sf::RectangleShape mShape;
};

