#pragma once
#include <iostream>
using namespace std;
class Tacka
{
	double x;
	double y;
	double z;
public:
	Tacka();
	Tacka(double x, double y, double z);
	friend istream& operator>>(istream& ulaz, Tacka& t1);
	friend ostream& operator<<(ostream& izlaz,const Tacka& t1);
	Tacka saberi(Tacka& t1);
	Tacka oduzmi(Tacka& t2);
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	void setX(double a) { x = a; }
	void setY(double a) { y = a; }
	void setZ(double a) { z = a; }
	void povecaj() {
		x++;
		y++;
		z++;
	}
};

