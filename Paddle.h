#pragma once
class Paddle
{

	float xPos, yPos;

	////Upper and Lower collision, extends 10 px above/below paddle
	float yPosUp;
	float yPosDown;

	int highScore;
	
	int width;
	int height;

public:
	Paddle();
	~Paddle();

	//I'm sorry, I need to keep this public in order to preserve my sanity
	int score = 0;

	/*Initializes a new paddle.
	inXPos: The x-position of the paddle.  Used as the FRONT of the paddle when calculating width.
	inSize: The Height of the paddle (will always be odd)
	inWidth: The width of the paddle*/
	void initPaddle(float inXPos, float inHeight, float inWidth);

	/*Draws the paddle*/
	void drawPaddle(unsigned int color);

	//Updates the paddle
	void updatePaddle();

	float getXPos() const;
	void setXPos(float num);

	float getYPos() const;
	void setYPos(float num);

	//These two values are dervied from yPos and do not have setters

	float getYPosUp() const;
	float getYPosDown() const;

	float getScore() const;
	void setScore(float num);

	float getWidth() const;
	void setWidth(float num);

	float getHeight() const;
	void setHeight(float num);
	
	//Call this when the ball goes out of the window.
	void resetScore();
	int getHighScore() const;
};