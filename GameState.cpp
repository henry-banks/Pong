#include "GameState.h"
#include "sfwdraw.h"


void GameState::initGameState()
{
	player.initPaddle(30, 30, 3);
	ball.initBall();
}

void GameState::updateGameState()
{
	player.updatePaddle();
	ball.updateBall(player, 800, 600);
}

void GameState::drawGameState()
{
	player.drawPaddle(BLUE);
	ball.drawBall(2, CYAN);
}

Paddle GameState::getPaddle() const
{
	return player;
}

Ball GameState::getBall() const
{
	return ball;
}

float GameState::getTopBound() const
{
	return topBound;
}

void GameState::setTopBound(float num)
{
	topBound = num;
}

float GameState::getBottomBound() const
{
	return bottomBound;
}

void GameState::setBottomBound(float num)
{
	bottomBound = num;
}

int GameState::getScore() const
{
	return score;
}

void GameState::setScore(int num)
{
	score = num;
}
