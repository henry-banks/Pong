#pragma once
#include "constdecl.h"
#include "MenuButton.h"
#include "ColorButton.h"
#include "ButtonRowButton.h"

#include <vector>

class OptionState
{
	int font;
	int cursor, clickedCursor;


	MenuButton confirmButton;
	MenuButton cancelButton;
	//Color buttons are the most vanilla buttons so I'm using one of those for the 'reset to deafult' button
	ColorButton DefaultButton;

	//I may want to put these in an array
	ButtonRowButton trailButton;
	ButtonRowButton paddleButton;
	ButtonRowButton particleButton;
	ButtonRowButton backgroundButton;

	std::vector<ButtonRowButton*> buttons;

	//Variables to hold all these colors
	unsigned trailColor, paddleColor, particleColor, backgroundColor;
	//Variables to save all these colors (in case of cancel)
	unsigned trailColor_s, paddleColor_s, particleColor_s, backgroundColor_s;

	//Used for resetting color buttons
	unsigned placeholderInt;

public:
	OptionState();
	~OptionState();
	//Startup
	void init(int inFont, int inCursor, int inClickedCursor);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next();

	//Getters
	unsigned getTrailColor();
	unsigned getPaddleColor();
	unsigned getParticleColor();
	unsigned getBackgroundColor();
};


