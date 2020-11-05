#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void eliminar(nodo**c, char da){
    nodo*aux,*act;
    act=*c;
    ant=*c;

    if(*c==NULL){
        printf("La lista esta vacia");
    }else{
        while(act->sig!=NULL&&strcmp(act->nom, da)!=0){
            ant=act;
            act=act->sig;
        }
        if(ant==act){
            aux=*c;
            *c=*c->sig;
            free(aux);
        }else if (act->sig!=NULL){
            aux=act;
            act=act->sig;
            free(aux):
        }else
        printf("No se encontro el dato");
    }

}

void insertarp(nodo**c, nodo*n){
    *c=*c->sig;
    *c=n;
}

void insertaru(nodo**c, nodo*n){
    nodo*aux;
    if(*c==NULL){
        *c=n;
    }else{
        aux=*c;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=n;
        n->sig=NULL;
    }
}

void insertaro(nodo**c, nodo*n){
    nodo*act,*ant;
    if(*c==NULL){
        *c=n;
    }else{
        act=*c;
        ant=*c;
        while(act->sig!=NULL&&strcmp(act->nom,n->nom)<0){
            ant=act;
            act=act->sig;
        }
        if(ant==act){
            n->sig=*c;
            *c=n;
        }else if (act->sig!NULL){
            n->sig=act;
            ant->sig=n;
        }else
            ant->sig=n;
    }
}
