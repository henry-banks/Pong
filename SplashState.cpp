#include "SplashState.h"
#include "sfwdraw.h"


SplashState::SplashState()
{
}


SplashState::~SplashState()
{
}

void SplashState::init(int inFont)
{
	font = inFont;
}

void SplashState::play()
{
	timer = 2.f;
}

void SplashState::draw()
{
	sfw::drawString(font, "Wait a Bit...", 100, 100, 20, 20);
	sfw::drawLine(100, 70, 100 + 500 * timer / 3.f, 70);
}

void SplashState::tick()
{
	timer -= sfw::getDeltaTime();
}

EState SplashState::next() const
{
	if (timer < 0) {
		return ENTER_MENU;
	}

	return SPLASH;
}

