#ifndef header_H
#define header_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
const int N = 10;
static class User* wsk; // UWAGA zale¿noœæ miêdzy obiektami
class  MailBox
{
	// friend class User; ewntualne uzycie seterów i geterów
	string mbox[10]; //tablica wiadomoœci od  uzytkownikow skrzynki
	string logname;	
	int i = 0;			// indeksem tablicy jest id uzytkownika
	string backupname;
	ofstream log; //plik z raportem
	ofstream backup; // zawartoœæ mbox do pliku backup gdy usuwamy obiekt
public:
	MailBox(string &log_, string& backup_) : logname(log_), backupname(backup_) {	}// je¿eli plik backup  ju¿ istnieje wczytuje go do mbox
	//~MailBox();
	// zapisuje wszystkie wiadomoœci do backup i usuwa z pamiêci
	// Uwaga poni¿sze metody musz¹ byæ w osobnym pliku:
	bool send(string& msg, User* sender, User* reciever); // uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
	
	string* receive(User* user); // zwraca NULL w przypadku b³êdu - indeks poza zakresem, lub gdy niema wiadomoœæ dla tego u¿ytkownika
	void print();
};

class  User
{
	friend class MailBox;
	int id = 0; // zmienna statyczna inkrementowana w konstruktorze bêd¹ca id nastêpnego  u¿ytkownika
	int myid; // id u¿ytkownika
	string nickname;// nazwa u¿ytkownika

	//*adres skrzynki z któr¹ jest zwiazany u¿ytkownik
public:
	MailBox* mb;
	User(MailBox* mb_, string& nickname_,int id)// : nickname(move(nickname_))//
	{
		myid = id++;
		nickname = nickname_;
		mb = mb_;
		//przypisanie unikalnego id
		// nadanie nazwy u¿ytkownikowi
		// przypisanie skrzynki zdefiniowanej wczeœniej
	}
	void send(string& msg, User& reciever)//
	{
		mb->send(msg, this, &reciever); 
		// wywo³ujemy send w klasie Mbox
	};
	bool receive()// pobieram wiadomoœæ ze skrzynki
	{
		mb->receive(this); // wywo³ujemy send w klasie Mbox
		// wyœwietla wiadomoœæ na ekranie
		// nastêpnie usuwa
	}
};
#endif