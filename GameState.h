#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "Particle.h"
#include "constdecl.h"
#include <vector>

class GameState
{
	Paddle player;
	Ball ball;
	std::vector<Particle> particles;
	float topBound, bottomBound;

	int score;

public:

	//Setup starting values.
	void initGameState();

	/*Call update and collision functions.
	Also, check for anythign that isn't part of a struct*/
	void updateGameState();

	//Drawing functions (if they work...)
	void drawGameState();

	Paddle getPaddle() const;
	Ball getBall() const;

	void spawnParticles(Ball inBall);

	float getTopBound() const;
	void setTopBound(float num);

	float getBottomBound() const;
	void setBottomBound(float num);

	int getScore() const;
	void setScore(int num);

	EState next();
};
