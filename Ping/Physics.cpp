#include "Physics.hpp"

bool Physics::isIntersection(Rectangle& r1, Rectangle& r2)
{
	return r1.right() >= r2.left() && 
			r1.left() <= r2.right() && 
			r1.bottom() >= r2.top() && 
			r1.top() <= r2.bottom();
}

void Physics::Collision(Entity & e1, Entity & e2)
{
	if (!isIntersection(e1, e2))
		return;

	float overlapLeft = e2.right() - e1.left();
	float overlapRight = e1.right() - e2.left();
	float overlapTop = e2.bottom() - e1.top();
	float overlapBottom = e1.bottom() - e2.top();

	bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
	bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

	float overlapX = fromLeft ? overlapLeft : overlapRight;
	float overlapY = fromTop ? overlapTop : overlapBottom;

	if (std::abs(overlapX) < std::abs(overlapY))
	{
		e1.mVelocity.x *= -1;
		e2.mVelocity.x *= -1;
	}
	else
	{
		e1.mVelocity.y *= -1;
		e2.mVelocity.y *= -1;
	}
}
