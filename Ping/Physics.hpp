#pragma once

#include "Entity.hpp"

class Physics
{
public:
	static bool isIntersection(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);
	static void Collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);
};

