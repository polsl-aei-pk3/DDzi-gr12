#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
using namespace std;
using namespace sf;

void Player::render(RenderWindow* okno)
{
	rect.setSize(wymiary);
	if (!Rside)
		rect.setPosition(gap, y);
	else
		rect.setPosition(1080 - gap - szer, y);
	okno->draw(rect);
}
void Player::move(int dir)
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