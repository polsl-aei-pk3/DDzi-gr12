#include <iostream>
#include <fstream>
#include "ranking.h"
using namespace std;
bool addScore(Gracze*& players, string nickname)
{


	
	auto p = players;
	if (p) {

		

		
		while (p->nick != nickname)
		{


			if (p->pNext == nullptr)
				return 0;

			p = p->pNext;
		}
			
		if (p) {
			p->score++;
			return 1;

		}
	}
	else return 0;
	
		
}

void addToRanking(Gracze*& players, string nickname)
{
	//petla po liœcie graczy, jezeli gracz sie znajdue to score++
	//else utworz element listy i ustaw score na 1;

	if (players == nullptr)
		players = new Gracze{ nickname, 1, nullptr };
	else
	{
		Gracze* pNowy = new Gracze{ nickname,1,nullptr };
		auto p = players;
		while (p->pNext) 
			p = p->pNext;
		
			
		p->pNext = pNowy;
	}


}
void showRanking(Gracze* players)
{
	if (players != nullptr)
	{
		Gracze* pTemp = players;
		while (pTemp)
		{
			cout << "Gracz: " << pTemp->nick << " Liczba zwyciestw: " << pTemp->score << endl;
			pTemp = pTemp->pNext;
		}
	}
	else
		cout << "Ranking jest pusty.";

}