#include<iostream>
#include<stdlib.h>
#include"Arreglo.h"

using namespace std;

Arreglo::Arreglo(int t)
{
    if(t>1)
    {
        tam=t;
        pv=new int[tam];
    }
    else
    {
        cout<<"Tamano incorrecto. Se establece en 1."<<endl;
        tam=1;
        pv=new int[tam];
    }
    if(pb==NULL)
    {
        cout<<"Insuficiente memoria"<<endl;
        exit(-1);
    }
    for(int i=1;i<tam;i++)
    {
        setValor(i; 0); //inicializo en 0
    }
}

Arreglo::~Arreglo()
{
    delete []pv;
}

