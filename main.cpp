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
#include "MenuState.h"
#include "AboutState.h"
#include "OptionState.h"

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

	int nameRand = rand() % 20;

	//Choose a random window name.  Please collapse this if it's open
	switch (nameRand)
	{
	case 0:
		initContext(800, 600, "The Worst Thing Ever Made");
		break;
	case 1:
		initContext(800, 600, "Pong for Lonely People");
		break;
	case 2:
		initContext(800, 600, "GIT GUD");
		break;
	case 3:
		initContext(800, 600, "i snort smarties");
		break;
	case 4:
		initContext(800, 600, "WAAAAAAGH");
		break;
	case 5:
		initContext(800, 600, "Holla Holla Get Dolla");
		break;
	case 6:
		initContext(800, 600, "Never Gonna Give You Up");
		break;
	case 7:
		initContext(800, 600, "Never Gonna Let You Down");
		break;
	case 8:
		initContext(800, 600, "Half-Life 3");
		break;
	case 9:
		initContext(800, 600, "i main bastion");
		break;
	case 10:
		initContext(800, 600, "heyyeyaaeyaaaeyaeyaa");
		break;
	case 11:
		initContext(800, 600, "THERE CAN BE ONLY ONE");
		break;
	case 12:
		initContext(800, 600, "pootis");
		break;
	case 13:
		initContext(800, 600, "just............................DO IT");
		break;
	case 14:
		initContext(800, 600, "Don't Let Your Dreams Stay Dreams");
		break;
	case 15:
		initContext(800, 600, "Winter is Coming");
		break;
	case 16:
		initContext(800, 600, "BLOOD FOR THE BLOOD GOD");
		break;
	case 17:
		initContext(800, 600, "SKULLS FOR THE SKULL THRONE");
		break;
	case 18:
		initContext(800, 600, "i'M bATMAN");
		break;
	case 19:
		initContext(800, 600, "The Ride Never Ends");
		break;
	default:
		initContext(800, 600, "a winrar is u");
		break;
	}

	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned cursor = loadTextureMap("./res/ball.png");
	unsigned clickedCursor = loadTextureMap("./res/ball_clicked.png");
	setBackgroundColor(0x222222FF);

	GameState gs;
	SplashState splash;
	EndState end;
	PauseState pause;
	MenuState menu;
	AboutState about;
	OptionState option;
	EState state =	ENTER_SPLASH;

	splash.init(d);
	end.init(d, cursor, clickedCursor);
	pause.init(d);
	gs.initGameState(d, cursor, &option);
	menu.init(d, cursor, clickedCursor);
	about.init(d, cursor, clickedCursor);
	option.init(d, cursor, clickedCursor);

	bool isExit = false;

	while (stepContext() && !isExit)
	{
		setBackgroundColor(option.getBackgroundColor());

		switch (state)
		{
		case ENTER_SPLASH:
			splash.play(); //Move on immediately
		case SPLASH:
			splash.tick();
			splash.draw();
			state = splash.next();
			break;

		case ENTER_MENU:
			menu.play();
		case MENU:
			menu.tick();
			menu.draw();
			state = menu.next();
			break;

		case ABOUT:
			about.tick();
			about.draw();
			state = about.next();
			break;

		case OPTION:
			option.tick();
			option.draw();
			state = option.next();
			break;

		case ENTER_MAIN:
			gs.playGameState();
		case MAIN:
			gs.updateGameState();
			gs.drawGameState();
			//Update the score
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
			end.play(gs.getPaddle().getHighScore(), gs.getRound());
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