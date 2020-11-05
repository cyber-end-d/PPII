#include<stdio.h>

typedef struct fecha
{
    int dia;
    int mes;
    int ao;
}fecha;

typedef struct alumno
{
    char nombre[30];
    char apellido[30];
    fecha ingreso;
    int aprobadas;
    float promedio;
}alumno;

int main()
{
   alumno aux;
   fecha ing;
   printf("\nIngrese nombre ");
   scanf("%s", &(aux.nombre));
   printf("%s", aux.nombre);
   printf("\nIngrese apellido ");
   scanf("%s", &(aux.apellido));
   printf("%s", aux.apellido);
   printf("\nIngrese fecha ingreso (dma) ");
   scanf("%s", &(ing.dia));
   scanf("%s", &(ing.mes));
   scanf("%s", &(ing.ao));
   aux.ingreso=ing;
   printf("%d", aux.ingreso);

   return 0;
}
