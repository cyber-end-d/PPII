#include<stdio.h>
#include<stdlib.h>

typedef struct fecha
{
    int dia;
    int mes;
    int ao;
}fecha;

typedef struct ficha
{
    int codigo;
    char autor[70];
    char titulo[70];
    int edicion;
    fecha fe;
}ficha;

void cargar(ficha*);

int main()
{
   // ficha *aux;
   // cargar(aux);
   int *a[3]={1, 2, 3, 8};
   int b[2]={4, 6, 7};
   int *ptr;

   ptr=&a[0];
   printf("%d p %d", a[0], *ptr);
   ptr++;
   ptr++;
   printf("\n%d p %d", a[0], *ptr);

   //a[0]++;
   //printf("%d", a[0]);
   //b[0]++;
   //printf("\n%d", b[0]);

    return 0;
}

/*void cargar(ficha*a)
{
    fecha fe;
    printf("\nIngrese codigo ");
    scanf("%d", &(a->codigo));
    printf("\n%d", a->codigo);

    printf("\nIngrese autor ");
    scanf("%s", &(a->autor));
    printf("\n%s", a->autor);

    printf("\nIngrese titulo ");
    scanf("%s", &(a->titulo));
    printf("\n%s", a->titulo);

    printf("\nIngrese fecha d-m-a");
    scanf("%d", &(a->(fe->dia)));
    scanf("%d", &(a->(fe->mes)));
    scanf("%d", &(a->(fe->ao)));
    printf("\n%d/%d/%d", aux->fe->dia, aux->fe->mes, aux->fe->ao);
}*/
