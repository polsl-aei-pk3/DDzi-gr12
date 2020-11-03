#pragma once
#include "engine.h"
#include "player.h"
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
	p1.Rside = true;
	p2.Rside = false;
}

void Engine::initBall()
{
	Ball ball;
}

//KONSTRUKTORY DESTRUKTORY
Engine::Engine()
{
	this->initVar();
	this->initWind();
	this->initPlayers();
	//this->initBall();
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
