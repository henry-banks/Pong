#include "MenuState.h"
#include "sfwdraw.h"
using namespace sfw;


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::init(int inFont)
{
	font = inFont;
	nextState = EState::MENU;

	playButton.init(font, 300, 600, 200, 50, WHITE, "Play", MAIN);
	aboutButton.init(font, 300, 675, 200, 50, WHITE, "About", MENU);
	quitButton.init(font, 300, 750, 200, 50, WHITE, "Quit", TERMINATE);
}

void MenuState::play()
{
}

void MenuState::draw()
{
	drawString(font, "PONG FOR LONELY PEOPLE", 300, 700, 18, 18, 0, '\0');

	playButton.draw();
	aboutButton.draw();
	quitButton.draw();
}

void MenuState::tick()
{
	playButton.tick();
	aboutButton.tick();
	quitButton.tick();
}

EState MenuState::next() const
{
	if (playButton.isClicked) {
		return playButton.next();
	}
	else if (aboutButton.isClicked) {
		return aboutButton.next();
	}
	else if (quitButton.isClicked) {
		return quitButton.next();
	}

	return MENU;
}
