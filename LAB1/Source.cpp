#include <iostream>
#include "Matrica.h"
#include <fstream>
using namespace std;

int main()
{
	int n, m, n1, m1;
	ifstream uldat("C:\\Users\\VS\\Desktop\\LAB_OOP\\lab1.txt");
	if (uldat.good())
	{
		uldat >> n >> m >> n1 >> m1;
	}
	Matrica mat1(n, m);
	Matrica mat2(n1, m1);

	if (uldat.good())
	{
		uldat >> mat1 >> mat2;
		uldat.close();
	}
	cout << mat1;
	cout << mat2;

	Matrica* mat3;
	mat3 = mat1 + mat2;
	cout << *mat3;

	cout << mat1;


	ofstream izldat("C:\\Users\\VS\\Desktop\\LAB_OOP\\lab1_izlaz.txt");

	if (izldat.good())
	{
		izldat << mat1.Sumiraj_red(1) << endl;
		izldat << mat1.Sumiraj_kolonu(1) << endl;
		izldat.close();
	}
	//mat1.povecaj();
	//mat1.Stampaj_matricu();



	/*Matrica mat2(3, 3);

	mat1.Unesi_matricu();
	mat2.Unesi_matricu();

	cout << "Sum kolone 1 je:" << mat1.Sumiraj_kolonu(1) << endl;
	cout << "Sum kolone 3 je:" << mat1.Sumiraj_kolonu(2) << endl;
	cout << "Sum reda 2 je:" << mat1.Sumiraj_red(1) << endl;
	cout << "Sum reda 3 je:" << mat1.Sumiraj_red(3) << endl;

	mat1.Stampaj_matricu();
	mat2.Stampaj_matricu();

	//mat1.Mnozi_matrice(mat2);

	mat1 = mat2;
	*/
	return 0;
}
