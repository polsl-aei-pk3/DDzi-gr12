#include <iostream>
#include "ranking.h"
using namespace std;
void addScore(string nickname, Gracze*& players)
{
	auto p = players;
	while (p->nick != nickname || p == nullptr)
		p = p->pNext;
	if (p)
		p->score++;
}

void addToRanking(string nickname, Gracze*& players)
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