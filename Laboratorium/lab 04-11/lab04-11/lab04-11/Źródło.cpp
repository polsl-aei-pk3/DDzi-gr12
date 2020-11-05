#include "header.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int id = 0;
	
	string e = "emil";
	string b = "bartek";
	string c = "czesio";
	string d = "Dawid";
	MailBox skrzynkaBartka(b,b);
	MailBox skrzynkaCzesia(b, b);
	MailBox skrzynkaDawida(d, d);
	MailBox skrzynkaEmila(e, e);
	
	User Bartek(&skrzynkaBartka, b,  id++);
	User Dawid(&skrzynkaDawida, d, id++);

	string msg = "msg";
	Bartek.send(msg, Dawid);
	skrzynkaBartka.print();
	skrzynkaDawida.print();
	Bartek.send(msg, Dawid);
	skrzynkaDawida.print();



	return 0;
}