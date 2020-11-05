#include <iostream>

#include "engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace std;
using namespace sf;

//PROJEKT PONG
//GRA DLA DWOCH GRACZY


int main()
{
//	Engine game;
	Gracze* ranking = nullptr;
	
	cout << "WITAM W GRZE W PONG" << endl;
	cout << "ZYCZE MILEJ ROZGRYWKI :-) Dziuk Dawid" << endl << endl;
	cout << "MENU GRY:" << endl;
	cout << "N - Nowa Gra" << endl;
	cout << "R - Ranking graczy" << endl;
	cout << "Q - Wyjscie" << endl;
	char opcja;
	 cin >> opcja;
	//opcja = 'n';
	while (opcja != 'q') {
		switch (opcja)
		{
		case 'r':showRanking(ranking);
			cin >> opcja;
			break;
		case 'n':
			Engine game;
			//GAME LOOP
			while (game.running())
			{
				//UPDATE
				game.update();
				//RENDER
				game.render();
			}

			string nickname;
			cout << " KONIEC GRY ! " << endl;
			cout << " Prosze dopisac sie do rankignu zwyciezcow:...";
			cin >> nickname;

			if(!addScore(ranking,nickname))
				addToRanking(ranking,nickname);
			cin >> opcja;
			break;
		}
	}
	return 0;
}

