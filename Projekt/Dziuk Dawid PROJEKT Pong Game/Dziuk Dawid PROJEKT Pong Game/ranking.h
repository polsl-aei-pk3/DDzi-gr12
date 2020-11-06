#include <string>
#include<iostream>
using namespace std;
/*
	LISTA JEDNOKIERUNKOWA Z RANKINGIEM GRACZY.
*/
//STRUKTURA GRACZ LISTA JEDNOKIERUNKOWA
struct Gracze {
	string nick;
	float score;
	Gracze* pNext;
};
void showRanking(Gracze* players); //POKAZUJE RANKING GRACZY
bool addScore(Gracze*& players,string nickname);	//DODAJE PUNKT GRACZOWI KTORY JEST JUZ W RANKINGU
void addToRanking(Gracze*& players, string nickname);	//DODAJE NOWEGO GRACZA DO RANKINGU