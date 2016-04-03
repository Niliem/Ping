#pragma once

#include <SFML/Graphics.hpp>

class TestActor
{
public:
	TestActor(int w, int h, int x, int y, float vx, float vy);
	~TestActor();

	sf::RectangleShape shape;
	sf::Vector2f velocity;

	void update(sf::RenderWindow* window);
	bool isRun;
};

