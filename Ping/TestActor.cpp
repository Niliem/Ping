#include "TestActor.hpp"


TestActor::TestActor(int w, int h, int x, int y, float vx, float vy)
	: isRun{ false }
{
	velocity.x = vx;
	velocity.y = vy;
	shape.setSize(sf::Vector2f(w, h));
}

TestActor::~TestActor()
{
}

void TestActor::update(sf::RenderWindow* window)
{
	if (isRun)
	{
		shape.move(velocity);

		if (shape.getPosition().x < 0 || shape.getPosition().x > window->getSize().x)
			velocity.x *= -1;
		if (shape.getPosition().y < 0 || shape.getPosition().y > window->getSize().y)
			velocity.y *= -1;
	}
}
