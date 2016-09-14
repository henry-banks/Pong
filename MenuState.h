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
	EState nextState;

	MenuState();
	~MenuState();

	//Startup
	void init(int inFont);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next() const;
};

