#pragma once
#include "Paddle.h"
#include "Ball.h"

struct GameState
{
	Paddle player;
	Ball ball;
	float topBound, bottomBound;

	int score;
};
//Setup starting values.
GameState initGameState();

/*Call update and collision functions.
Also, check for anythign that isn't part of a struct*/
void updateGameState(GameState &gs);

//Drawing functions (if they work...)
void drawGameState(GameState &gs);