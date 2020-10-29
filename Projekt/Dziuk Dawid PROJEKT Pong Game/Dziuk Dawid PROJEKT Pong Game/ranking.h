#include <string>
#include<iostream>
using namespace std;

struct Gracze {
	string nick;
	float score;
	Gracze* pNext;
};
void showRanking(Gracze* players);
void addScore(string nickname, Gracze*& players);
void addToRanking(string nickname, Gracze*& players);