#include "Paddle.h"
#include "sfwdraw.h"

using namespace sfw;

void Paddle::drawPaddle(float height, unsigned int color)
{
	//For-loop didn't want to work, sticking with statick width of 3
	drawLine(xPos, yPos + height, xPos, yPos - height, color);
	drawLine(xPos - 1, yPos + height, xPos - 1, yPos - height, color);
	drawLine(xPos - 2, yPos + height, xPos - 2, yPos - height, color);
}

void Paddle::updatePaddle()
{
	yPos = getMouseY();
	yPosUp = yPos + 40;
	yPosDown = yPos - 40;
}

Paddle initPaddle(float inXPos, float inHeight, float inWidth)
{
	Paddle newPaddle;

	newPaddle.xPos = inXPos;

	newPaddle.height = inHeight;
	newPaddle.width = inWidth;

	return newPaddle;
}
