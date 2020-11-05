#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct producto
{
    int codigo,stock,borrado; ///1= marcado para ser borrado, 0=no marcado
};
void altas(FILE *);
void bajas(FILE *);
void modificacion(FILE *);
void compactar(FILE **);///en un primer momento no se borra físicamente, se marca para ser borrado y despues cuando se elige borrar los marcados es cuando se borra físicamente
void listado(FILE *);
void buscar(FILE **,int);
int menu();
int main()
{
    FILE *arch;
    int op;
    arch=fopen("PRODUCTOS.DAT","ab+"); ///lectura y grabacion binaria, en mejor abrirlo como append aca que w o r
    if(arch==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(-1);
    }
    fclose(arch);
    arch=fopen("PRODUCTOS.DAT","rb+");
    if(arch==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(-1);
    }
    op=menu();
    while(op!=6)
    {
        switch(op)
        {
            case 1: altas(arch);
                    break;
            case 2: bajas(arch);
                    break;
            case 3: modificacion(arch);
                    break;
            case 4: compactar(&arch);
                    break;
            case 5: listado(arch);
        }
        getch();
        op=menu();
    }
    fclose(arch);
    return 0;
}

void altas(FILE * pa)
{
   int cod;
   struct producto reg;
   clearerr(pa);
   fseek(pa,0,SEEK_SET);
   printf("Ingrese el codigo de producto 0 para terminar: ");
   scanf("%d",&cod);
   while(cod!=0)
   {
       buscar(&(pa),cod);
       if(!feof(pa)) ///lo encontro
            printf("Alta existente\n");
       else/// esta en end of file Osea no lo encontro
       {
            clearerr(pa);
            reg.codigo=cod;
            reg.borrado=0;
            printf("Ingrese el stock: ");
            scanf("%d",&reg.stock);
            fseek(pa,0,SEEK_END); ///me ubico al final del archivo(0 desplazamiento)
            fwrite(&reg,sizeof(struct producto),1,pa); ///graba una estructura que grabe en reg
       }
       printf("Ingrese otro c�digo 0 para terminar: ");
       scanf("%d",&cod);
   }
}

void bajas(FILE *pa)
{
   int cod;
   struct producto reg;
   clearerr(pa);
   fseek(pa,0,SEEK_SET);
   printf("Ingrese el codigo de producto que quiere eliminar: ");
   scanf("%d",&cod);
   while(cod!=0)
   {
       buscar(&(pa),cod);
       if(!feof(pa))
       {
           fseek(pa,ftell(pa)-sizeof(struct producto),SEEK_SET);
           fread(&reg,sizeof(struct producto),1,pa);
           reg.borrado=1; ///lo marca para borrar
           fseek(pa,ftell(pa)-sizeof(struct producto),SEEK_SET);
           fwrite(&reg,sizeof(struct producto),1,pa);
       }
       else
       {
           printf("Baja inexistente\n");
       }
       printf("Ingrese otro c�digo de producto 0 para terminar: ");
       scanf("%d",&cod);
   }
}

void modificacion(FILE *pa)
{
   int cod,stock;
   struct producto reg;
   clearerr(pa);
   fseek(pa,0,SEEK_SET);
   printf("Ingrese el c�digo de producto que quiere modificar: ");
   scanf("%d",&cod);
   while(cod!=0)
   {
       buscar(&(pa),cod);
       if(!feof(pa))
       {
           fseek(pa,ftell(pa)-sizeof(struct producto),SEEK_SET);
           fread(&reg,sizeof(struct producto),1,pa);
           printf("Ingrese el nuevo stock: ");
           scanf("%d",&stock);
           reg.stock=stock;
           fseek(pa,ftell(pa)-sizeof(struct producto),SEEK_SET);
           fwrite(&reg,sizeof(struct producto),1,pa);
       }
       else
       {
           printf("Modificaci�n inexistente\n");
       }
       printf("Ingrese otro c�digo de producto 0 para terminar: ");
       scanf("%d",&cod);
   }
}
void compactar(FILE **pa)
{
   struct producto reg;
   FILE *ftemp;
   ftemp=fopen("PRODUCTOS.TMP","wb");
   if(ftemp==NULL)
   {
       printf("No se pudo abrir el archivo\n");
       exit(-1);
   }
   clearerr(*pa);
   fseek(*pa,0,SEEK_SET);
   fread(&reg,sizeof(struct producto),1,*pa);
   while(!feof(*pa))
   {
      if(reg.borrado==0)
         fwrite(&reg,sizeof(struct producto),1,ftemp);
         fread(&reg,sizeof(struct producto),1,*pa);
   }
   fclose(ftemp);
   fclose(*pa);
   remove("PRODUCTOS.DAT");
   rename("PRODUCTOS.TMP","PRODUCTOS.DAT");
   *pa=fopen("PRODUCTOS.DAT","rb+");
   if(*pa==NULL)
   {
       printf("No se pudo abrir el archivo\n");
       exit(-1);
   }
}

void listado(FILE * pa)
{
  struct producto reg;
  clearerr(pa);
  fseek(pa,0,SEEK_SET);
  fread(&reg,sizeof(struct producto),1,pa);
  while(!feof(pa))
  {
      printf("C�digo: %d Stock: %d Borrado: %d\n",reg.codigo,reg.stock,reg.borrado);
      fread(&reg,sizeof(struct producto),1,pa);
  }
}

int menu()
{
    int op;
    system("cls");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificaci�n\n");
    printf("4- Compactar\n");
    printf("5- Listado\n");
    printf("6- Salir\n");
    printf("\nIngrese una opci�n: ");
    do
    {
        scanf("%d",&op);
        if(op<1||op>6)
        {
            printf("Opci�n incorrecta. Intente de nuevo.\n");
        }
    }while(op<1||op>6);
    return op;
}

void buscar(FILE **pa,int c)
{
  struct producto reg;
  clearerr(*pa);
  fseek(*pa,0,SEEK_SET);
  fread(&reg,sizeof(struct producto),1,*pa);
  while(!feof(*pa)&&reg.codigo!=c) ///lee mientras no sea end of file o no es el código que busco
  {
      fread(&reg,sizeof(struct producto),1,*pa);
  }
}
