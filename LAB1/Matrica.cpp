#include "Matrica.h"
#include <iostream>
using namespace std;

Matrica::Matrica() {
    n = 0;
    m = 0;
};

Matrica::Matrica(int dim, int dim1) {
    n = dim;
    m = dim1;
    mat = new Tacka* [n];

    for (int i = 0; i < n; i++)
        mat[i] = new Tacka[m];
};

Matrica::~Matrica() {
    if (mat != 0) {
        for (int i = 0; i < n; i++)
            delete[] mat[i];
        delete[] mat;
        delete[] naziv_matrice;
    }
    mat = 0;
};

Tacka Matrica::Sumiraj_red(int br_reda)
{
    Tacka sum;
    for (int i = 0; i < m; i++)
        sum = sum.saberi(mat[br_reda][i]);
    return sum;
};

Tacka Matrica::Sumiraj_kolonu(int br_kolone)
{
    Tacka sum;
    for (int i = 0; i < n; i++)
        sum = sum.saberi(mat[i][br_kolone]);
    return sum;
};

istream& operator>>(istream& ulaz, Matrica& t1)
{
    for (int i = 0; i < t1.n; i++)
        for (int j = 0; j < t1.m; j++)
            ulaz >> t1.mat[i][j];
    return ulaz;
}

ostream& operator<<(ostream& izlaz, const Matrica& t1)
{
    cout << "Elementi matrice su:" << endl;
    for (int i = 0; i < t1.n; i++)
    {
        for (int j = 0; j < t1.m; j++)
        {
            izlaz << "\t" << t1.mat[i][j];
        }
        izlaz << "\t" << endl;
    }
    return izlaz;
}



/*void Matrica::Mnozi_matrice(Matrica& mat1)
{
    Matrica c(dimenzija_Matrice);

    for (int i = 0; i < dimenzija_Matrice; i++)
    {
        for (int j = 0; j < dimenzija_Matrice; j++)
        {
            c.mat[i][j] = Tacka();
            for (int l = 0; l < dimenzija_Matrice; l++)
                c.mat[i][j] = c.mat[i][j] + mat1.mat[i][l] * mat[l][j];
        }
    }
    
    cout << "Elementi matrice dobijene mnozenjem su:" << endl;
    c.Stampaj_matricu();
}*/

Matrica& Matrica::operator=(const Matrica& obj) {
    if (this != &obj)
    {
        this->n = obj.n;
        if (mat != 0) {
            for (int i = 0; i < n; i++)
                delete[] mat[i];
            delete[] mat;
            delete[] naziv_matrice;
        }
        mat = 0;

        mat = new Tacka* [n];

        for (int i = 0; i < n; i++)
            mat[i] = new Tacka[m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = obj.mat[i][j];
    }
    return *this;
}

void Matrica::povecaj()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j].povecaj();
        }
    }
}

void Matrica::normalizuj(double a, double a1, double b, double b1,
                        double c, double c1)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j].getX() > a1) mat[i][j].setX(a1);
            else if (mat[i][j].getX() < a) mat[i][j].setX(a);

            if (mat[i][j].getY() > b1) mat[i][j].setY(b1);
            else if (mat[i][j].getY() < b) mat[i][j].setY(b);

            if (mat[i][j].getZ() > c1) mat[i][j].setX(c1);
            else if (mat[i][j].getZ() < c) mat[i][j].setX(c);
        }
    }
}

Matrica* Matrica::operator + (const Matrica& obj)
{
    int nMax = n > obj.n ? n : obj.n;
    Matrica* rez = new Matrica(nMax, m + obj.m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rez->mat[i][j] = mat[i][j];

    for (int i = 0; i < obj.n; i++)
    {
        int br = 0;
        for (int j = m; j < m + obj.m; j++)
            rez->mat[i][j] = obj.mat[i][br++];
    }
    return rez;
}