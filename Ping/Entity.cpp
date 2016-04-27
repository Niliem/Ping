#include "Entity.hpp"


Entity::Entity()
	: mStartX(0)
	, mStartY(0)
	, mStartVelocity{0, 0}
{
}

void Entity::Load(std::string filename)
{
	mTexture = std::make_shared<sf::Texture>();
	mTexture->loadFromFile("Data/Graphics/Sprites/" + filename);
	setTexture(*mTexture);
	setOrigin({ getGlobalBounds().width / 2.0f, getGlobalBounds().height / 2.0f });
}

bool Entity::checkCollision(std::shared_ptr<Entity> e) const
{
	return getGlobalBounds().intersects(e->getGlobalBounds());
}

float Entity::x() const noexcept
{
	return getPosition().x;
}

float Entity::y() const noexcept
{
	return getPosition().y;
}

float Entity::left() const noexcept
{
	return (x() - getGlobalBounds().width / 2.0f);
}

float Entity::right() const noexcept
{
	return (x() + getGlobalBounds().width / 2.0f);
}

float Entity::top() const noexcept
{
	return (y() - getGlobalBounds().height / 2.0f);
}

float Entity::bottom() const noexcept
{
	return (y() + getGlobalBounds().height / 2.0f);
}
