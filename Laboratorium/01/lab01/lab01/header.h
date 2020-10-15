#pragma once
using namespace std;
class Punkt
{
private:
	float x;
	float y;
public:
	void drukuj()
	{
		cout<<"Wspolrzedne punktu:" << x << " x " << y<<endl;
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

};
class Tablica
{
private:
	Punkt* w;
	int dl;
public:
	Tablica(int dl_=0) {
		dl = dl_;
		Punkt w(0, 0);
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
};