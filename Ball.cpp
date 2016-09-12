#include "Ball.h"
#include "sfwdraw.h"
#include <cstdlib>
#include <iostream>

using namespace sfw;


Ball::Ball()
{
	initBall();
}

Ball::~Ball()
{
}

void Ball::initBall()
{
	setXPos(400);
	setYPos(300);
	setXVel(100);
	setYVel(100);

	setIsXPos(true);
	setIsYPos(true);
}

void Ball::updateBall(Paddle& paddle, float x, float y)
{
	//X-movement
	isXPos ? xPos += getDeltaTime()*xVel : xPos -= getDeltaTime()*xVel;

	//X-collision with wall
	if (xPos >= x) {
		isXPos = false;
		randVelocity(yVel, 180, true);
	}

	//X-collision with paddle.  Paddle collision extended 10 pixels above actual paddle
	if (xPos <= paddle.getXPos()+5 && xPos > 10 && (yPos <= paddle.getYPosUp() + 10 && yPos >= paddle.getYPosDown() + 10)) {
		isXPos = true;
		randVelocity(yVel, 80, true);
		std::cout << "Score: " << ++paddle.score << std::endl;
		xVel += 25;
	}

	//Reset ball collision
	if (xPos < 0) {
		xPos = 400;
		yPos = 300;
		xVel = 100;
		isXPos = true;
		randVelocity(yVel, 180, true);
		if (paddle.score >= 100) {
			//After 101 it glitches through the paddle, so I'm setting 100 to a 'win'.
			printf("\nYou win!\n");
		}
		paddle.score = 0;
	}

	//Y-movement
	isYPos ? yPos += getDeltaTime()*yVel : yPos -= getDeltaTime()*yVel;

	//Y-collision with ceiling
	if (yPos >= y) {
		isYPos = false;
		randVelocity(yVel, 90, false);
	}
	//Y-collision with floor
	if (yPos <= 0) {
		isYPos = true;
		randVelocity(yVel, 90, false);
	}
}

void Ball::drawBall(int choice, unsigned int color)
{
	switch (choice)
	{
	case 0:
		//Empty circle
		drawCircle(xPos, yPos, 8, 15, color);
		break;
	case 1:
		//Filled circle
		for (int i = 8; i > 0; i--)
		{
			drawCircle(xPos, yPos, i, 15, color);
		}
		break;
	case 2:
		//GLOWY circle
		drawCircle(xPos, yPos, 9, 15, 0x00ffff20);
		drawCircle(xPos, yPos, 8, 15, 0x00ffff50);
		drawCircle(xPos, yPos, 7, 15, 0x00ffff80);
		drawCircle(xPos, yPos, 6, 15, 0x00ffffc0);
		drawCircle(xPos, yPos, 5, 15, 0xFFFFFF80);
		drawCircle(xPos, yPos, 4, 15, 0xFFFFFF60);
		drawCircle(xPos, yPos, 3, 15, 0xFFFFFF40);
		drawCircle(xPos, yPos, 2, 15, 0xFFFFFF20);
		drawCircle(xPos, yPos, 1, 15, 0xFFFFFF05);
		break;
	}
}

void Ball::randVelocity(float& inVel, int maxRange, bool canNeg)
{

	if (!canNeg) {
		inVel = rand() % maxRange + 1;
	}
	else {
		//This effectively allows for a negative range.
		inVel = rand() % (maxRange * 2) + 1;
		inVel -= maxRange;
	}
}

float Ball::getXPos() const
{
	return xPos;
}

void Ball::setXPos(float num)
{
	xPos = num;
}

float Ball::getYPos() const
{
	return yPos;
}

void Ball::setYPos(float num)
{
	yPos = num;
}

float Ball::getXVel() const
{
	return xVel;
}

void Ball::setXVel(float num)
{
	xVel = num;
}

float Ball::getYVel() const
{
	return yVel;
}

void Ball::setYVel(float num)
{
	yVel = num;
}

bool Ball::getIsXPos() const
{
	return isXPos;
}

void Ball::setIsXPos(bool in)
{
	isXPos = in;
}

bool Ball::getIsYPos() const
{
	return isYPos;
}

void Ball::setIsYPos(bool in)
{
	isYPos = in;
}
