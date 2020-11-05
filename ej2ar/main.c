#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char END_REGISTRY[2] ={'#'};
char END_FIELD[2] ={','};
char* strconcat(char*,char*);
char* escapear(char*);


int main()
{
    int num, i=0;
    char buffer[100];
    char*string=NULL;
    FILE*file;

    printf("Ingrese la cantidad de personas a ingresar: ");
    scanf("%d", &num);

    for(i=0;i<num;i++){
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,&escapear(buffer));
        string=strconcat(string,&END_FIELD);

        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,&escapear(buffer));
        string=strconcat(string,&END_REGISTRY);

        printf("Resultado: %s", string);
        fflush(stdin);
    }
    fopen("personas.dat", "a");
    fwrite(string,sizeof(char),strlen(string),file);
    fclose(file);

    return 0;
}

char*strconcat(char*string,char*buffer){
    char*concat;
    int i=0;
    int lBuffer=strlen(buffer);
    int lString=strlen(string);

    if(string!=NULL){
        concat=malloc(sizeof(char)*(lString+lBuffer+1));
        for(i=0;i<lString;i++){
            concat[i]=string[i];
        }
        for(i=0;i<lBuffer;i++){
            concat[i+lString]=buffer[i];
        }
        concat[i+lString]='\0';
    }else{
        concat=malloc(sizeof(char)*(lBuffer+1));
        for(i=0;i<lBuffer;i++){
            concat[i]=buffer[i];
        }
        concat[i+lBuffer]='\0';
    }
    return concat;
}

char*escapear(char*texto){
    int cant=0, i=0, j=0;

    for(i=0;texto[i]!='\0';i++){
        if(texto[i]=='END_REGISTRY'||texto[i]=='END_FIELD'){
            cant++;
        }
    }
    char*string=malloc(sizeof(char)*(strlen(texto)+cant+1));
    for(i=0;i<strlen(texto);i++){
        if(texto[i]=='END_REGISTRY'||texto[i]=='END_FIELD'){
            string[j]='\\';
            j++;
        }
        string[j]=texto[i];
        j++;
    }
    string[j]='\0';
    return string;
}
