#ifndef Player_H_INCLUDED 
#define Player_H_INCLUDED 
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Player {
	friend class Engine;
	friend class Ball;
protected:
	Font font;
	bool Rside;
	//float x;
	float gap = 25;
	float y=(float)(720/2);
	int pkt=0;
	RectangleShape rect;
	float szer = 25;
	float wys = 150;
	Vector2f wymiary = { szer,wys };
	
	//float acceleration = 0;
	//float ySpeed;
public:
	void render(RenderWindow* okno)
	{
		rect.setSize(wymiary);
		if (!Rside) 		
			rect.setPosition(gap, y);
		else		
			rect.setPosition(1080-gap-szer, y);
		okno->draw(rect);
	}
	void move(int dir)
	{
		float acceleration = 0.5;
		float ySpeed = 0;
		
		if (y > -1 && y < (720 - 150 + 1)) { //JESLI GRACZE ZNAJDUJE SIE W OKNIE TO WYKONAC RUCH
			ySpeed = ySpeed + acceleration;
			y = y + ySpeed * dir;

		}
		else if (y == -1) //JESLI GRACZ WYCHODZI POZA GORNA GRANICE
			y = 0;
		else if (y == (720 - 150 + 1))//JESLI GRACZ WYCHODZI POZA DOLNA GRANICE
			y = 720 - 150;
	}
	void checkWin()
	{
		if(pkt==10){
		//	 newGame();
		// addToRanking();
		}
	}
	void score()
	{
		
		
	}

	
};
#endif