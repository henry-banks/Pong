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

void MenuButton::init(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text, EState a_nextState)
{
	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;
	text = a_text;

	size = 20;
	nextState = a_nextState;
}

void MenuButton::onClicked()
{
	isClicked = true;
}

EState MenuButton::next() const
{
	return nextState;
}
