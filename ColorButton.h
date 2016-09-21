#pragma once
#include "Button.h"

class ColorButton : public Button
{

public:
	ColorButton();
	~ColorButton();

	void onClicked();
	unsigned getColor();
};

