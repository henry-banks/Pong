#pragma once
#include "constdecl.h"
#include "MenuButton.h"


class AboutState
{
	int font;
	MenuButton backButton;
public:
	AboutState();
	~AboutState();
	//Startup
	void init(int inFont);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next();
};

