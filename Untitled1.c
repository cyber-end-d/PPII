#include<stdio.h>
#include<stdlib.h>

typedef struct arbol
{
    struct arbol*izq;
    int dato;
    struct arbol*der;
}nodo;

//planteo los prpototipos de funcion a utilizar
nodo *crearnodo();
void insertar(nodo**,nodo*);
void calcular(nodo*,int*,int*,int);
void eliminarbol(nodo**);

//planteo el main
int main()
{
    int num,prod=1,cont=0;
    nodo *raiz=NULL,*aux;
    printf("Ingrese un numero, -1 para terminar\n");
    scanf("%d",&num);
    while(num != -1)
    {
        aux = crearnodo();
        aux->dato = num;
        aux->izq = NULL;
        aux->der = NULL;
        insertar(&raiz,aux);
        printf("Ingrese numero -1 para terminar\n");
        scanf("%d",&num);
    }
    calcular(raiz,&prod,&cont,raiz->dato);
    printf("La productoria de los elemento del arbol es: %d\n",prod);
    printf("La cantidad de divisores de la raiz es %d\n",(cont-1));
    eliminarbol(&raiz);
    return 0;
}

//declaro el cuerpo de las funciones
nodo *crearnodo()
{
    nodo *pn;
    pn = (nodo*)malloc(sizeof(nodo));
    if (pn == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(-1);
    }
    return pn;
}

void insertar(nodo**r,nodo*n)
{
    if(*r == NULL)
        *r = n;
    else
    {
        if(n->dato < (*r)->dato)
            insertar(&((*r)->izq),n);
        else
            if(n->dato >(*r)->dato)
                insertar(&((*r)->der),n);
        else
            printf("El dato esta duplicado");
    }
    return;
}

void calcular(nodo*r,int*p,int*c,int n)
{

    if(r != NULL)
    {
        if((r->izq != NULL) && (r->der != NULL))
            (*p) *= (r->dato);
        if(n %r->dato == 0)
            (*c)++;
        calcular(r->izq,p,c,n);
        calcular(r->der,p,c,n);
    }
    return;
}

void eliminarbol(nodo**r)
{
    nodo*aux;
    if(*r != NULL)
    {
        eliminarbol(&((*r)->izq));
        eliminarbol(&((*r)->der));
        aux = *r;
        *r = NULL;
        free (aux);
    }
    return;
}
