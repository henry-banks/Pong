#pragma once
class Brick
{
public:
	Brick();
	~Brick();
	
	//x-coordinates
	float x1, x2;
	//y-coordinates
	float y1, y2;

	//Hexidecimal color
	unsigned int color;

	//bool isActive //Turn on if deleting does not work.

	void initBrick(float inX1, float inX2, float inY1, float inY2, int inColor);

};

