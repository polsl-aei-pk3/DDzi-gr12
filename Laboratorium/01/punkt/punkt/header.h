#include <iostream>class Punkt{
	float x;	float y;	Punkt(float x_, float y_)	{		x = x_;		y = y_;	}	void dodaj(Punkt& p)	{		x += p.x;		y += p.y;	}	void drukuj()	{		cout << "x: " << x << " y:" << y;	}};