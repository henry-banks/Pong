#include <iostream>	//just because ;D
#include <ctime>	//for the randoms
#include <string>
#include <vector>

#include "sfwdraw.h"
#include "GameState.h"
#include "SplashState.h"
#include "EndState.h"
#include "PauseState.h"
#include "constdecl.h"

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


void main()
{
	//Seed the randoms
		srand(time(0));

	initContext(800, 600, "The Worst Thing Ever Made");
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	setBackgroundColor(0x222222FF);

	GameState gs;
	SplashState splash;
	EndState end;
	PauseState pause;
	EState state =	ENTER_SPLASH;

	splash.init(d);
	end.init(d);
	pause.init(d);
	gs.initGameState();

	bool isExit = false;

	while (stepContext() && !isExit)
	{

		switch (state)
		{
		case ENTER_SPLASH:
			splash.play(); //Move on immediately
		case SPLASH:
			splash.tick();
			splash.draw();
			state = splash.next();
			break;

		case MAIN:
			gs.updateGameState();
			gs.drawGameState();
			//Update the score
			drawString(d, std::to_string(gs.getPaddle().score).c_str(), 50, 600, 16, 16, 0, '\0', WHITE);
			state = gs.next();
			break;

		case ENTER_PAUSE:
			pause.play();
		case PAUSE:
			pause.tick();
			pause.draw();
			state = pause.next();
			break;

		case ENTER_END:
			end.play(gs.getPaddle().getHighScore());
		case END:
			end.tick();
			end.draw();
			state = end.next();
			break;
		case TERMINATE:
			isExit = true;
			break;
		}

		
	}
	termContext();
}