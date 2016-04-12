#include "Physics.hpp"

void Physics::Collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
	if (!e1->checkCollision(e2))
		return;

	auto overlapLeft = e2->right() - e1->left();
	auto overlapRight = e1->right() - e2->left();
	auto overlapTop = e2->bottom() - e1->top();
	auto overlapBottom = e1->bottom() - e2->top();

	auto fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
	auto fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

	auto overlapX = fromLeft ? overlapLeft : overlapRight;
	auto overlapY = fromTop ? overlapTop : overlapBottom;

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
