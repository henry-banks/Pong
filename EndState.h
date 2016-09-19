#pragma once
#include "constdecl.h"
#include "MenuButton.h"

class EndState
{
	int font;
	int cursor, clickedCursor;
	int highScore, rounds;

	MenuButton contButton, endButton;
public:
	EndState();
	~EndState();
	//Startup
	void init(int inFont, int inCursor, int inClickedCursor);
	//Activation
	void play(int inScore, int roundNum);

	//Update
	void draw();
	void tick();

	EState next();
};

