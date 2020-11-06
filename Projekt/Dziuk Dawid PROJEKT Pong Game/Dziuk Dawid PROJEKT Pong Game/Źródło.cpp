#include <iostream>
#include "ball.h"
#include "player.h"
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace std;
//using namespace sf;

//PROJEKT PONG
//GRA DLA DWOCH GRACZY


int main()
{
	//INICJALIZACJA WSKAZNIKA NA RANKING GRACZY
	Gracze* ranking = nullptr;
	
	//MENU G£ÓWNE
	cout << "WITAM W GRZE W PONG" << endl;
	cout << "ZYCZE MILEJ ROZGRYWKI :-) Dziuk Dawid" << endl << endl;
	cout << "Po kazdym odbiciu od gracza predkosc pilki wzrasta." << endl;
	cout << "Rozgrywka trwa do 10 punktów" << endl;
	cout << "Sterowanie: " << endl;
	cout << "Gracz po lewej stronie: klawisze W i S" << endl;
	cout << "Gracz po prawej stronie: strzalki w gore i w dol" << endl << endl;
	cout << "MENU GRY:" << endl;
	cout << "N - Nowa Gra" << endl;
	cout << "R - Ranking graczy" << endl;
	cout << "Q - Wyjscie" << endl;
	
	//ZMIENNA WYBOR OPCJI Z MENU
	char opcja;
	cin >> opcja;

	//DOPÓKI OPCJ¥ NIE BEDZIE Q -WYJŒCIE
	while (opcja != 'q') {
		switch(opcja)
		{
		case 'r':	
					showRanking(ranking);
					cin >> opcja;
					break;
		case 'n':	
					//INICJALIZAJCA SILNIK GRY
					Engine game;
					//GAME LOOP
					while (game.running())	{
					//UPDATE
					game.update();
					//RENDER
					game.render();
					}
					//KONIEC GRY - DODANIE DO RANKINGU
					game.endGame(ranking);
					cin >> opcja;
					break;
		}
	}
	return 0;
}

