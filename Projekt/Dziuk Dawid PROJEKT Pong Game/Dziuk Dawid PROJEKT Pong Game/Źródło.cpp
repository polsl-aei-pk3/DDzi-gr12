#include <iostream>
#include "ball.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace std;
using namespace sf;

int main()
{
	//testowanie sfml
	RenderWindow okno (VideoMode(1080, 720), "essa");
	 Clock stoper;
	while (okno.isOpen())
	{
		  Event event;
		while (okno.pollEvent(event))
		{
			if (event.type ==    Event::Closed)
				okno.close();
		}
		okno.clear();
		CircleShape ksztalt(50, 5);
		ksztalt.setPosition(500, 360);
		okno.draw(ksztalt);

		okno.display();
	}
	
	

	return 0;
}

