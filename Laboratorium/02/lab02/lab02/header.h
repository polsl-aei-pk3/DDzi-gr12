#pragma once
#include <iostream>
using namespace std;
class Punkt
{
private:
	float x;
	float y;

public:
	Punkt() {};
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
		x = p.x;
		y = p.y;

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
	Tablica() {};
	Tablica(int dl_ = 0) {
		dl = dl_;
		*w = new Punkt(0, 0)[dl_];
	}
	bool porownaj(Tablica t_)
	{
		if (dl > t_.dl)return 1;
		else return 0;
	}
	void dodaj(Tablica& t_)
	{
		dl += t_.dl;
	}
	~Tablica()
	{
		delete w;
	}
	Tablica(Tablica& t_)
	{
		dl = t_.dl;
		w = t_.w;
	}
	Tablica(float* x, float* y, int dl_)
	{
		Punkt w(*x, *y);
		dl = dl_;
	}
	Tablica(float *x, float *y, int dl_)
	{
		//*w = new Punkt(0, 0)[dl_];
		w = Punkt(x[0], y[0]);
	}
	int operator==(Tablica& w)
	{
		return porownaj(w);
	}
	friend ostream& operator<<(ostream& wyjscie, const Tablica& t);
	Tablica operator+=(Tablica& T)
	{
		this->dl = T.dl;
		this->w += T.w;
		return (*this);
	}
	

	
};

ostream& operator<<(ostream& wyjscie, const Tablica&t)
{
	return
		wyjscie << "Dlugosc tablicy: " << t.dl << ", wspolrzedna x: "; cout << t.w;

}
