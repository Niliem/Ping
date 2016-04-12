#include "Entity.hpp"


Entity::Entity()
	: mStartX(0)
	, mStartY(0)
	, mStartVelocity{0, 0}
{
}

void Entity::Load(std::string filename)
{
	this->mTexture = std::make_shared<sf::Texture>();
	this->mTexture->loadFromFile("Data/Graphics/Sprites/" + filename);
	this->setTexture(*this->mTexture);
	this->setOrigin({ this->getGlobalBounds().width / 2.0f, this->getGlobalBounds().height / 2.0f });
}

bool Entity::checkCollision(std::shared_ptr<Entity> e) const
{
	return this->getGlobalBounds().intersects(e->getGlobalBounds());
}

float Entity::x() const noexcept
{
	return this->getPosition().x;
}

float Entity::y() const noexcept
{
	return this->getPosition().y;
}

float Entity::left() const noexcept
{
	return (this->x() - this->getGlobalBounds().width / 2.0f);
}

float Entity::right() const noexcept
{
	return (this->x() + this->getGlobalBounds().width / 2.0f);
}

float Entity::top() const noexcept
{
	return (this->y() - this->getGlobalBounds().height / 2.0f);
}

float Entity::bottom() const noexcept
{
	return (this->y() + this->getGlobalBounds().height / 2.0f);
}
