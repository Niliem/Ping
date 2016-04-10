#include "Score.hpp"

int Score::mScore[SECOND + 1] = {};

void Score::resetScore()
{
	mScore[SECOND+1] = {0};
}

void Score::addScore(SCORE score)
{
	mScore[score]++;
}

int Score::getScore(SCORE score)
{
	return mScore[score];
}
