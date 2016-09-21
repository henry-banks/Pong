#pragma once
class Particle
{
	float xPos, yPos;
	float xVel, yVel;
	float startTime;
	int lifetime;

	bool isXPos, isYPos;

	bool isActive;

public:
	Particle();
	~Particle();

	//Base reset, for paddle particles
	void resetParticle(float inX, float inY, int inLife);

	/*Paddle collision*/
	void updateParticle();
	void drawParticle(unsigned int color);

	float randVelocity(int maxRange, bool canNeg);

	bool getActive();

};

