#include <iostream>
using namespace std;
class Szachownica
{
	friend class Figura;
	friend class Goniec;
	friend class Wieza;
protected:
	Figura* sz[8][8];// tablica kontrolna zawieraj¹ca wska¿niki do ustawionych figur
	// NULL w przypadku gdy pole jest puste;
	char wiz[8][8];// tablica do wizualizacji :
	//'O' pole puste 'X' pole bite , 'G'- polo¿enie goñca,
	// 'W' - po³o¿enie wie¿y; zapisywane przez metodê range klasy Figura
public:
	Szachownica()// tworzy pust¹ szachownicê: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 
	{
		clear();
	}
	void showRange(); // metoda wywo³uje na wszystkich polach tablicy sz (ró¿nych od NULL)
	//metodê wirtualn¹ range 
	void display(); // wyœwietla szachownnice (tablica wiz)
	void clear();// tworzy pust¹ szachownice, wywo³uje metode remove na wszystkich polach tablicy sz (ró¿nych od NULL)
  // UWAGA usuniêcie figury nie oznacza usuniêcie z pamiêci - nie wywo³ujemy delete
	
};
class Figura
{
protected:
	Szachownica* s; //figura zna swoj¹ szachownice - ustawiane przez set
	int x, y; // po³o¿enie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 							 //UWAGA:(friend nie jest dziedziczony)
	{
		s->wiz[x][y] = z;//sprawdzic czy pole nie jest zajête (zwracamy wtedy false)
		return true;
	};
	bool set(int x, int y, Figura* f)// ustawia pole x,y tablicy sz na wskaŸnik do klasy dziedzicz¹cej z klasy Figura (Wieza , Goniec)
	{
		s->sz[x][y] = f;//sprawdzic czy pole nie jest zajête (zwracamy wtedy false)
		return true;
	};
public:
	Figura() { s == NULL; };
	virtual bool set(Szachownica* s, int x_, int y_) = 0;
	//metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zajête
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza czêœæ zadania)
	// za pomoc¹ set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()
	{
		if (s != NULL) {
			s->sz[x][y] = NULL; s = NULL;
			s->wiz[x][y] = '.';
			s = NULL;// ustawia s na NULL - figura zdjêta z szachownicy 
		}
	};
	virtual void range() = 0;//pokazuje zasiêg bicia na szachownicy - operuje na tablicy wiz 
// klasy Szachownica

};

class Wieza : public Figura
{
public:
	Wieza(Szachownica *s_,int x_,int y_) :Figura() {
		set(s_, x_, y_);
	};
	bool set(Szachownica* s_, int x_, int y_)
	{
		s = s_;
		if (s->wiz[x_][y_] == '.')
		{
			//cout << "sss";
			x = x_;
			y = y_;
			Figura::set(x_, y_, 'W');
			return 1;
		}
		else return 0;
		
			
		// wywo³aæ set(int x,int y,Figura *f) z odpowiednim parametrem
		
	}
	void range() {
		for (int i = 0; i < 8; i++)
		{
				s->wiz[x][i] = 'b';
				s->wiz[i][y] = 'b';
				s->wiz[x][y] = 'W';
			
		}
	}
	//zdefiniowaæ zasiêg bicia dla Wie¿y
};
class Goniec : public Figura
{
public:
	Goniec(Szachownica* s_, int x_, int y_) :Figura() {
		set(s_, x_, y_);

	};
	bool set(Szachownica* s_, int x_, int y_)
	{
		s = s_;


		if (s->wiz[x_][y_] == '.')
		{
			//cout << "sss";
			x = x_;
			y = y_;
			Figura::set(x_, y_, 'G');
			return 1;
		}
		else return 0;
	}
	void range() {
		int dx[4] = { -1,-1,1,1 };
		int dy[4] = { -1,1,-1,1 };

		for (int dir = 0; dir < 4; dir++) {
			for (int i=1;i<8;i++)
			{
				int new_x, new_y;
				new_x = x + dx[dir] * i;
				new_y = y + dy[dir] * i;

				if (new_x >= 0 && new_x < 8 && new_y>=0 && new_y < 8)
				{
					if (s->wiz[new_x][new_y] == '.')
					{
						s->wiz[new_x][new_y] = 'b';

					}
					else break;
				}
				else break;
		
			}
		}
	}
};

