#pragma once
#include <string>
#include "constdecl.h"

namespace cursorDraw
{
	//Draws the ball as a cursor
	void drawCursor(int normalTex, int clickedTex);
}


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
	void init(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text, EState a_nextState);

	bool isClicked;
	void draw();
	void tick();
	EState next() const;
};

