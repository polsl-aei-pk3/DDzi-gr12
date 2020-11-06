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
	User Czesio(&skrzynkaCzesia, c, id++);
	User Emil(&skrzynkaEmila, e, id++);

	string msg = "msg";
	Bartek.send(msg, Dawid);
	Bartek.send(msg, Dawid);
	Bartek.send(msg, Dawid);
	Bartek.send(msg, Emil);
	Dawid.send(msg, Bartek);
	Dawid.send(msg, Bartek);
	Czesio.send(msg, Emil);
	skrzynkaBartka.print();
	skrzynkaEmila.print();
	skrzynkaDawida.print();
	skrzynkaCzesia.print();



	return 0;
}