#include "Ball.h"
#include "sfwdraw.h"

#include <vector>
#include <cstdlib>
#include <iostream>

using namespace sfw;

//
//BALL TRAIL
//

void BallTrail::setPoint(int i, float inX, float inY)
{
	points[i].xPos = inX;
	points[i].yPos = inY;

	//Validate point, just in case it was invalid before
	points[i].isValid = true;
}

void BallTrail::init(float inX, float inY)
{
	for (int i = 0; i < TRAIL_LENGTH; i++) {
		//Set all x/y positions to -1 and invalidating them
		setPoint(i, inX, inY);
		points[i].isValid = true;
	}
}

void BallTrail::update(float inX, float inY)
{
	//Check if there are still invalid points in the array
	for (int i = 0; i < TRAIL_LENGTH; i++)
	{
		//If there are, find the first invalid point and set it
		if (!points[i].isValid) {
			setPoint(i, inX, inY);
			return;
		}
	}
	//If not...

	//Temp array to 'save' the current array
	Point2D saveArray[TRAIL_LENGTH];

	//Copy points array into save array
	for (int i = 0; i < TRAIL_LENGTH; i++) {
		saveArray[i] = points[i];
	}

	//Set each point in the 'points' array to the next value (e.g. #1 = #2, #4 = #5, etc)
	for (int i = 0; i < TRAIL_LENGTH - 1; i++) {
		points[i + 1] = saveArray[i];
	}
	//Set the first point to the given position
	setPoint(0, inX, inY);
}

void BallTrail::draw(int color)
{
	for (int i = 0; i < TRAIL_LENGTH - 1; i++)
	{
		//As long as the next point is valid...
		if (points[i + 1].isValid)
		{
			drawLine(points[i].xPos, points[i].yPos, points[i + 1].xPos, points[i + 1].yPos, color);
			
			//I saw some breaks between lines, so I'll have it draw secondary lines that connect to the PREVIOUS point.
			if (i > 0) {
				drawLine(points[i].xPos, points[i].yPos, points[i - 1].xPos, points[i - 1].yPos, color);
			}
			continue;
		}
		//If an invalid point is hit, break the loop
		break;
	}
}


//
//BALL
//

Ball::Ball()
{
	initBall();
}

Ball::~Ball()
{
}

void Ball::initBall()
{
	setXPos(400);
	setYPos(300);
	setXVel(100);
	setYVel(100);

	setIsXPos(true);
	setIsYPos(true);

	trail.init(xPos, yPos);
}

void Ball::initBall(int inTex)
{
	ballTex = inTex;

	//This one's basically the same as the above one, but this one sets the texture
	initBall();
}

void Ball::initBall(int inTex, float inX, float inY, float inXVel, float inYVel, int inRadius, bool inIsX, bool inIsY)
{
	ballTex = inTex;
	xPos = inX;
	yPos = inY;
	xVel = inXVel;
	yVel = inYVel;

	radius = inRadius;

	isXPos = inIsX;
	isYPos = inIsY;

	trail.init(xPos, yPos);
}

void Ball::updateBall(Paddle& paddle, float x, float y)
{

	//After the score hits 101 the ball glitches through the paddle, so I'm setting 100 to a 'win'.
	//Maybe get rid of this?
	if (paddle.score >= 100) {
		printf("\nYou win!\n");
		loseGame = true;
	}
	
	//X-movement
	isXPos ? xPos += getDeltaTime()*xVel : xPos -= getDeltaTime()*xVel;

	//X-collision with wall
	if (xPos >= x) {
		isXPos = false;
		randVelocity(yVel, 180, true);
	}

	//X-collision with paddle.  Paddle collision extended 5 pixels beyond actual paddle
	if (xPos <= paddle.getXPos()+5 && xPos > 5 && (yPos <= paddle.getYPosUp() + 10 && yPos >= paddle.getYPosDown()-5)) {
		isXPos = true;
		randVelocity(yVel, 80, true);
		std::cout << "Score: " << ++paddle.score << std::endl;
		xVel += 25;

		//This (probably) fixes a bug where the ball would collide with the paddle multiple times if it bounced off the very tip.
		xPos = paddle.getXPos() + 5;

		spawnParticles = true;
	}

	if (xPos < 0) {
		resetBall();
	}

	//Y-movement
	isYPos ? yPos += getDeltaTime()*yVel : yPos -= getDeltaTime()*yVel;

	//Y-collision with ceiling
	if (yPos >= y) {
		isYPos = false;
		randVelocity(yVel, 90, false);
	}
	//Y-collision with floor
	if (yPos <= 0) {
		isYPos = true;
		randVelocity(yVel, 90, false);
	}

	//Update the trail
	trail.update(xPos, yPos);
}

