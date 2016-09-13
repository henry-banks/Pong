#include "GameState.h"
#include "sfwdraw.h"


void GameState::initGameState()
{
	player.initPaddle(30, 30, 3);
	ball.initBall();

	for (int i = 0; i < 5; i++)
	{
		Particle newParticle;
		particles.push_back(newParticle);
	}
}

void GameState::updateGameState()
{
	player.updatePaddle();
	ball.updateBall(player, 800, 600);
	for (int i = 0; i < 5; i++)
	{
			particles[i].updateParticle();
	}

	if (ball.spawnParticles) {
		spawnParticles(ball);
		ball.spawnParticles = false;
	}
}

void GameState::drawGameState()
{
	player.drawPaddle(BLUE);
	ball.drawBall(2, CYAN);
	for (int i = 0; i < 5; i++)
	{
		if (particles[i].getActive()) {
			particles[i].drawParticle(YELLOW);
		}
	}
}

Paddle GameState::getPaddle() const
{
	return player;
}

Ball GameState::getBall() const
{
	return ball;
}

void GameState::spawnParticles(Ball inBall)
{
	for (int i = 0; i < 5; i++)
	{
		particles[i].resetParticle(inBall.getXPos(), inBall.getYPos(), 1);
	}
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
