#pragma once

#include <vector>

#include "State.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class StateGame :
	public State
{
public:
	explicit StateGame(sf::RenderWindow* window);
	~StateGame();

	void handleEvent() override;
	void update(float deltaTime) override;
	void render() override;

private:
	std::shared_ptr<Ball> mBall;
	std::shared_ptr<Paddle> mPlayer1;
	std::shared_ptr<Paddle> mPlayer2;

	std::vector<std::shared_ptr<Entity>> mActors;

	bool reset;
};

