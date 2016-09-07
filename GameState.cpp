#include "GameState.h"

GameState initGameState()
{
	GameState newState;
	newState.player = initPaddle(30, 30, 3);

	return newState;
}
