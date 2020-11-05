#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    FILE*file;
    char *string=NULL;
    int cant;
    fopen("texto.txt", "r");
    if(file!=NULL){
        fseek(file,0,SEEK_END);
        cant=ftell(file);
        fseek(file,0,SEEK_SET);
        rewind(file);
        string=(char*)malloc(sizeof(char)*(cant+1));
        string[cant]='\0';

        fread(string,sizeof(char),cant,file);
        printf("%s", string);
        fclose(file);
    }else
        printf("No se hallo el archivo");

    return 0;
}
