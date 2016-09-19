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

	nextState = a_nextState;
}

void MenuButton::draw()
{
	//draw rectangle
	drawLine(x1, y1, x2, y1);
	drawLine(x1, y2, x2, y2);
	drawLine(x1, y1, x1, y2);
	drawLine(x2, y1, x2, y2);

	drawString(font, text.c_str(), ((x1 + x2)/2) - (text.size() * 10) , y1-15, 20, 20, 0, '\0');
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
	return nextState;
}

void cursorDraw::drawCursor(int normalTex, int clickedTex)
{
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)) {
		drawTexture(clickedTex, getMouseX(), getMouseY(), 20, 20);
	/*	drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00fffff0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFFc0);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF25);*/
	}
	else {
		drawTexture(normalTex, getMouseX(), getMouseY(), 20, 20);
	/*	drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff20);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF20);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF05);*/
	}
}
