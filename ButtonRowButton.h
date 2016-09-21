#pragma once
#include "Button.h"
#include "ColorButton.h"
#include <vector>

class ButtonRowButton :
	public Button
{
	//I will be looping over all the color buttons later
	std::vector<ColorButton*> colorButtons;

public:
	ButtonRowButton();
	~ButtonRowButton();
	void init(int a_font, float a_x1, float a_y1, float width, float height, int a_size, int a_color, std::string a_text, int a_editColor);

	void draw();
	void tick_a();

	//Color variable edited by the button
	unsigned editColor;

	ColorButton redButton;
	ColorButton yellowButton;
	ColorButton greenButton;
	ColorButton cyanButton;
	ColorButton blueButton;
	ColorButton magButton;
	ColorButton whiteButton;
	ColorButton blackButton;
	

	bool isClickedChild;
	bool isActive;

	void onClicked();

};

