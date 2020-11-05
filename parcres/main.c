#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char nom[25], dir[30], cat;
    struct nodo*sig;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertarp(nodo**,nodo*);
void mostrar(nodo*);
nodo desapilar(nodo**);
void insertaro(nodo**,nodo*);
void eliminar(nodo**);

int main()
{
    nodo*cab=NULL, *cabT=NULL, *cabD=NULL, *cabC=NULL, *aux, dato;
    int i, num;

    printf("Ingrese la cantidad de peliculas: ");
    scanf("%d", &num);

    for(i=0;i<num;i++){
        aux=newNodo();
        cargar(aux);
        insertarp(&cab,aux);
    }
    printf("\n----Peliculas----\n");
    mostrar(cab);

    while(cab!=NULL){
        dato=desapilar(&cab);
        aux=newNodo();
        *aux=dato;
        aux->sig=NULL;

        if(aux->cat=='T'){
            insertaro(&cabT,aux);
        }else if (aux->cat=='D'){
            insertaro(&cabD,aux);
        }else if (aux->cat=='C'){
            insertaro(&cabC,aux);
        }else
        printf("\nCategoria incorrecta");
    }
    printf("\n----Terror----\n");
    mostrar(cabT);
    printf("\n----Drama----\n");
    mostrar(cabD);
    printf("\n----Comedia----\n");
    mostrar(cabC);

    eliminar(&cabT);
    eliminar(&cabD);
    eliminar(&cabC);
    return 0;
}

nodo*newNodo(){
    nodo*ne;
    ne=(nodo*)malloc(sizeof(nodo));
    if(ne==NULL){
        printf("Memoria insuficiente");
        exit(-1);
    }
    return ne;
}

void cargar(nodo*n){
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(n->nom);

    printf("\nIngrese director: ");
    fflush(stdin);
    gets(n->dir);

    printf("Ingese categoria: ");
    fflush(stdin);
    scanf("%c", &(n->cat));

    n->sig=NULL;
}

void insertarp(nodo**c, nodo*n){
    n->sig=*c;
    *c=n;
}

nodo desapilar(nodo**c){
    nodo d, *aux;
    d=**c;
    aux=*c;
    (*c)=(*c)->sig;
    free(aux);
    return d;
}

void eliminar(nodo**c){
    nodo*aux;
    if(*c==NULL){
        printf("\nLa lista esta vacia");
    }else{
    while(*c!=NULL){
    aux=*c;
    (*c)=(*c)->sig;
    free(aux);
    }}
}

void mostrar(nodo*c){
    if(c==NULL)
        printf("La lista esta vacia");
    while(c!=NULL){
        printf("\n%s, %s, categoria %c", c->nom, c->dir, c->cat);
        c=c->sig;
    }
}

void insertaro(nodo**c,nodo*n){
    nodo*act,*ant;
    if(*c==NULL)
        *c=n;
    else{
        act=*c;
        ant=*c;
        while(act->sig!=NULL&&strcmp(act->nom,n->nom)<0){
            ant=act;
            act=act->sig;
        }
        if(ant==act){
            n->sig=act;
            *c=n;
        }else if (act->sig!=NULL){
            n->sig=act;
            ant->sig=n;
        }else
            ant->sig=n;
    }
}
