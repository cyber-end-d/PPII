#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo*der;
    struct nodo*izq;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertar(nodo**,nodo*);
void preOrden(nodo*);
void sumatoria(nodo*);
void multiplo(nodo*);
void eliminar(nodo**);

void sumatoria(nodo*){

}
