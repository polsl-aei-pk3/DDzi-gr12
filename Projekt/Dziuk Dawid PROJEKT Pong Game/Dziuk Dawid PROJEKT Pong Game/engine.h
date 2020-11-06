#ifndef Engine_H_INCLUDED 
#define Engine_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "ranking.h"
#include "ball.h"

using namespace sf;
/*
	Klasa, ktora dziala jako silnik gry.
*/

class Engine
{
public:
	//ZMIENNA MOWI DO ILU PUNKTOW TRWA ROZGRYWKA
	int scoreMax = 10;
private:
	//ZMIENNE

	//ZMIENNE ODPOWIEDZIALNE ZA POWSTANIE OKNA PROGRAMU
	RenderWindow *okno;
	VideoMode videomode;

	//ZMIENNA PRZY POMOCY KTOREJ POBIERANE SA DANE Z KLAWIATURY
	Event ev;

	//ZAWODNICY
	Player p1;
	Player p2;

	//PILKA
	Ball ball;

	//ZMIENNE ODPOWIEDZIALNE ZA TWORZENIE LICZNIKA PUNKTÓW
	Font font;
	Text scoreTextP1;
	Text scoreTextP2;

	//RANKING GRACZY
	Gracze* ranking;

	//PRYWATNE FUNKCJE, KTÓRE INICJALIZUJ¥ POWY¯SZE ZMIENNE
	void initVar();
	void initWind();
	void initPlayers();
	void initBall();
	void initRank();
	void initScore();

	//WYSYLA LICZBE PUNKTOW GRACZA DO FUNKCJI WYWSIETLAJACEJ PUNKTY
	void score(Player p);

public:
	//KONSTRUKTORY DESTRUKTORY

	Engine();
	virtual ~Engine();

	//AKCESOR, KIEDY GRA MA DZIALAC A KIEDY NIE
	const bool running()const
	{
		if (p1.pkt == scoreMax || p2.pkt == scoreMax) //
			return 0;
		else
			return this->okno->isOpen();

	}

	//FUNCKJE
	void update(); //AKTUALIZUJE ZMIENNE
	void render();	//WYSWIETLA OBIEKTY GRY
	void endGame(Gracze *&ranking);	//CO SIE DZIEJE PO ZAKONCZENIU ROZGRYWKI
	void pollEvents(); //POBIERA DANE Z GRY

};
#endif
