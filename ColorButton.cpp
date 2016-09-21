#include "ColorButton.h"



ColorButton::ColorButton()
{
}


ColorButton::~ColorButton()
{
}


void ColorButton::onClicked()
{
	isClicked = true;
}

unsigned ColorButton::getColor()
{
	return color;
}
