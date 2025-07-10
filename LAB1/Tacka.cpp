#include "Tacka.h"
#include <iostream>
using namespace std;

Tacka::Tacka()
{
	x = 0;
	y = 0;
	z = 0;
}

Tacka::Tacka(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
istream& operator>>(istream& ulaz, Tacka& t1)
{
	ulaz >> t1.x >> t1.y >> t1.z;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, const Tacka& t1)
{
	izlaz << t1.x << "," << t1.y << "," << t1.z;
	return izlaz;
}

Tacka Tacka::saberi(Tacka& t1)
{
	Tacka t2(x+t1.x, y+t1.y, z+t1.z);
	return t2;
}

Tacka Tacka::oduzmi(Tacka& t1)
{
	Tacka t2(x - t1.x, y - t1.y, z - t1.z);
	return t2;
}