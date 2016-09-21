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

void OptionState::init(int inFont, int inCursor, int inClickedCursor, GameData* inData)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;

	data = inData;

	//Set default colors
	trailColor = 0x00ffffff;
	paddleColor = 0x0000ffff;
	particleColor = 0xffff00ff;
	backgroundColor = 0x222222FF;


	confirmButton.init(font, 75, 100, 200, 50, WHITE, "Confirm", ENTER_MENU);
	cancelButton.init(font, 525, 100, 200, 50, WHITE, "Cancel", ENTER_MENU);

	trailButton.init(font, 75, 550, 200, 30, 12, WHITE, "Trail Color");
	paddleButton.init(font, 75, 450, 200, 30, 12, WHITE, "Paddle Color");
	particleButton.init(font, 75, 350, 200, 30, 12, WHITE, "Particle Color");
	backgroundButton.init(font, 75, 250, 200, 30, 12, WHITE, "Background Color");

}

void OptionState::play()
{

}

void OptionState::draw()
{
	confirmButton.draw();
	cancelButton.draw();
	
	//Draw toggle buttons
	trailButton.draw();
	paddleButton.draw();
	particleButton.draw();
	backgroundButton.draw();

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

	trailButton.tick_a();
	paddleButton.tick_a();
	particleButton.tick_a();
	backgroundButton.tick_a();

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
		data->trailColor = trailButton.editColor;
	}
	if (paddleButton.isClickedChild) {
		paddleButton.isClickedChild = false;
		data->paddleColor = paddleButton.editColor;
	}
	if (particleButton.isClickedChild) {
		particleButton.isClickedChild = false;
		data->particleColor = particleButton.editColor;
	}
	if (backgroundButton.isClickedChild) {
		backgroundButton.isClickedChild = false;
		data->backgroundColor = backgroundButton.editColor;
	}
}

GameData * OptionState::getData()
{
	return data;
}

EState OptionState::next()
{
	if (confirmButton.isClicked) {
		confirmButton.isClicked = false;
		return confirmButton.next();
	}
	if (cancelButton.isClicked) {
		//reset colors
		trailColor = 0x00ffffff;
		paddleColor = 0x0000ffff;
		particleColor = 0xffff00ff;
		backgroundColor = 0x222222FF;

		cancelButton.isClicked = false;
		return cancelButton.next();
	}

	return OPTION;
}
