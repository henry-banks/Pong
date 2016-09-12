#include "Brick.h"
#include "sfwdraw.h"
#include <vector>



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

std::vector<Brick> makeBricks()
{
	std::vector<Brick> brickList;
	//used as y-base
	int yAcc = 795;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j < 590; j += 25)
		{
			Brick newBrick;
			newBrick.initBrick(j, j + 10, yAcc, yAcc - 20, RED);

			brickList.push_back(newBrick);
		}
		yAcc += 15;
	}

	return brickList;
}