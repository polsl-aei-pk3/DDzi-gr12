#ifndef ball_H_INCLUDED 
#define ball_H_INCLUDED 
#include"player.h"
/*
	Klasa, pi³ka.
*/
class Ball {
private:
	//WSPOLRZEDNE:
	float x;
	float y;

	//PREDKOSC:
	float xSpeed; 
	float ySpeed;
	float radius;
	float acc;

	//ZMIENNE POMOCNICZE DO WYTWARZANIA LOSOWEJ PREDKOSCI PO PUNKTU:
	float yHI;
	float yLOW;
	float xHI;
	float xLOW;
	Player* player1_pointer;
	Player* player2_pointer;

	//ZEZWOLENIE SILNIKOWI DO ZMIANY TYCH ZMIENNYCH:
		friend class Engine;
	
	//PRYWATNE FUNKCJE
	void render(RenderWindow* okno); //RYSOWANIE FUNKCJI NA EKRANIE
	void move();	//RUCH PI£KI
	void wallBounce();	//ODBICIE OD GORNEJ I DOLNEJ SCIANY ORAZ WYKRYWANIE GOLA
	void playerBounce(Player p);	//ODBICIE OD GRACZA
	void p2Scores();	//RESET PILKI NA SRODEK EKRANU I DODANI GRACZOWI PUNKTU
	void p1Scores();	//RESET PILKI NA SRODEK EKRANU I DODANI GRACZOWI PUNKTU

};
#endif