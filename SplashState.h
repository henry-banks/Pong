#pragma once
#include "constdecl.h"

class SplashState
{
	int font;
	float timer;
public:
	SplashState();
	~SplashState();
	//Startup
	void init(int inFont);
	//Activation
	void play();

	//Update
	void draw();
	void tick();

	EState next() const;
};

