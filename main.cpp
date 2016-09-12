#include <iostream>	//just because ;D
#include <ctime>	//for the randoms
#include <string>
#include <vector>

#include "sfwdraw.h"
#include "GameState.h"

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

//Simple thingey, REALLY messy.  Delete soon.
void customFunc1()
{
	//THE FOLLOWING IS A HORRIBLE MESS.  BEWARE.

	//Seed the randoms
	srand(time(0));

	initContext(800, 600, "The Worst Thing Ever Made");

	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);

	setBackgroundColor(0x222222FF);

	Ball ball;

	GameState gs = initGameState();
	Paddle paddle = gs.player;

	while (stepContext())
	{
		//drawString(d, "HELLO.", 0, 600, 24, 24, 0, '\0', 0x33FFFFFF);

		paddle.yPos = getMouseY();
		paddle.yPosUp = paddle.yPos + 40;
		paddle.yPosDown = paddle.yPos - 40;

		//paddle.drawPaddle();  //THE FUNCTION DOESN'T WANT TO WORK.
		drawLine(paddle.xPos, paddle.yPos + 30, paddle.xPos, paddle.yPos - 30, BLUE);  
		drawLine(paddle.xPos - 1, paddle.yPos + 30, paddle.xPos - 1, paddle.yPos - 30, BLUE);
		drawLine(paddle.xPos - 2, paddle.yPos + 30, paddle.xPos - 2, paddle.yPos - 30, BLUE);

		//THIS WON'T WORK EITHER.
		/*for (int i = paddle.width; i < 0; i++)
		{
			drawLine(paddle.xPos, paddle.yPos + paddle.height, paddle.xPos, paddle.yPos - paddle.height, BLUE);
		}*/
		
		drawString(d, std::to_string(paddle.score).c_str(), 50, 600, 16, 16, 0, '\0', WHITE);

		//for (int i = 0; i < bricks.size(); i++)
		//{
		//	//Shortcut variable
		//	Brick r = bricks[i];
		//	for (int j = r.x1; j < r.x2; j++)
		//	{
		//		drawLine(j, r.y1 + (j-r.x1), )
		//	}
		//}

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
			ball.randVelocity(ball.yVel, 180, true);
		}
		//X-collision with paddle
		if (ball.xPos <= paddle.xPos + 5 && paddle.xPos > 10 && (ball.yPos <= paddle.yPos+40 && ball.yPos >= paddle.yPos - 40)) {
			ball.isXPos = true;
			ball.randVelocity(ball.yVel, 80, true);
			std::cout << "Score: " << ++paddle.score << std::endl;
			ball.xVel += 25;
			
		}

		//Reset ball position
		if (ball.xPos < 0) {
			ball.xPos = 400;
			ball.yPos = 300;
			ball.xVel = 100;
			ball.isXPos = true;
			ball.randVelocity(ball.yVel, 180, true);
			paddle.score = 0;
		}

		//Y-movement
		ball.isYPos ? ball.yPos += getDeltaTime()*ball.yVel : ball.yPos -= getDeltaTime()*ball.yVel;

		if (ball.yPos >= 600) {
			ball.isYPos = false;
			ball.randVelocity(ball.yVel, 90, false);
		}
		if (ball.yPos <= 0) {
			ball.isYPos = true;
			ball.randVelocity(ball.yVel, 90, false);
		}

		//printf("XPos: %f, YPos: %f, XVel: %f, YVel: %f\n", ball.xPos, ball.yPos, ball.xVel, ball.yVel);
		
		//hollow circle
		//drawCircle(ball.xPos, ball.yPos, 8, 15, CYAN);
		
		//filled circle
		/*for (int i = 8; i > 0; i--)
		{
			drawCircle(ball.xPos, ball.yPos, 8, 15, CYAN);
		}*/

		//GLOWY circle
		drawCircle(ball.xPos, ball.yPos, 9, 15, 0x00ffff20);
		drawCircle(ball.xPos, ball.yPos, 8, 15, 0x00ffff50);
		drawCircle(ball.xPos, ball.yPos, 7, 15, 0x00ffff80);
		drawCircle(ball.xPos, ball.yPos, 6, 15, 0x00ffffc0);
		drawCircle(ball.xPos, ball.yPos, 5, 15, 0xFFFFFF80);
		drawCircle(ball.xPos, ball.yPos, 4, 15, 0xFFFFFF60);
		drawCircle(ball.xPos, ball.yPos, 3, 15, 0xFFFFFF40);
		drawCircle(ball.xPos, ball.yPos, 2, 15, 0xFFFFFF20);
		drawCircle(ball.xPos, ball.yPos, 1, 15, 0xFFFFFF05);

		//BIG glowy circle
		/*drawCircle(ball.xPos, ball.yPos, 11, 15, 0x00ffff20);
		drawCircle(ball.xPos, ball.yPos, 10, 15, 0x00ffff50);
		drawCircle(ball.xPos, ball.yPos, 9, 15, 0x00ffff80);
		drawCircle(ball.xPos, ball.yPos, 8, 15, 0x00ffffc0);
		drawCircle(ball.xPos, ball.yPos, 7, 15, 0xFFFFFF80);
		drawCircle(ball.xPos, ball.yPos, 6, 15, 0xFFFFFF60);
		drawCircle(ball.xPos, ball.yPos, 5, 15, 0xFFFFFF40);
		drawCircle(ball.xPos, ball.yPos, 4, 15, 0xFFFFFF20);
		drawCircle(ball.xPos, ball.yPos, 3, 15, 0xFFFFFF05);*/

	}
	termContext();
}

void main()
{
	//Seed the randoms
		srand(time(0));

	initContext(800, 600, "The Worst Thing Ever Made");
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	setBackgroundColor(0x222222FF);

	GameState gs = initGameState();

	while (stepContext())
	{
		updateGameState(gs);
		drawGameState(gs);

		//Update the score
		drawString(d, std::to_string(gs.player.score).c_str(), 50, 600, 16, 16, 0, '\0', WHITE);
	}
	termContext();
}