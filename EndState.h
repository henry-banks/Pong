#pragma once
#include "constdecl.h"

class EndState
{
	int font;
	int highScore;
public:
	EndState();
	~EndState();
	//Startup
	void init(int inFont);
	//Activation
	void play(int inScore);

	//Update
	void draw();
	void tick();

	EState next() const;
};

