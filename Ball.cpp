#include "Ball.h"
#include <cstdlib>


void Ball::randVelocity(float& inVel, int maxRange, bool canNeg)
{

	if (!canNeg) {
		inVel = rand() % maxRange + 1;
	}
	else {
		//This effectively allows for a negative range.
		inVel = rand() % (maxRange * 2) + 1;
		inVel -= maxRange;
	}
}
