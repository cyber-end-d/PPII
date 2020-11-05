#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    FILE *arch;
    int cuenta;
    char nombre[30];
    float saldo;
    arch=fopen("datos.txt","r");
    if(!arch)
    {
        printf("Error de apertura\n");
        exit(1);
    }
    printf("%-16s%-20s%-16s\n","Nro de cuenta","Nombre","Saldo"); //<num>s es un ancho de impresion. (-) es alineado a la izquierda. Si sobra espacio queda en blanco.
    fscanf(arch,"%d %s %f",&cuenta,nombre,&saldo); //nombre no tiene & por ser string.
    while(!feof(arch)) //busca marca de fin de archivo(feof=end of file),queda como una tabla para eso esta alineado
    {
        printf("%-16d%-20s%-16.2f\n",cuenta,nombre,saldo);
        fscanf(arch,"%d %s %f",&cuenta,nombre,&saldo); //para que itere mientras no sea fin de archivo
    }
    fclose(arch);
   getch(); //detiene la pantalla y espera que apriete una tecla para cerrar. No hace falta en CodeBlocks porque deja la ventana con los resultados abierta
    return 0;
}


