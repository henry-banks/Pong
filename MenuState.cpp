#include "MenuState.h"
#include "sfwdraw.h"
using namespace sfw;


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::init(int inFont, int inCursor, int inClickedCursor)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;
	nextState = EState::MENU;

	playButton.init(font, 300, 400, 200, 50, WHITE, "Play", ENTER_MAIN);
	optionButton.init(font, 300, 325, 200, 50, WHITE, "Options", OPTION);
	aboutButton.init(font, 300, 250, 200, 50, WHITE, "About", ABOUT);
	quitButton.init(font, 300, 175, 200, 50, WHITE, "Quit", TERMINATE);
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
	optionButton.draw();
	aboutButton.draw();
	quitButton.draw();

	cursorDraw::drawCursor(cursor, clickedCursor);
}

void MenuState::tick()
{
	playButton.tick();
	optionButton.tick();
	aboutButton.tick();
	quitButton.tick();
}

EState MenuState::next()
{
	if (playButton.isClicked) {
		playButton.isClicked = false;
		return playButton.next();
	}
	else if (optionButton.isClicked) {
		optionButton.isClicked = false;
		return optionButton.next();
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
