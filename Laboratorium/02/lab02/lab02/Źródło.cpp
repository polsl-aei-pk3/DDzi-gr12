#include <iostream>
#include "header.h"

using namespace std;

int main()
{
	//PUNKTY
		
	Punkt p1(8, 3);
	Punkt p2(5, 6);
	Punkt p3(5, 6);
	Punkt p4(1, 2);

	p4 = p1;
	cout << p4;

	if (p2 == p3)
		cout << "Punkt p2 jest taki sam jak punkt p3" << endl;
	else
		cout << " Punkt p2 nie jest taki sam jak punkt 3" << endl;

	cout << p1 << endl << endl;
	//TABLICA

	float xTab[5] = { 2,3,5,7,11 };
	float yTab[5] = { 1,4,6,8,10 };
	Tablica(xTab,yTab, sizeof(xTab));
	//cout << T;


	return 0;
}