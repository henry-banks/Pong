#pragma once
#include "Paddle.h"
struct Ball
{
	float xPos = 400, yPos = 300;
	float xVel = 100, yVel = 100;

	bool isXPos = true, isYPos = true;

	/*Checks to see if ball has collided with a corner
	Paddle: The player's paddle.  Used to see if the ball has hit the paddle
	x: x-boundry of the window.  Used to check for ceiling/floor collision
	y: y-boundry of the window.  Used to check for wall collision*/
	void updateBall(Paddle& paddle, float x, float y);

	/*Draws trhe ball
	choice: Draws a different type of ball based on integer given
		0: empty circle
		1: filled circle
		3: 'glowing' cyan circle
	color: hexidecimal color of ball
	*/
	void drawBall(int choice, unsigned int color);

	/*Creates a random velocity within the range (in degrees) given.
	inVel: Velocity to change (use ballName.xVel/yVel)
	maxRange: The maximum range (in degrees) that the new velocity can be.
	canNeg: Whether or not the velocity can be negative (set to false if bouncing off floor/ceiling).
	*/
	void randVelocity(float& inVel, int maxRange, bool canNeg);
};

Ball initBall();