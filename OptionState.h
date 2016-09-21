#pragma once
#include "constdecl.h"
#include "MenuButton.h"
#include "ColorButton.h"
#include "ButtonRowButton.h"
#include "GameData.h"

#include <vector>

class OptionState
{
	int font;
	int cursor, clickedCursor;

	GameData* data;

	MenuButton confirmButton;
	MenuButton cancelButton;

	//I may want to put these in an array
	ButtonRowButton trailButton;
	ButtonRowButton paddleButton;
	ButtonRowButton particleButton;
	ButtonRowButton backgroundButton;

	//Variables to hold all these colors
	unsigned trailColor, paddleColor, particleColor, backgroundColor;
	//Used for resetting color buttons
	unsigned placeholderInt;

public:
	OptionState();
	~OptionState();
	//Startup
	void init(int inFont, int inCursor, int inClickedCursor, GameData* inData);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	GameData* getData();

	EState next();
};