//Probably DEPRECATED
void Ball::updateBall(float x, float y)
{
	//X-movement
	isXPos ? xPos += getDeltaTime()*xVel : xPos -= getDeltaTime()*xVel;

	//Y-movement
	isYPos ? yPos += getDeltaTime()*yVel : yPos -= getDeltaTime()*yVel;
	//Y-collision with floor
	if (yPos <= 0) {
		isYPos = true;
		randVelocity(yVel, 90, false);
	}
}

void Ball::resetBall()
{
	//Reset ball collision
	xPos = 400;
	yPos = 300;
	xVel = 100;
	isXPos = true;
	randVelocity(yVel, 180, true);
	
	loseGame = true;

	//Reset the trail
	trail.init(xPos, yPos);
}

void Ball::drawBall(int choice, unsigned int color)
{
	//Draw this first so it's 'under' the ball
	trail.draw(CYAN);

	//Elegent, texture-based ball
	drawTexture(ballTex, xPos, yPos, 20, 20, 0);

	/* Cluttered, geometry-based ball
	switch (choice)
	{
	case 0:
		//Empty circle
		drawCircle(xPos, yPos, radius, 15, color);
		break;
	case 1:
		//Filled circle
		for (int i = radius; i > 0; i--)
		{
			drawCircle(xPos, yPos, i, 15, color);
		}
		break;
	case 2:
		//GLOWY circle
		drawCircle(xPos, yPos, 9, 15, 0x00ffff20);
		drawCircle(xPos, yPos, 8, 15, 0x00ffff50);
		drawCircle(xPos, yPos, 7, 15, 0x00ffff80);
		drawCircle(xPos, yPos, 6, 15, 0x00ffffc0);
		drawCircle(xPos, yPos, 5, 15, 0xFFFFFF80);
		drawCircle(xPos, yPos, 4, 15, 0xFFFFFF60);
		drawCircle(xPos, yPos, 3, 15, 0xFFFFFF40);
		drawCircle(xPos, yPos, 2, 15, 0xFFFFFF20);
		drawCircle(xPos, yPos, 1, 15, 0xFFFFFF05);
		break;
	}
	*/
}

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

float Ball::randVelocity(int maxRange, bool canNeg)
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

//DEPRECATED, this is done in the Particle class
/*
void Ball::spawnParticles(float num, int lifetime, unsigned int color)
{
	//The start of the particles' lives
	float startTime = sfw::getTime();

	std::vector<Ball>particles;
	for (int i = 0; i < num; i++)
	{
		Ball newBall;
		newBall.initBall(xPos, yPos, randVelocity(100, true), randVelocity(100, false), 2, (rand()%1) == 1, (rand()%1) == 1);
		particles.push_back(newBall);
	}

	if (getDeltaTime() - getTime() < lifetime)
	{
			Ball b = particles[0];
			b.updateBall(b.getXPos(), b.getYPos());
			b.drawBall(1, color);
	}
}
*/

//Getters and Setters

float Ball::getXPos() const
{
	return xPos;
}

void Ball::setXPos(float num)
{
	xPos = num;
}

float Ball::getYPos() const
{
	return yPos;
}

void Ball::setYPos(float num)
{
	yPos = num;
}

float Ball::getXVel() const
{
	return xVel;
}

void Ball::setXVel(float num)
{
	xVel = num;
}

float Ball::getYVel() const
{
	return yVel;
}

void Ball::setYVel(float num)
{
	yVel = num;
}

bool Ball::getIsXPos() const
{
	return isXPos;
}

void Ball::setIsXPos(bool in)
{
	isXPos = in;
}

bool Ball::getIsYPos() const
{
	return isYPos;
}

void Ball::setIsYPos(bool in)
{
	isYPos = in;
}