#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ej 26

typedef struct nodo{
    char nom[50];
    float t;
    struct nodo*sig;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertaru(nodo**, nodo*);
nodo eliminarp(nodo**);
void mostrar(nodo*);

int main()
{
    nodo* cab=NULL, *aux, *atend;
    float tot=0, i;

    for(i=0; i<50; i++){
        aux=newNodo();
        cargar(aux);
        insertaru(&cab, aux);
    }
    printf("Cola: \n");
    mostrar(cab);

    do{
        atend=newNodo();
        atend=eliminarp(&cab);
        tot+=atend->t;
    }while(tot<90);

    printf("\nPersonas restantes: ");
    mostrar(cab);

    return 0;
}

nodo*newNodo(){
    nodo*ne;
    ne=(nodo*)malloc(sizeof(nodo));
    if(ne==NULL){
        printf("Memoria insuficiente");
        exit(-1);
    }
}

void cargar(nodo*n){
    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(n->nom);

    printf("\nIngrese el tiempo en el que sera atendido: ");
    scanf("%f", &(n->t));
}

void insertaru(nodo**c, nodo*n){
    nodo*aux;
    if(*c==NULL){
        *c=n;
    }else {
        aux=*c;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=n;
    }
}

void mostrar(nodo*c){
    if(c==NULL){
        printf("La lista esta vacia");
    }else {
        while(c!=NULL){
        printf("\n%s, tiempo %.2f", c->nom, c->t);
        c=c->sig;
        }
    }
}

nodo eliminarp(nodo**c){
    nodo*aux, dat;
    dat=**c;
    aux=*c;
    *c=*c->sig;
    free(aux);
    return dat;
}
