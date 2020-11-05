#include <string>
#include<iostream>
using namespace std;

struct Gracze {
	string nick;
	float score;
	Gracze* pNext;
};
void showRanking(Gracze* players);
bool addScore(Gracze*& players,string nickname);
void addToRanking(Gracze*& players, string nickname);