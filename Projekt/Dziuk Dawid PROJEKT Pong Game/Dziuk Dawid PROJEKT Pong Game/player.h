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
	//DANE
	bool Rside;			//STRONA
	float gap = 25;		//ODSTEP OD BRZEGU OKNA
	float y=720/2;		
	int pkt=0;

	//RENDERING:
	RectangleShape rect;
	float szer = 25;
	float wys = 150;
	Vector2f wymiary = { szer,wys };
	
	
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
	
	

	
};
#endif