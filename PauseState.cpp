#include "PauseState.h"
#include "sfwdraw.h"	


PauseState::PauseState()
{
}


PauseState::~PauseState()
{
}

void PauseState::init(int inFont)
{
	font = inFont;
}

void PauseState::play()
{
	timer = 3.f;
}

void PauseState::draw()
{
	sfw::drawString(font, "Press 'C' to continue.", 100, 100, 20, 20);
	sfw::drawLine(100, 70, 100 + 500 * timer / 3.f, 70);
}

void PauseState::tick()
{
	timer -= sfw::getDeltaTime() / 2;
}

EState PauseState::next() const
{
	if (timer < 0) {
		return ENTER_END;
	}
	if (sfw::getKey('C')) {
		return MAIN;
	}

	return PAUSE;
}
