#include "OptionState.h"
#include "sfwdraw.h"
#include <string>

using namespace sfw;

OptionState::OptionState()
{
}


OptionState::~OptionState()
{
}

void OptionState::init(int inFont, int inCursor, int inClickedCursor)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;


	//Set default colors
	trailColor_s = trailColor = 0x00ffffff;
	paddleColor_s = paddleColor = 0x0000ffff;
	particleColor_s =  particleColor = 0xffff00ff;
	backgroundColor_s = backgroundColor = 0x222222FF;


	confirmButton.init(font, 75, 100, 200, 50, WHITE, "Confirm", ENTER_MENU);
	cancelButton.init(font, 525, 100, 200, 50, WHITE, "Cancel", ENTER_MENU);
	DefaultButton.init(font, 300, 100, 200, 50, WHITE, "Default");

	trailButton.init(font, 75, 550, 200, 30, 12, WHITE, "Trail Color", trailColor);
	paddleButton.init(font, 75, 450, 200, 30, 12, WHITE, "Paddle Color", paddleColor);
	particleButton.init(font, 75, 350, 200, 30, 12, WHITE, "Particle Color", particleColor);
	backgroundButton.init(font, 75, 250, 200, 30, 12, WHITE, "Background Color", backgroundColor);

	buttons.push_back(&trailButton);
	buttons.push_back(&paddleButton);
	buttons.push_back(&particleButton);
	buttons.push_back(&backgroundButton);
}

void OptionState::play()
{

}

void OptionState::draw()
{
	confirmButton.draw();
	cancelButton.draw();
	DefaultButton.draw();
	
	//Draw toggle buttons
	for (ButtonRowButton* i : buttons) {
		i->draw();
	}

	//Draw text
	drawString(font, "Current Color ", 300, 540, 16, 16, 0, '\0', trailColor);
	drawString(font, "Current Color ", 300, 440, 16, 16, 0, '\0', paddleColor);
	drawString(font, "Current Color ", 300, 340, 16, 16, 0, '\0', particleColor);
	drawString(font, "Current Color ", 300, 240, 16, 16, 0, '\0', backgroundColor);

	cursorDraw::drawCursor(cursor, clickedCursor);
}

void OptionState::tick()
{
	confirmButton.tick();
	cancelButton.tick();
	DefaultButton.tick();

	for (ButtonRowButton* i : buttons) {
		i->tick_a();
	}

	//Reset colors to default
	if (DefaultButton.isClicked)
	{
		trailColor_s = trailColor = 0x00ffffff;
		paddleColor_s = paddleColor = 0x0000ffff;
		particleColor_s = particleColor = 0xffff00ff;
		backgroundColor_s = backgroundColor = 0x222222FF;

		DefaultButton.isClicked = false;
	}

	//Check to see if a 'row button' has been pressed
	if (trailButton.isClicked) {
		trailButton.isClicked = false;
		paddleButton.isActive = false;
		particleButton.isActive = false;
		backgroundButton.isActive = false;
	}
	if (paddleButton.isClicked) {
		paddleButton.isClicked = false;
		trailButton.isActive = false;
		particleButton.isActive = false;
		backgroundButton.isActive = false;
	}
	if (particleButton.isClicked) {
		particleButton.isClicked = false;
		trailButton.isActive = false;
		paddleButton.isActive = false;
		backgroundButton.isActive = false;
	}
	if (backgroundButton.isClicked) {
		backgroundButton.isClicked = false;
		trailButton.isActive = false;
		paddleButton.isActive = false;
		particleButton.isActive = false;
	}

	//Check to see if any colors have changed
	if (trailButton.isClickedChild) {
		trailButton.isClickedChild = false;
		trailColor = trailButton.editColor;
	}
	if (paddleButton.isClickedChild) {
		paddleButton.isClickedChild = false;
		paddleColor = paddleButton.editColor;
	}
	if (particleButton.isClickedChild) {
		particleButton.isClickedChild = false;
		particleColor = particleButton.editColor;
	}
	if (backgroundButton.isClickedChild) {
		backgroundButton.isClickedChild = false;
		backgroundColor = backgroundButton.editColor;
	}
}

EState OptionState::next()
{
	if (confirmButton.isClicked) {
		//Confirm colors
		trailColor_s = trailColor;
		paddleColor_s = paddleColor;
		particleColor_s = particleColor;
		backgroundColor_s = backgroundColor;
		confirmButton.isClicked = false;
		return confirmButton.next();
	}
	if (cancelButton.isClicked) {
		//reset colors
		trailColor = trailColor_s;
		paddleColor = paddleColor_s;
		particleColor = particleColor_s;
		backgroundColor = backgroundColor_s;

		cancelButton.isClicked = false;
		return cancelButton.next();
	}

	return OPTION;
}

unsigned OptionState::getTrailColor()
{
	return trailColor_s;
}

unsigned OptionState::getPaddleColor()
{
	return paddleColor_s;
}

unsigned OptionState::getParticleColor()
{
	return particleColor_s;
}

unsigned OptionState::getBackgroundColor()
{
	return backgroundColor_s;
}
