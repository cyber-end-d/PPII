#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char*nombre;
    char*apellido;
}persona;

char*llave(persona*);

int main(){
    char*res;
    persona*p;

    p.nombre="Mariana";
    p.apellido="Donas";

    llave(&p);

    printf("%s", res);

    return 0;
}

char*llave(persona*p){
    char*nombre=(p->nombre);
    char*apellido=(p->apellido);
    char*esp=" ";
    int lon;
    int i=0;

    lon=malloc(sizeof(char)*(strlen(nombre)+strlen(apellido)+strlen(esp)));
    res=(char*)malloc(lon);

    strcat(res, apellido);
    strcat(res, esp);
    strcat(res, nombres);

    return res;
}
