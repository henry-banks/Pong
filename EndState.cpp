#include "EndState.h"
#include "sfwdraw.h"
#include <string>


EndState::EndState()
{
}


EndState::~EndState()
{
}

void EndState::init(int inFont, int inCursor, int inClickedCursor)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;
	contButton.init(inFont, 75, 100, 200, 50, WHITE, "Continue", ENTER_MAIN);
	endButton.init(inFont, 525, 100, 200, 50, WHITE, "Quit", TERMINATE);
}

void EndState::play(int inScore, int roundNum)
{
	highScore = inScore;
	rounds = roundNum;
}

void EndState::draw()
{
	//High Score
	sfw::drawString(font, "High Score: ", 100, 500, 20, 20);
	sfw::drawString(font, std::to_string(highScore).c_str(), 325, 500, 20, 20);

	sfw::drawString(font, "Rounds: ", 100, 450, 20, 20);
	sfw::drawString(font, std::to_string(rounds).c_str(), 260, 450, 20, 20);

	//sfw::drawString(font, "Press Q to exit.", 100, 100, 20, 20);

	contButton.draw();
	endButton.draw();
	cursorDraw::drawCursor(cursor, clickedCursor);
}

void EndState::tick()
{
	contButton.tick();
	endButton.tick();
}

EState EndState::next()
{
	//if (sfw::getKey('Q')) {
	//	return TERMINATE;
	//}
	if (contButton.isClicked) {
		contButton.isClicked = false;
		return contButton.next();
	}
	else if (endButton.isClicked) {
		endButton.isClicked = false;
		return endButton.next();
	}

	return END;
}
