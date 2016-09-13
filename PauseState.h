#pragma once
#include "constdecl.h"

class PauseState
{
	int font;
	float timer;
public:
	PauseState();
	~PauseState();
	//Startup
	void init(int inFont);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next() const;
};

