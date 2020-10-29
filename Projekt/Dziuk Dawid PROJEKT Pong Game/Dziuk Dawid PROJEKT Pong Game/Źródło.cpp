#include <iostream>
#include "ball.h"
#include "player.h"
#include "ranking.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace std;
using namespace sf;

//PROJEKT PONG
//GRA DLA DWOCH GRACZY
RenderWindow okno(VideoMode(1080, 720), "test");
int main()
{
	Gracze* ranking = nullptr;
	

	//testowanie sfml
	//RenderWindow okno (VideoMode(1080, 720), "test");
	
	 /*Clock stoper;
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
	}*/
	//

	//menu g³ówne
	// wcisnij N zeby zagrac
	// wcisnij S aby sprawdzic ranking
	// wcisnij Q aby wyjsc
	
	cout << "WITAM W GRZE W PONG" << endl;
	cout << "ZYCZE MILEJ ROZGRYWKI :-) Dziuk Dawid" << endl << endl;
	cout << "MENU GRY:" << endl;
	cout << "N-Nowa Gra" << endl;
	cout << "R-Ranking graczy" << endl;
	cout << "Q-WYjscie" << endl;

	char opcja;
	cin >> opcja;
	if (opcja == 'q')
		exit(0);
	else if (opcja == 'r')
	{
		showRanking(ranking);
	}

	return 0;
}

