#pragma once
struct Paddle
{
	float xPos = 30, yPos = 400;

	//Upper and Lower collision, extends 10 px above/below paddle
	float yPosUp = yPos + 40;
	float yPosDown = yPos - 40;

	int score = 0;
	int width = 1;
	int height = 30;

	/*Draws the given paddle*/
	void drawPaddle();

};


/*Initializes a new paddle.
inXPos: The x-position of the paddle.  Used as the FRONT of the paddle when calculating width.
inSize: The Height of the paddle (will always be odd)
inWidth: The width of the paddle*/
Paddle initPaddle(float inXPos, float inHeight, float inWidth);