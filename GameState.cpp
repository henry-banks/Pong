#include "GameState.h"
#include "sfwdraw.h"

GameState initGameState()
{
	GameState newState;
	newState.player = initPaddle(30, 30, 3);
	newState.ball = initBall();

	return newState;
}

void updateGameState(GameState& gs)
{
	gs.player.updatePaddle();
	gs.ball.updateBall(gs.player, 800, 600);
}

void drawGameState(GameState& gs)
{
	gs.player.drawPaddle(30, BLUE);
	gs.ball.drawBall(2, CYAN);
}
