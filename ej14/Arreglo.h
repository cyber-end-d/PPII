#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED
#include<iostream>

using namespace std;

class Arreglo
{
    friend ostream& operator<<(ostream&, Arreglo);
    friend istream& operator>>(istream&, Arreglo&);

    public:
        Arreglo(t=1);
        ~Arreglo();
        int getValor(int)const;
        void setValor(int, int);
        void insertarDer(int, int);
        void insertarIzq(int, int);
        void eliminar(int, int);
        void insertarFin(int);
        int getTamano()const;

    private:
        int tam;
        int *pv;
};


#endif // ARREGLO_H_INCLUDED
