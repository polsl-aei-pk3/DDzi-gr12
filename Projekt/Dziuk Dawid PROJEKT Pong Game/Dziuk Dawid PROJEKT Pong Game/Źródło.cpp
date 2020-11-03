#include <iostream>
//#include "ball.h"
//#include "player.h"
#include "ranking.h"
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace std;
using namespace sf;

//PROJEKT PONG
//GRA DLA DWOCH GRACZY

Gracze* ranking = nullptr;
int main()
{
	Engine game;
	
	cout << "WITAM W GRZE W PONG" << endl;
	cout << "ZYCZE MILEJ ROZGRYWKI :-) Dziuk Dawid" << endl << endl;
	cout << "MENU GRY:" << endl;
	cout << "N - Nowa Gra" << endl;
	cout << "R - Ranking graczy" << endl;
	cout << "Q - Wyjscie" << endl;
	char opcja;
	//cin >> opcja;
	opcja = 'n';
	switch (opcja)
	{
	case 'r':showRanking(ranking);
		break;
	case 'q':exit(0);
		break;
	case 'n':
			//GAME LOOP
		while (game.running())
		{
			//UPDATE
			game.update();
			//RENDER
			game.render();
		}		   		 	  	  
		break;
	}
	return 0;
}

