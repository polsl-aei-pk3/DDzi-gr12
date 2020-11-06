#pragma once
#include "engine.h"
#include "player.h"
#include <string>
#include "ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
//PRYWATNE FUNKCJE
void Engine::initVar()
{
	this->okno = nullptr;

}

void Engine::initWind()
{
	this->videomode.width = 1080;
	this->videomode.height = 720;
	this->okno = new RenderWindow(this->videomode, "PONG GAME");
}

void Engine::initPlayers()
{
	
	p1.gap = 25;		
	p1.y = 720 / 2;
	p1.pkt = 0;

	p2.gap = 25;		
	p2.y = 720 / 2;
	p2.pkt = 0;

	
	p1.Rside = true;	
	p2.Rside = false;
}

void Engine::initBall()
{
	ball.yHI = 0.25;
	ball.yLOW = 0.25;
	ball.xHI = 0.4;
	ball.xLOW = 0.25;

	ball.xSpeed = 0.25;
	ball.ySpeed = 0.25;
	ball.acc=(-1.1);
	ball.radius = 20;

	ball.x = 1080 / 2;
	ball.y = 720 / 2;
	ball.player1_pointer = &p1;
	ball.player2_pointer = &p2;
}

void Engine::initRank()
{
	ranking = nullptr;
}

void Engine::initScore()
{
	
	if (!font.loadFromFile("font.ttf"))
		cout << "Wystapil problem ze wczytaniem czcionki";
	
	scoreTextP1.setString(to_string(0));
	scoreTextP1.setCharacterSize(50);
	scoreTextP1.setFillColor(Color::Black);
	scoreTextP1.setPosition(50, 35);
	scoreTextP1.setFont(font);

	scoreTextP2.setString(to_string(0));
	scoreTextP2.setCharacterSize(50);
	scoreTextP2.setFillColor(Color::Black);
	scoreTextP2.setPosition(1000, 35);
	scoreTextP2.setFont(font);
}
void Engine::score(Player p)
{
	if(p.Rside)
	scoreTextP1.setString(to_string(p.pkt));
	else
	scoreTextP2.setString(to_string(p.pkt));
	
}



//KONSTRUKTORY DESTRUKTORY
Engine::Engine()
{
	this->initVar();
	this->initWind();
	this->initPlayers();
	this->initBall();
	this->initScore();
	this->initRank();
	
}

Engine::~Engine()
{
	delete this->okno;
}

//FUNKCJE
void Engine::update()
{
	/*
		@return void

		-pobiera dane z klawiatury (pollEvents)
		-porusza pi³k¹ (ball.move)
		-odbija pilke i sprawdza czy zostal zdobyty punkt (ball.wallBounce)
		-odbija pilke od gracza (ball.playerBounce)
		-wyswietla punkty (score)
	*/

	pollEvents();
	ball.move();
	ball.wallBounce();
	ball.playerBounce(p1);
	ball.playerBounce(p2);
	score(p2);
	score(p1);
}

void Engine::render()
{
	/*	
		@return void

		-czysci okno
		-renderuje obiekty
		-wyswietla je w oknie
		Renderuje obiekty gry
	*/
	
	this->okno->clear(Color(255, 220, 245));
	p1.render(okno);
	p2.render(okno);
	ball.render(okno);
	this->okno->draw(scoreTextP1);
	this->okno->draw(scoreTextP2);
	
	//RYSUJ GRE
	this->okno->display();
}

void Engine::endGame(Gracze *&ranking)
{
	string nickname;
	cout << " KONIEC GRY ! " << endl;
	cout << " Prosze dopisac sie do rankignu zwyciezcow:...";
	cin >> nickname;

	if (!addScore(ranking, nickname))
		addToRanking(ranking, nickname);
}

void Engine::pollEvents()
{

	//STEROWANIE DLA GRACZA PIERWSZEGO
	//RUCH W DÓ£
	if (Keyboard::isKeyPressed(Keyboard::Down))
		p1.move(1);
	//RUCH W GÓRE
	if (Keyboard::isKeyPressed(Keyboard::Up))
		p1.move(-1);

	//STEROWANIE DLA GRACZA DRUGIEGO
	//RUCH W DÓ£
	if (Keyboard::isKeyPressed(Keyboard::S))
		p2.move(1);

	//RUCH W GÓRE
	if (Keyboard::isKeyPressed(Keyboard::W))
		p2.move(-1);

	//KIEDY GRA MA SIE WYLACZYC
	while (this->okno->pollEvent(this->ev))
	{
		//GDY ZOSTANIE ZAMNIETE OKNO
		if (ev.type == Event::Closed)
			this->okno->close();

		//GDY ZOSTANIE WCISNIETY PRZYCISK ESCAPE
		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			this->okno->close();
		
	}
}
