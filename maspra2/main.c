#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo* izq;
    struct nodo* der;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertar(nodo**, nodo*);
void enOrden (nodo*);

int main()
{
    nodo* aux, *r=NULL;
    int c, i;

    printf("Ingrese la cantidad de numeros a ingresar: ");
    scanf("%d", &c);

    for(i=0; i<c; i++){
        aux=newNodo();
        cargar(aux);
        insertar(&r, aux);
    }

    enOrden(r);

    return 0;
}

nodo*newNodo(){
    nodo* ne;
    ne=(nodo*)malloc(sizeof(nodo));
    if(ne==NULL){
        printf("Memoria insuficiente");
        exit(-1);
    }
}

void cargar(nodo*n){
    printf("\nIngrese el numero: ");
    scanf("%d", &(n->num));
    n->der=NULL;
    n->izq=NULL;
}

void insertar(nodo**r, nodo*n){
    if(*r==NULL){
        *r=n;
    }else if (n->num < *r->num){
        insertar((*r->izq), n);
    }else if (n->num > *r->num){
        insertar ((*r->der), n);
    }else
    printf("\nNumero duplicado");
}

void enOrden(nodo*r){
    if(r!=NULL){
        enOrden(r->izq);
        printf("%d - ", r->num);
        enOrden(r->der);
    }
}
