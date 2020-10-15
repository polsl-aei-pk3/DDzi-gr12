#include <iostream>
#include "header.h"

using namespace std;
int main()
{
	Punkt p1(1, 2);
	Punkt p2(2, 4);
	p1.dodaj(p2);
	p1.drukuj();
	return 0;
}