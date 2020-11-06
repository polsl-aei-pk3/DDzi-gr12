#include "header.h"

bool MailBox::send(string& msg, User* sender, User* reciever)
{
	// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazwê  nadawcy oraz odbiorcy
	// w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
	// jezeli id odbiorcy jest równa id nadawcy wiadomoœæ odrzucamy i zwracamy false
	// umieszczamy tresc wiadomoœci  czas nadania i adres nadawcy   w tablicy pod indeksem bêd¹cym id odbiorcy
	// je¿eli by³a wiadomoœæ nie odebrana doklejamy j¹ (operator + na klasie string) wiadomoœci odzielone s¹
	// ³añcuchem "\n***********\n"

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
}; // wyœietla wszystkie wiadomoœci w skrynce