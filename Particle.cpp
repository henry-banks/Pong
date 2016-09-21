#include "Particle.h"
#include "sfwdraw.h"
#include "Ball.h"
#include <cstdlib>
#include <ctime>

Particle::Particle()
{
	xPos = 0;
	yPos = 0;

	xVel = 100;
	yVel = 100;

	startTime = sfw::getTime();
	lifetime = 0;

	isXPos = true;
	isYPos = false;

	isActive = false;
}


Particle::~Particle()
{
}

void Particle::resetParticle(float inX, float inY, int inLife)
{
	//Just in case
	//srand(time(0));

	xPos = inX;
	yPos = inY;

	xVel = randVelocity(90, true);
	yVel = randVelocity(90, true);

	lifetime = rand() % inLife + 1; //Life will be anywhere between 1 and 1 + inLife
	startTime = sfw::getTime();

	isActive = true;
}


void Particle::updateParticle()
{
	if (sfw::getTime() - startTime > lifetime) {
		isActive = false;
	}

	//X-Movement
	isXPos ? xPos += sfw::getDeltaTime()*xVel : xPos -= sfw::getDeltaTime()*xVel;

	//Y-Movement
	isYPos ? yPos += sfw::getDeltaTime()*yVel : yPos -= sfw::getDeltaTime()*yVel;

	//Y-collision with floor
	if (yPos <= 0) {
		isYPos = true;
		yPos = randVelocity(100, false);
	}
	
}

void Particle::drawParticle(unsigned int color)
{
	if (isActive){
		sfw::drawCircle(xPos, yPos, 1, 1, color);
	}
	
}

float Particle::randVelocity(int maxRange, bool canNeg)
{
	float inVel;

	if (!canNeg) {
		inVel = rand() % maxRange + 1;
	}
	else {
		//This effectively allows for a negative range.
		inVel = rand() % (maxRange * 2) + 1;
		inVel -= maxRange;
	}

	return inVel;
}

bool Particle::getActive()
{
	return isActive;
}
