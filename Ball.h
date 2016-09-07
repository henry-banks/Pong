#pragma once
struct Ball
{
	float xPos = 400, yPos = 300;
	float xVel = 100, yVel = 100;

	bool isXPos = true, isYPos = true;

	/*Creates a random velocity within the range (in degrees) given.
	inVel: Velocity to change (use ballName.xVel/yVel)
	maxRange: The maximum range (in degrees) that the new velocity can be.
	canNeg: Whether or not the velocity can be negative (set to false if bouncing off floor/ceiling).
	*/
	void randVelocity(float& inVel, int maxRange, bool canNeg);
};