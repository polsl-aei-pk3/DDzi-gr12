#ifndef Engine_H_INCLUDED 
#define Engine_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
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
	
	//PRYWATNE FUNKCJE
	void initVar();
	void initWind();
	void initPlayers();
	void initBall();

public:
	//KONSTRUKTORY DESTRUKTORY

	Engine();
	virtual ~Engine();
	//AKCESORY
	const bool running()const;

	//FUNCKJE
	void update();
	void render();
	void pollEvents();

};
#endif