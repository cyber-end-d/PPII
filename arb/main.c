#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo*izq;
    struct nodo*der;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertar(nodo**,nodo*);
void enOrden(nodo*);

int main(){
    nodo*r=NULL, *num;
    int d, i;
    printf("Cuantos numeros desea ingresar? ");
    scanf("%d", &d);

    for(i=0;i<d;i++){
        num=newNodo();
        cargar(num);
        insertar(&r, num);
    }
    enOrden(r);

    return 0;
}

nodo*newNodo(){
    nodo*n;
    n=(nodo*)malloc(sizeof(nodo));
    if (n==NULL){
        printf("Memoria insuficiente");
    }
    return n;
}

void cargar(nodo*n){
    printf("Ingrese numero: ");
    scanf("%d", &(n->num));
    n->der=NULL;
    n->izq=NULL;
}

void insertar(nodo**r,nodo*n){
    if(*r==NULL){
        *r=n;
    }else if ((n->num)<(*r->num)){
        insertar(&(r->izq),n);
    }else if ((n->num)>(*r->num)){
        insertar(&(r->der),n);
    }else
    printf("Numero duplicado");
}

void enOrden(nodo*r){
    if(r!=NULL){
    enOrden(r->izq);
    printf("%d - ", r->num);
    enOrden(r->der);
    }
}
