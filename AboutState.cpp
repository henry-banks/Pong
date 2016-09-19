#include "AboutState.h"
#include "sfwdraw.h"

using namespace sfw;

AboutState::AboutState()
{
}

AboutState::~AboutState()
{
}

void AboutState::init(int inFont, int inCursor, int inClickedCursor)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;
	backButton.init(font, 75, 100, 200, 50, WHITE, "Back", ENTER_MENU);
}

void AboutState::play()
{
	//nothing here
}

void AboutState::draw()
{
	drawString(font, "PONG FOR LONELY PEOPLE", 75, 550, 30, 30, 0, '\0');

	drawString(font, "Controls: Move the mouse up and down to control", 75, 450, 15, 15, 0, '\0');
	drawString(font, "the paddle.  If the ball hits the paddle, it ", 75, 430, 15, 15, 0, '\0');
	drawString(font, "bounces back.  Move the paddle so that the ball", 75, 410, 15, 15, 0, '\0');
	drawString(font, "hits it.", 75, 390, 15, 15, 0, '\0');

	drawString(font, "Programming: Henry Banks", 75, 300, 20, 20, 0, '\0');
	drawString(font, "Art: Henry Banks", 75, 275, 20, 20, 0, '\0');
	drawString(font, "Design: Henry Banks", 75, 250, 20, 20, 0, '\0');
	drawString(font, "All Other Jobs: Henry Banks", 75, 225, 20, 20, 0, '\0');

	backButton.draw();

	cursorDraw::drawCursor(cursor, clickedCursor);
}

void AboutState::tick()
{
	backButton.tick();
}

EState AboutState::next()
{
	if (backButton.isClicked) {
		backButton.isClicked = false;
		return backButton.next();
	}
	return ABOUT;
}
