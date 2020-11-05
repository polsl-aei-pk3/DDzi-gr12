#ifndef header_H
#define header_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
const int N = 10;
static class User* wsk; // UWAGA zale�no�� mi�dzy obiektami
class  MailBox
{
	// friend class User; ewntualne uzycie seter�w i geter�w
	string mbox[10]; //tablica wiadomo�ci od  uzytkownikow skrzynki
	string logname;	
	int i = 0;			// indeksem tablicy jest id uzytkownika
	string backupname;
	ofstream log; //plik z raportem
	ofstream backup; // zawarto�� mbox do pliku backup gdy usuwamy obiekt
public:
	MailBox(string &log_, string& backup_) : logname(log_), backupname(backup_) {	}// je�eli plik backup  ju� istnieje wczytuje go do mbox
	//~MailBox();
	// zapisuje wszystkie wiadomo�ci do backup i usuwa z pami�ci
	// Uwaga poni�sze metody musz� by� w osobnym pliku:
	bool send(string& msg, User* sender, User* reciever); // uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
	
	string* receive(User* user); // zwraca NULL w przypadku b��du - indeks poza zakresem, lub gdy niema wiadomo�� dla tego u�ytkownika
	void print();
};

class  User
{
	friend class MailBox;
	int id = 0; // zmienna statyczna inkrementowana w konstruktorze b�d�ca id nast�pnego  u�ytkownika
	int myid; // id u�ytkownika
	string nickname;// nazwa u�ytkownika

	//*adres skrzynki z kt�r� jest zwiazany u�ytkownik
public:
	MailBox* mb;
	User(MailBox* mb_, string& nickname_,int id)// : nickname(move(nickname_))//
	{
		myid = id++;
		nickname = nickname_;
		mb = mb_;
		//przypisanie unikalnego id
		// nadanie nazwy u�ytkownikowi
		// przypisanie skrzynki zdefiniowanej wcze�niej
	}
	void send(string& msg, User& reciever)//
	{
		mb->send(msg, this, &reciever); 
		// wywo�ujemy send w klasie Mbox
	};
	bool receive()// pobieram wiadomo�� ze skrzynki
	{
		mb->receive(this); // wywo�ujemy send w klasie Mbox
		// wy�wietla wiadomo�� na ekranie
		// nast�pnie usuwa
	}
};
#endif