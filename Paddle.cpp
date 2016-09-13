#include "Paddle.h"
#include "sfwdraw.h"
#include <iostream>

using namespace sfw;

Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

void Paddle::initPaddle(float inXPos, float inHeight, float inWidth)
{
	score = 0;
	highScore = 0;

	xPos = inXPos;
	height = inHeight;
	width = inWidth;
}

void Paddle::drawPaddle(unsigned int color)
{
	//For-loop didn't want to work, sticking with statick width of 3
	drawLine(xPos, yPosUp, xPos, yPosDown, color);
	drawLine(xPos - 1, yPosUp, xPos - 1, yPosDown, color);
	drawLine(xPos - 2, yPosUp, xPos - 2, yPosDown, color);
}

void Paddle::updatePaddle()
{
	yPos = getMouseY();
	yPosUp = yPos + height;
	yPosDown = yPos - height;
}

float Paddle::getXPos() const
{
	return xPos;
}

void Paddle::setXPos(float num)
{
	xPos = num;
}

float Paddle::getYPos() const
{
	return yPos;
}

void Paddle::setYPos(float num)
{
	yPos = num;
}

float Paddle::getYPosUp() const
{
	return yPosUp;
}

float Paddle::getYPosDown() const
{
	return yPosDown;
}

float Paddle::getScore() const
{
	return score;
}

void Paddle::setScore(float num)
{
	score = num;
}

float Paddle::getWidth() const
{
	return width;
}

void Paddle::setWidth(float num)
{
	width = num;
}

float Paddle::getHeight() const
{
	return height;
}

void Paddle::setHeight(float num)
{
	height = num;
}

void Paddle::resetScore()
{
	if (score > highScore) {
		highScore = score;
	}
	score = 0;
}

int Paddle::getHighScore() const
{
	return highScore;
}
