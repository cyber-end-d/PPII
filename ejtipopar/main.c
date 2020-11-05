#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char cat, nom[25], dir[30];
    struct nodo*sig;
}nodo;

nodo*newNodo();
void cargar(nodo*);
void insertarp(nodo**, nodo*); //pila
void instertaru(nodo**, nodo*); //cola
nodo desapilar(nodo**);
void insertaro(nodo**, nodo*);
void mostrar(nodo*);
void eliminar(nodo**);

int main()
{
    nodo*c=NULL, *cT=NULL, *cD=NULL, *cC=NULL, *peli, *peli2, dato;
    int num, i;

    printf("Cuantas peliculas quiere ingresar? ");
    scanf("%d", &num);

    for(i=0;i<num;i++){
        peli=newNodo();
        cargar(peli);
        insertarp(&c, peli);
    }
    printf("\n----Peliculas----");
    mostrar(c);
    while(c!=NULL){
        dato=desapilar(&c);
        peli2=newNodo();
        *peli2=dato;
        peli2->sig=NULL;

        if(peli2->cat=='T'){
            insertaro(&cT, peli2);
        }else if (peli2->cat=='D'){
            insertaro(&cD, peli2);
        }else if (peli2->cat=='C'){
            insertaro(&cC, peli2);
        }
    }
    printf("\n----Peliculas de terror----");
    mostrar(cT);

    printf("\n----Peliculas de drama----");
    mostrar(cD);

    printf("\n----Peliculas de comedia----");
    mostrar(cC);

    return 0;
}

nodo*newNodo(){
    nodo*n;

    n=(nodo*)malloc(sizeof(nodo));
    if(n==NULL){
        printf("\nMemoria insuficiente\n");
        exit(-1);
    }
    return n;
}

void cargar(nodo*n){
    char ct;
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(n->nom);

    printf("\nIngrese director: ");
    fflush(stdin);
    gets(n->dir);


    printf("\nIngrese categoria: ");
    fflush(stdin);
    scanf("%c", &(n->cat));

    n->sig;
}

void insertarp(nodo**c, nodo*n){ //pila
    n->sig=*c;
    *c=n;
}

void insertaru(nodo**c, nodo*n){ //cola
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

void insertaro(nodo**c, nodo*n){
    nodo*act, *ant;
    if(*c==NULL){
        *c=n;
    }else{
        act=*c;
        ant=*c;
        while(act!=NULL&&strcmp(act->nom,n->nom)<0){
            ant=act;
            act=act->sig;
        }//me para en donde tengo que insertar. actual es el siguiente al que quiero insertar
        if(ant==act){ //si esta adelante de todo
           n->sig=*c;
           *c=n;
        }else if (act!=NULL){ //esta en el medio
            n->sig=act;
            ant->sig=n;
        }else { //esta en el final
            ant->sig=n;
        }
    }
}

void mostrar(nodo*c){
    if(c==NULL){
        printf("\nLa lista esta vacia\n");
    }else{
        while(c!=NULL){
            printf("\n%s %s %c\n", c->nom, c->dir, c->cat);
            c=c->sig;
        }
    }
}

nodo desapilar(nodo**c){
    nodo*aux, e;
    e=**c;
    aux=*c;
    (*c)=(*c)->sig;
    free(aux);

    return e;
}

void eliminar(nodo**c){
    nodo*aux;
    if(*c==NULL){
        printf("\nLa lista esta vacia\n");
    }else{
        while(*c!=NULL){
            aux=(*c);
            (*c)=(*c)->sig;
            free(aux);
        }
    }
}
