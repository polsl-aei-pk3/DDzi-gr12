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
	Player* player1_pointer;
	Player* player2_pointer;
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
	void wallBounce()	{  //ZWRACA 1  JELIS GRACZ PO LEWEJ ZDOBYL BRAMKE ,0- JESLI GRACZE PO PRAWEJ ZDOBYL BRAMKE;
		if (y < radius / 2 || y>720 - 10)
			ySpeed = ySpeed * (-1);
		if (x > 1080)
			p2Scores();
		if (x < 0)
			p1Scores();
				
	}
	void playerBounce(Player p)	{
		if (p.Rside)	//DLA GRACZA Z PRAWEJ STRONKY
			if ((x+radius*2<1080)&&(x+2*radius >1080-p.szer-p.gap)&&(y>p.y)&&(y<p.y+p.wys)&&(xSpeed>0)) 
				xSpeed = xSpeed * (-1); //ZMIEN KIERUNEK
		if (!p.Rside)	//DLA GRACZA Z LEWEJ STRONY
			if ((x - radius < p.szer) && (x > radius) && (y > p.y) && (y < p.y + p.wys) && (xSpeed < 0))
				xSpeed = xSpeed * (-1);		//ZMIEN KIERUNEK
	}
	void p2Scores()	{
		x = 1080 / 2;
		y = 720 / 2;

		player1_pointer->pkt++;
		
		float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
		float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));

		
			xSpeed = xRandom ;
			ySpeed = yRandom ;
			
		
	}
	void p1Scores(){
		x = 1080 / 2;
		y = 720 / 2;

		player2_pointer->pkt++;
		

		float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
		float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));

		xSpeed = xRandom * (-1);
		ySpeed = yRandom * (-1);
	}

};
#endif