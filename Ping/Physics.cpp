#include "Physics.hpp"

bool Physics::isIntersection(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
	return e1->getGlobalBounds().intersects(e2->getGlobalBounds());
}

void Physics::Collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
	if (!isIntersection(e1, e2))
		return;

	float overlapLeft = e2->right() - e1->left();
	float overlapRight = e1->right() - e2->left();
	float overlapTop = e2->bottom() - e1->top();
	float overlapBottom = e1->bottom() - e2->top();

	bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
	bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

	float overlapX = fromLeft ? overlapLeft : overlapRight;
	float overlapY = fromTop ? overlapTop : overlapBottom;

	if (std::abs(overlapX) < std::abs(overlapY))
	{
		e1->velocity.x *= -1;
		e2->velocity.x *= -1;
	}
	else
	{
		e1->velocity.y *= -1;
		e2->velocity.y *= -1;
	}
}
