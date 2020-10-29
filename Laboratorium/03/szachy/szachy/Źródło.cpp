#include "header.h"
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char* argv[])
{ 
	

	Szachownica* szachW=new Szachownica;
	Szachownica* szachG = new Szachownica;
	Szachownica* szach2 = new Szachownica;

	Goniec g1(szachG, 3, 1);
	Wieza w1(szachW ,1, 5);
	
	
	Goniec g2(szach2, 2, 4);
	Wieza w2(szach2, 7, 5);
	
	g1.range();
	szachG->display();
	cout << endl;
	w1.range();
	szachW->display();
	cout << endl;
	szach2->display();
	// uzupe³niæ 
}
