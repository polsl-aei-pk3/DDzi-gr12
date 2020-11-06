#include "header.h"

bool MailBox::send(string& msg, User* sender, User* reciever)
{
	// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazw�  nadawcy oraz odbiorcy
	// w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
	// jezeli id odbiorcy jest r�wna id nadawcy wiadomo�� odrzucamy i zwracamy false
	// umieszczamy tresc wiadomo�ci  czas nadania i adres nadawcy   w tablicy pod indeksem b�d�cym id odbiorcy
	// je�eli by�a wiadomo�� nie odebrana doklejamy j� (operator + na klasie string) wiadomo�ci odzielone s�
	// �a�cuchem "\n***********\n"

	if (!sender || !reciever)
		return false;
	else
	{
		
		reciever->mb->mbox[reciever->i] = msg;
	
	
		reciever->mb->log << "Wiadomosc #" << reciever->i <<" "<< reciever->mb->mbox[reciever->i] << endl;
			reciever->i++;
		return true;
	}

}
//string* MailBox::receive(User* user)



void MailBox::print()
{
	for (int i = 0; i < N; i++)
	{
		cout <<"Wiadomosc " << i << ": " << mbox[i] << endl;
	}
}; // wy�ietla wszystkie wiadomo�ci w skrynce