#pragma once

#include "Entity.hpp"

class Physics
{
public:
	static void Collision(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);
};

