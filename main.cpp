#include <iostream>	//just because ;D
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>	//for the randoms
#include <ctime>	//also for the randoms
#include <string>
#include "sfwdraw.h"

using namespace sfw;

//Original 'main' function that came with the project.
void origin()
{
	sfw::initContext(800,600,"NSFW Draw");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png",16,16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	float acc = 0;
	char c = '\0';

	sfw::setBackgroundColor(YELLOW);

	while (sfw::stepContext())
	{	
		sfw::drawString(f, " !\"#$%&'()*+,./-\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n`abcdefghijklmno\npqrstuvwxyz{|}~", 0, 600, 48, 48, 0, ' ');
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);

		acc += sfw::getDeltaTime();
		sfw::drawString(d, "TIME 4 FUN", 400, 300, 48, 48, -acc*24,'\0',MAGENTA);

		

		sfw::drawString(d, "6", 400, 32, 24, 24);
		sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
		sfw::drawString(d, "3", 800-32, 300, 24, 24);
		sfw::drawString(d, "9", 32, 300, 24, 24);

		if(sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2.5, sfw::getTextureHeight(u)/2.5,45,true,0,0x88ffffff);
		else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2, sfw::getTextureHeight(u)/2);
	}

	sfw::termContext();
}

/*Draws the paddle.
x: Origin x-coordinate
y: Origin y-coordinate
height: height of paddle
width: width of paddle (goes backwards from origin x)
*/

struct Ball
{
	float xPos = 400, yPos = 300;
	float xVel = 100, yVel = 100;

	bool isXPos = true, isYPos = true;
};

/*Creates a random velocity within the range (in degrees) given.
maxRange: The maximum range (in degrees) that the new velocity can be.
canNeg: Whether or not the velocity can be negative (set to false if bouncing off floor/ceiling).
*/
float randVelocity(int maxRange, bool canNeg)
{
	float newVel;

	if (!canNeg){
		newVel = rand() % maxRange + 1;
	}
	else {
		//This effectively allows for a negative range.
		newVel = rand() % (maxRange * 2) + 1;
		newVel -= maxRange;
	}
	return newVel;
}

struct Paddle
{
	float xPos = 30, yPos = 400;
	
	//Upper and Lower collision, extends 10 px above/below paddle
	float yPosUp = yPos + 40;
	float yPosDown = yPos - 40;

	int score = 0;
};

//Simple thingey
void customFunc1()
{
	//THE FOLLOWING IS A HORRIBLE MESS.  BEWARE.

	//Seed the randoms
	srand(time(0));

	initContext(800, 600, "The Worst Thing Ever Made");

	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);

	setBackgroundColor(0x222222FF);

	int paddleHeight = 30, paddleWidth = 3;

	//x value for paddle and wall
	float x = 30, x2 = 780;
	float y = 0, y2 = 0;

	Ball ball;
	Paddle paddle;

	while (stepContext())
	{
		//drawString(d, "HELLO.", 0, 600, 24, 24, 0, '\0', 0x33FFFFFF);

		paddle.yPos = getMouseY();
		paddle.yPosUp = paddle.yPos + 40;
		paddle.yPosDown = paddle.yPos - 40;

		//drawPaddle(x, y, 30, 3);  //THE FUNCTION DOESN'T WANT TO WORK ADSA.
		drawLine(paddle.xPos, paddle.yPos + 30, paddle.xPos, paddle.yPos - 30, BLUE);  
		drawLine(paddle.xPos - 1, paddle.yPos + 30, paddle.xPos - 1, paddle.yPos - 30, BLUE);
		drawLine(paddle.xPos - 2, paddle.yPos + 30, paddle.xPos - 2, paddle.yPos - 30, BLUE);

		//Opposite wall
		//drawLine(780, 0, 780, 800, RED);
		
		drawString(d, std::to_string(paddle.score).c_str(), 50, 600, 16, 16, 0, '\0', WHITE);

		

		//Middle line
		/*for (int i = 600; i > 0; i -= 40)
		{
			drawLine(400, i - 10, 400, i - 30, WHITE);
			drawLine(399, i - 10, 399, i - 30, WHITE);
		}*/

		//X-movement
		ball.isXPos ? ball.xPos += getDeltaTime()*ball.xVel : ball.xPos -= getDeltaTime()*ball.xVel;
		
		//X-collision with wall
		if (ball.xPos >= 800) {
			ball.isXPos = false;
			ball.yVel = randVelocity(180, true);
		}
		//X-collision with paddle
		if (ball.xPos <= paddle.xPos + 5 && paddle.xPos > 10 && (ball.yPos <= paddle.yPos+40 && ball.yPos >= paddle.yPos - 40)) {
			ball.isXPos = true;
			ball.yVel = randVelocity(80, true);
			std::cout << "Score: " << ++paddle.score << std::endl;
			ball.xVel += 25;
			
		}

		//Reset ball position
		if (ball.xPos < 0) {
			ball.xPos = 400;
			ball.yPos = 300;
			ball.xVel = 100;
			ball.isXPos = true;
			ball.yVel = randVelocity(180, true);
			paddle.score = 0;
		}

		//Y-movement
		ball.isYPos ? ball.yPos += getDeltaTime()*ball.yVel : ball.yPos -= getDeltaTime()*ball.yVel;

		if (ball.yPos >= 600) {
			ball.isYPos = false;
			ball.yVel = randVelocity(90, false);
		}
		if (ball.yPos <= 0) {
			ball.isYPos = true;
			ball.yVel = randVelocity(90, false);
		}

		//printf("XPos: %f, YPos: %f, XVel: %f, YVel: %f\n", ball.xPos, ball.yPos, ball.xVel, ball.yVel);
		drawCircle(ball.xPos, ball.yPos, 8, 15, CYAN);

	}
	termContext();
}

void main()
{
	customFunc1();
}