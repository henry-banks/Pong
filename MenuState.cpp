#include "MenuState.h"
#include "sfwdraw.h"
using namespace sfw;


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::init(int inFont, int inCursor)
{
	font = inFont;
	cursor = inCursor;
	nextState = EState::MENU;

	playButton.init(font, 300, 400, 200, 50, WHITE, "Play", MAIN);
	aboutButton.init(font, 300, 325, 200, 50, WHITE, "About", ABOUT);
	quitButton.init(font, 300, 250, 200, 50, WHITE, "Quit", TERMINATE);
}

void MenuState::play()
{
	//Reset
	nextState = EState::MENU;
}

void MenuState::draw()
{
	drawString(font, "PONG FOR LONELY PEOPLE", 75, 550, 30, 30, 0, '\0');

	playButton.draw();
	aboutButton.draw();
	quitButton.draw();

	//"cursor"
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)) {
		drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00fffff0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFFc0);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF25);
	}
	else {
		drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff20);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF20);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF05);
	}
}

void MenuState::tick()
{
	playButton.tick();
	aboutButton.tick();
	quitButton.tick();
}

EState MenuState::next()
{
	if (playButton.isClicked) {
		playButton.isClicked = false;
		return playButton.next();
	}
	else if (aboutButton.isClicked) {
		aboutButton.isClicked = false;
		return aboutButton.next();
	}
	else if (quitButton.isClicked) {
		quitButton.isClicked = false;
		return quitButton.next();
	}

	return MENU;
}
