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
private:
	//ZMIENNE
	RenderWindow *okno;
	VideoMode videomode;
	Event ev;
	Player p1;
	Player p2;
	Ball ball;
	Font font;
	Text scoreTextP1;
	Text scoreTextP2;
	Gracze* ranking;
	//PRYWATNE FUNKCJE
	void initVar();
	void initWind();
	void initPlayers();
	void initBall();
	void initRank();
	void initScore();
	void score(Player p);
	void addToRanking(string nick,Gracze *ranking);

public:
	//KONSTRUKTORY DESTRUKTORY

	Engine();
	virtual ~Engine();
	//AKCESORY
	//AKCESORY
	const bool running()const
	{
		if (p1.pkt == 5 || p2.pkt == 5)
			return 0;
		else
			return this->okno->isOpen();

	}

	//FUNCKJE
	void update();
	void render();
	void pollEvents();

};
#endif
