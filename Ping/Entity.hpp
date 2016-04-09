#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Entity
	: public sf::Sprite
{
public:
	void Load(std::string filename);
	virtual void update(sf::RenderWindow * window, float ft) = 0;
	bool checkCollision(std::shared_ptr<Entity> e);

	float x() const noexcept;
	float y() const noexcept;
	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	sf::Vector2f velocity;

protected:	
	std::shared_ptr<sf::Texture> mTexture;
};

