#pragma once
#include <string>
#include "constdecl.h"

//Anywhere there is a button there will also be a cursor.
//So, it seems safe to put the cursor function in the button header.
namespace cursorDraw
{
	//Draws the ball as a cursor
	void drawCursor(int normalTex, int clickedTex);
}

class Button
{
protected:
	int font;
	int size;
	float x1, x2, y1, y2;
	int color;
	std::string text;
public:
	Button();
	~Button();
	void init(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text);
	//Optional initializer, using font size
	void init(int a_font, float a_x1, float a_y1, float width, float height, int a_size, int a_color, std::string a_text);

	bool isClicked;
	void draw();
	void tick();

	//The function to call when the button is clicked
	virtual void onClicked() = 0;

	//Getters, no setters
	unsigned getFont();

	float getX1();
	float getX2();
	float getY1();
	float getY2();

	int getColor();
	std::string getText();
};

