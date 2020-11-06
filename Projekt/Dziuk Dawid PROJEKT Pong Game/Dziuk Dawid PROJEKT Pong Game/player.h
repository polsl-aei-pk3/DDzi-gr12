#ifndef Player_H_INCLUDED 
#define Player_H_INCLUDED 
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

/*
	Klasa gracz.
*/
class Player {
private:
	//DANE
	bool Rside;		//STRONA
	float gap;		//ODSTEP OD BRZEGU OKNA
	float y;		//WSPOLRZEDNA Y-OWA
	int pkt;		//LICZBA ZDOBYTYCH PUNKTÓW

	//RENDERING:

	//KSZTALT PROSTOKATNY
	RectangleShape rect;
	
	//WYMIARY PROSTOK¥TA
	float szer = 25;
	float wys = 150;
	Vector2f wymiary = { szer,wys };
	
	//PRYWATNE FUNKCJE

	//RENDER GRACZA NA EKRANIE
	void render(RenderWindow* okno);

	//PORUSZANIE GRACZEM
	void move(int dir);	

	//ZEZWOLENIE DOSTEPU 
	friend class Engine;
	friend class Ball;
};
#endif