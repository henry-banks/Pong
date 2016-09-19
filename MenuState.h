#pragma once
#include "constdecl.h"
#include "MenuButton.h"

class MenuState
{
	MenuButton playButton;
	MenuButton aboutButton;
	MenuButton quitButton;

public:
	int font;
	int cursor, clickedCursor;
	EState nextState;

	MenuState();
	~MenuState();

	//Startup
	void init(int inFont, int inCursor, int inClickedCursor);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next();
};

