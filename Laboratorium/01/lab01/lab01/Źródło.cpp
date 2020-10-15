#include <iostream>
#include "header.h"
using namespace std;

int main()
{
	Punkt p1(1, 2);
	Punkt p2(2, 3);
	p1.drukuj();
	p1.dodaj(p2);
	p1.drukuj();

	Tablica t1(15);
	Tablica t2(30);
	Tablica t3(t2);

	cout <<"Porowannie t2 i t1: "<< t2.porownaj(t1);

}