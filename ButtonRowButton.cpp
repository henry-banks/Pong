#include "ButtonRowButton.h"
#include "sfwdraw.h"
using namespace sfw;

ButtonRowButton::ButtonRowButton()
{
}


ButtonRowButton::~ButtonRowButton()
{
}

void ButtonRowButton::init(int a_font, float a_x1, float a_y1, float width, float height, int a_size, int a_color, std::string a_text, int a_editColor)
{
	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;
	text = a_text;

	size = a_size;
	editColor = a_editColor;

	isActive = false;

	/*These guys should spawn off-screen*/
	redButton.init(font, 0, -1, 50, 50, RED, "R");
	yellowButton.init(font, 0, -1, 50, 50, YELLOW, "Y");
	greenButton.init(font, 0, -1, 50, 50, GREEN, "G");
	cyanButton.init(font, 0, -1, 50, 50, CYAN, "C");
	blueButton.init(font, 0, -1, 50, 50, BLUE, "B");
	magButton.init(font, 0, -1, 50, 50, MAGENTA, "M");
	whiteButton.init(font, 0, -1, 50, 50, WHITE, "W");
	blackButton.init(font, 0, -1, 50, 50, BLACK, "K");

	colorButtons.push_back(&redButton);
	colorButtons.push_back(&yellowButton);
	colorButtons.push_back(&greenButton);
	colorButtons.push_back(&cyanButton);
	colorButtons.push_back(&blueButton);
	colorButtons.push_back(&magButton);
	colorButtons.push_back(&whiteButton);
	colorButtons.push_back(&blackButton);

}

void ButtonRowButton::draw()
{
	//draw rectangle
	drawLine(x1, y1, x2, y1, color);
	drawLine(x1, y2, x2, y2, color);
	drawLine(x1, y1, x1, y2, color);
	drawLine(x2, y1, x2, y2, color);

	//All the math makes the text show up in the middle of the button
	drawString(font, text.c_str(), ((x1 + x2) / 2) - (text.size() * (size / 2)), ((y1 + y2) / 2) + size / 2, size, size, 0, '\0', color);

	if (isActive) {
		for (int i = 0; i < colorButtons.size(); i++)
		{
			colorButtons[i]->draw();
		}
	}
}

void ButtonRowButton::tick_a()
{
	if (getMouseX() > x1 && getMouseX() < x2 && getMouseY() < y1 && getMouseY() > y2 && getMouseButton(0))
	{
		onClicked();
	}

	for (ColorButton* i : colorButtons) {
		i->tick();
		if (i->isClicked) {
			isClickedChild = true;
			editColor = i->getColor();
			i->isClicked = false;
		}
	}
}

void ButtonRowButton::onClicked()
{
	isActive = true;
	isClicked = true;
	for (int i = 0; i < colorButtons.size(); i++)
	{
		colorButtons[i]->init(font, x1 + (30 * i), y2 - 10, 25, 25, colorButtons[i]->getColor(), colorButtons[i]->getText());
	}
}
