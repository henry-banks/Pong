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
	timer = 1.f;
}

void SplashState::draw()
{
	sfw::drawString(font, "Hold on I'm loading...", 100, 100, 20, 20);
	sfw::drawLine(100, 70, 100 + 500 * timer, 70);
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

