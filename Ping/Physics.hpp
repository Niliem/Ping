#pragma once

#include "Entity.hpp"

class Physics
{
public:
	static bool isIntersection(Rectangle& r1, Rectangle& r2);
	static void Collision(Entity& e1, Entity& e2);

};

