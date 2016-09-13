#include "EndState.h"
#include "sfwdraw.h"
#include <string>


EndState::EndState()
{
}


EndState::~EndState()
{
}

void EndState::init(int inFont)
{
	font = inFont;
}

void EndState::play(int inScore)
{
	highScore = inScore;
}

void EndState::draw()
{
	//High Score
	sfw::drawString(font, "High Score: ", 100, 200, 20, 20);
	sfw::drawString(font, std::to_string(highScore).c_str(), 325, 200, 20, 20);

	sfw::drawString(font, "Press Q to exit.", 100, 100, 20, 20);
}

void EndState::tick()
{
}

EState EndState::next() const
{
	if (sfw::getKey('Q')) {
		return TERMINATE;
	}

	return END;
}
