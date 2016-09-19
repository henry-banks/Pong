#pragma once
#include "constdecl.h"
#include "MenuButton.h"


class AboutState
{
	int font;
	int cursor, clickedCursor;
	MenuButton backButton;
public:
	AboutState();
	~AboutState();
	//Startup
	void init(int inFont, int inCursor, int inClickedCursor);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next();
};

