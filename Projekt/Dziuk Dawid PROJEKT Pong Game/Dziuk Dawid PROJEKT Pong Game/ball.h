#ifndef ball_H_INCLUDED 
#define ball_H_INCLUDED 
#include <iostream>
using namespace std;
using namespace sf;

class Ball {
private:
	float x=1080/2; // width/2
	float y=720/2;	//height/2
	float xSpeed=0.25; 
	float ySpeed=0.25;
	float radius = 20;

	float yHI=0.25;
	float yLOW=-0.25;
	float xHI=0.4;
	float xLOW=0.25;
		friend class Engine;

	void render(RenderWindow* okno)	{
		CircleShape ball(radius, 50);
		ball.setPosition(x , y);
		okno->draw(ball);
		
	}
	void move()	{
		x += xSpeed;
		y += ySpeed;
	}
	void wallBounce()	{
		if (y < radius / 2 || y>720 - 10)
			ySpeed = ySpeed * (-1);
		if (x > 1080)
			p2Scores();
		if (x < 0)
			p1Scores();
	}
	void playerBounce()	{

	}
	void p1Scores()	{
		cout << "p1win";
		x = 1080 / 2;
		y = 720 / 2;

		float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
		float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));

		xSpeed = xRandom * (-1);
		ySpeed = yRandom * (-1);
	}
	void p2Scores(){
		cout << "2win";
		x = 1080 / 2;
		y = 720 / 2;

		float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
		float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));

		xSpeed = xRandom;
		ySpeed = yRandom;
	}

};
#endif