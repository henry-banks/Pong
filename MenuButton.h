#pragma once
#include <string>
#include "constdecl.h"

class MenuButton
{
	int font;
	float x1, x2, y1, y2;
	int color;
	std::string text;
	

	EState nextState;
public:
	MenuButton();
	~MenuButton();
	void init(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_name, EState a_nextState);

	bool isClicked;
	void draw();
	void tick();
	EState next() const;
};

