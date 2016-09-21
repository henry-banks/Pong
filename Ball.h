#pragma once
#include "Paddle.h"

//2D point, used for ball trail
struct Point2D
{
	float xPos, yPos;
	//Not sure if necessary, but will keep just in case
	bool isValid;
};

//Used to set the length of the trail
const int TRAIL_LENGTH = 20;

//A trail behind the ball
class BallTrail
{
	//Using a static array to make sure it doesn't accidentally 'grow' like a vector could.  Add 9 so that it isn't inside the ball
	Point2D points[TRAIL_LENGTH];

	//Sets a point in one line, reducing clutter
	void setPoint(int i, float inX, float inY);
public:
	/*Initializes the ball
	inBall: a base ball that is used to set the position of all the points*/
	void init(float inX, float inY);
	void update(float inX, float inY);
	void draw(int color);

};

class Ball
{
	float xPos = 400, yPos = 300;
	float xVel = 100, yVel = 100;
	
	//DEPRECATED, used for geometry-ball
	int radius;

	int ballTex;

	bool isXPos = true, isYPos = true;
	//Used as a trigger to tell the game state to spawn particles.

	BallTrail trail;

public:

	Ball();
	~Ball();
	void initBall();
	void initBall(int inTex);
	void initBall(int inTex, float inX, float inY, float inXVel, float inYVel, int inRadius, bool inIsX, bool inIsY);

	//Trigger for particle spawning, set to true when ball collides with paddle.
	bool spawnParticles = false;
	//Trigger for game loss, set to true when ball leaves window.
	bool loseGame = false;

	/*Checks to see if ball has collided with a corner
	Paddle: The player's paddle.  Used to see if the ball has hit the paddle
	x: x-boundry of the window.  Used to check for ceiling/floor collision
	y: y-boundry of the window.  Used to check for wall collision*/
	void updateBall(Paddle& paddle, float x, float y);
	void updateBall(float x, float y);

	/*Resets the ball*/
	void resetBall();

	/*Draws trhe ball
	choice: Draws a different type of ball based on integer given
		0: empty circle
		1: filled circle
		3: 'glowing' cyan circle
	color: hexidecimal color of ball
	*/
	void drawBall(int choice, unsigned int color);

	/*Creates a random velocity within the range (in degrees) given.
	inVel(optional): Velocity to change (use ballName.xVel/yVel).  Using this will set the velocity given.
	maxRange: The maximum range (in degrees) that the new velocity can be.
	canNeg: Whether or not the velocity can be negative (set to false if bouncing off floor/ceiling).
	*/
	void randVelocity(float& inVel, int maxRange, bool canNeg);
	float randVelocity(int maxRange, bool canNeg);

	//void spawnParticles(float num, int lifetime, unsigned int color);

	float getXPos() const;
	void setXPos(float num);

	float getYPos() const;
	void setYPos(float num);

	float getXVel() const;
	void setXVel(float num);

	float getYVel() const;
	void setYVel(float num);

	bool getIsXPos() const;
	void setIsXPos(bool in);

	bool getIsYPos() const;
	void setIsYPos(bool in);
};

