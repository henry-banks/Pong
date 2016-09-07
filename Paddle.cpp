#include "Paddle.h"
#include "sfwdraw.h"

void Paddle::drawPaddle()
{
	for (int i = width; i < 0; i++)
	{
		sfw::drawLine(xPos, yPos + height, xPos, yPos - height, BLUE);
	}
}

Paddle initPaddle(float inXPos, float inHeight, float inWidth)
{
	Paddle newPaddle;

	newPaddle.xPos = inXPos;

	newPaddle.height = inHeight;
	newPaddle.width = inWidth;

	return newPaddle;
}
