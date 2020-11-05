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
	
	//font.loadFromFile("font.ttf"); //INICIALIZACJA CZCIONKI SCORE
	p1.Rside = true;	
	p2.Rside = false;
}

void Engine::initBall()
{
	
	ball.player1_pointer = &p1;
	ball.player2_pointer = &p2;
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
	
}

Engine::~Engine()
{
	delete this->okno;
}

//AKCESORY
const bool Engine::running() const
{
	return this->okno->isOpen();
}
//FUNKCJE
void Engine::update()
{
	this->pollEvents();
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

void Engine::pollEvents()
{
	if (Keyboard::isKeyPressed(Keyboard::Down))
		p1.move(1);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		p1.move(-1);

	if (Keyboard::isKeyPressed(Keyboard::S))
		p2.move(1);
	if (Keyboard::isKeyPressed(Keyboard::W))
		p2.move(-1);

	while (this->okno->pollEvent(this->ev))
	{
		if (ev.type == Event::Closed)
			this->okno->close();
		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			this->okno->close();
		
	}
}
