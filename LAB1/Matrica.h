#pragma once
#include "Tacka.h"
class Matrica
{
public:
    Matrica();
    ~Matrica();
    Matrica(int dim, int dim1);
    Tacka Sumiraj_red(int br_reda);
    Tacka Sumiraj_kolonu(int br_kolone);
   // void Unesi_matricu();
   // void Stampaj_matricu();
    Matrica& operator = (const Matrica& obj);
    Matrica* operator + (const Matrica& obj);
    void povecaj();
    void normalizuj(double a, double a1, double b, double b1,
                    double c, double c1);
    Tacka vratiTacku(int x, int y)
    {
        return mat[x][y];
    }
    friend istream& operator>>(istream& ulaz, Matrica& t1);
    friend ostream& operator<<(ostream& izlaz, const Matrica& t1);
private:
    Tacka** mat;
    int n;
    int m;
    char* naziv_matrice;
};
