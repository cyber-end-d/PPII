#include <stdio.h>
#include <stdlib.h>
#define B 5

typedef struct nodo
{
    struct nodo*sig;
    char string[100];
}nodo;

int hash(char[]);
void dispAb(nodo*[],int,char);

int main()
{
    nodo*hash[B];
    int clase;
    char string[100];

    printf("Ingrese el texto: ");
    fflush(stdin);
    gets(string);

    clase=hash(string);
    dispAb(hash,clase,string);

    return 0;
}

int hash(char s[100])
{
    int i=0, res;

    for(i=0;s[i]!='\0';i++)
    {
        res+=(int)string[i];
    }
    return res%B;
}

void dispAb(char*hash[B],int c,char s[100])
{
    nodo*aux=NULL;

    aux=hash[clase];
    if(aux==NULL)
    {
        hash[clase]=newNodo(string);
    }
    else
    {
        for(;aux->sig!=NULL;aux=(aux->sig))
        {
            aux->sig=newNodo(s);
        }
    }

}
