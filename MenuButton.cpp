#include "MenuButton.h"
#include "sfwdraw.h"
using namespace sfw;

MenuButton::MenuButton()
{
	isClicked = false;
}


MenuButton::~MenuButton()
{
}

void MenuButton::init(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_name, EState a_nextState)
{
	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;
	text = a_name;

	nextState = a_nextState;
}

void MenuButton::draw()
{
	//draw rectangle
	drawLine(x1, y1, x2, y1);
	drawLine(x1, y2, x2, y2);
	drawLine(x1, y1, x1, y2);
	drawLine(x2, y1, x2, y2);

	drawString(font, text.c_str(), x1 + 2, y2/2, 12);
}

void MenuButton::tick()
{
	if (getMouseX() > x1 && getMouseX() < x2 && getMouseY() < y1 && getMouseY() > y2 && getMouseButton(0))
	{
		isClicked = true;
	}
}

EState MenuButton::next() const
{
	if (isClicked) {
		return nextState;
	}
	return EState::MENU;
}
