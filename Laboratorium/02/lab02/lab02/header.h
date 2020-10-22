#pragma once
#include <iostream>
using namespace std;
class Punkt
{
protected:
	float x;
	float y;

public:
	Punkt() { x = 0; y = 0; };
	void drukuj()
	{
	cout<< "Wspolrzedne punktu:" << x << " x " << y << endl;
	}
	Punkt(float x_, float y_)
	{
		x = x_;
		y = y_;
	}
	void dodaj(Punkt& p)
	{
		x += p.x;
		y += p.y;
	}
	void operator=(Punkt& p)
	{
		if (this != nullptr) {
			x = p.x;
			y = p.y;
		}
	}
	Punkt operator+=(Punkt &p)
	{
		this->dodaj(p);
		return(*this);

	}
	Punkt operator+(Punkt& p1)
	{
		Punkt tmp(0,0);
		tmp.x = this->x + p1.x;
		tmp.y = this->y + p1.y;
		return tmp;
	}
	int operator==(Punkt& p) //1- this niemniejsze od p
	{
		if (x == p.x || y == p.y)
			return 1;
		else
			return 0;
	}
	friend ostream& operator<<(ostream& wyjscie,const Punkt & p );
	


};

ostream& operator<<(ostream& wyjscie,const Punkt &p)
{
	return wyjscie << "Wspolrzedna X: " << p.x << ",wspolrzedna Y:" << p.y << endl;
}
class Tablica
{
private:
	Punkt* w;
	int dl;
public:
	
	Tablica() { dl = 0; w = nullptr; };
	Tablica(Punkt p, int dl_)
	{
			*w = p;
			dl = dl_;
	}
	Tablica(int dl_=0,Punkt *w=nullptr) {
		dl = dl_;
		 w = new Punkt[dl_] ;
	}
	bool porownaj(Tablica t_)
	{
		if (dl > t_.dl)return 1;
		else return 0;
	}
	void dodaj(Tablica &t_)
	{
		if (t_.dl == dl)
		{
			
			for (int i = 0; i < dl; i++) {
				w[i].dodaj(t_.w[i]);
			}
		}
		
	}
	~Tablica()
	{
		delete[] w;
	}
	Tablica(Tablica& t_)
	{
		dl = t_.dl;
		w = t_.w;
	}
	Tablica(float* x, float* y, int dl_)
	{
	
		dl = dl_;
		w = new Punkt[dl_];
		for (int i = 0; i < dl_; i++)
		{
			Punkt P(x[i], y[i]);
			w[i] = P;
		}
	}
	int operator==(Tablica& w)
	{
		return porownaj(w);
	}
	friend ostream& operator<<(ostream& wyjscie, const Tablica& t);
	Tablica operator+=(Tablica& T)
	{
		Tablica temp(dl+T.dl);
		w = new Punkt[temp.dl];
		for (int i = 0; i < dl; i++)
		{
			temp.w[i] = w[i];
		}
		for (int i = dl; dl < temp.dl ; i++)
		{
			temp.w[i] = w[i];
		}

	}
	

	
};

ostream& operator<<(ostream& wyjscie, const Tablica& t)
{
	
	

		return wyjscie << "Dlugosc tablicy i 1-y punkt : " << t.dl<<" "<< t.w[0];

	
}
class Wektor:public Punkt
{
protected:
	float dlugosc;
	float kierunek;
public:
	Wektor(float _x=0,float _y=0):Punkt(x,y)
	{
		x = _x;
		y = _y;
		dlugosc = sqrt((x * y) + (x * y));
		kierunek = atan(y / x);
	}
	int operator==(Wektor& w)
	{
		if (dlugosc == w.dlugosc && kierunek == w.kierunek)
			return 3;
		if (dlugosc == w.dlugosc && kierunek != w.kierunek)
			return 2;
		if (dlugosc != w.dlugosc && kierunek == w.kierunek)
			return 1;
		else return 0;
	}
	void dodaj(Wektor w)
	{
		Punkt::dodaj(w);
		dlugosc = sqrt((x * y) + (x * y));
		kierunek = atan(y / x);	
	}
	void drukuj()
	{
		Punkt::drukuj();
		cout << "Dlugosc:" << dlugosc << " Kierunek: " << kierunek << endl<<endl;
	}
	void operator=(Wektor&w)
	{
		if (this != nullptr) {
			x = w.x;
			y = w.y;
			dlugosc = sqrt((x * y) + (x * y));
			kierunek = atan(y / x);
		}
	}

};
class tablicaWektorow :public Wektor
{
public:
	Wektor* vek;
	int rozmiar;

	tablicaWektorow(int rozm):Wektor(dlugosc,kierunek)
	{
		Wektor x(0, 0);
		rozmiar = rozm;
		vek = new Wektor[rozm];
		for (int i = 0; i < rozm; i++)
			vek[i] = x;
	}
	void print()
	{
		cout << " Rozmiar tablicy wektorow:" << rozmiar << endl;
		for (int i = 0; i < rozmiar; i++)
		{

			vek[i].drukuj();
			

		}
	
	}
};
class sortedTabWek :public tablicaWektorow
{

};