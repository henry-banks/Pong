#include "Brick.h"



Brick::Brick()
{
	x1 = 0;
	x2 = 0;

	y1 = 0;
	y2 = 0;

	color = 0xffffffff;
}


Brick::~Brick()
{
}

void Brick::initBrick(float inX1, float inX2, float inY1, float inY2, int inColor)
{
	x1 = inX1;
	x2 = inX2;

	y1 = inY1;
	y2 = inY2;

	color = inColor;

}
