#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *arch;
    int cuenta;
    char nombre[30];
    float saldo;
    arch=fopen("datos.txt","w");
    if(!arch) //o if(arch==NULL)
    {
        printf("Error de apertura\n");
        exit(-1);
    }
    printf("Ingrese un numero de cuenta 0 para terminar: ");
    scanf("%d",&cuenta);
    while(cuenta!=0)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese el saldo: ");
        scanf("%f",&saldo);
        fprintf(arch,"%d %s %.2f\n",cuenta,nombre,saldo);
        printf("Ingrese otro numero de cuenta 0 para terminar: ");
        scanf("%d",&cuenta);
    }
    fclose(arch);
    return 0;
}


