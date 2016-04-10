#pragma once

enum SCORE
{
	FIRST, SECOND
};

class Score
{
public:
	static void resetScore();
	static void addScore(SCORE score);
	static int getScore(SCORE score);

private:
	static int mScore[SECOND+1];
};

