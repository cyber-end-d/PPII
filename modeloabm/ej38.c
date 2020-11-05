#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
typedef struct
{
    char nombre[30];
    int sector;
} emple;
void cargar(FILE *,emple *);
void ordenar(emple *,int);
void mostrar(emple *,int);
void mostrar2(emple *,int);
void ordenar2(emple *,int);
int main()
{
    FILE * arch;
    emple *p,reg;
    int sec,cantreg;
    arch = fopen(&quot;EMPLADO.DAT&quot;,&quot;ab+&quot;);
    if(arch==NULL)
    {
        printf(&quot;No se pudo abrir el archivo\n&quot;);
        exit(1);
    }
    fclose(arch);
    arch = fopen(&quot;EMPLADO.DAT&quot;,&quot;rb+&quot;);
    if(arch==NULL)
    {
        printf(&quot;No se pudo abrir el archivo\n&quot;);
        exit(1);
    }
    do
    {
        printf(&quot;Ingrese un numero de sector: &quot;);
        scanf(&quot;%d&quot;,&amp;sec);
        if(sec&lt;0||sec&gt;5)
        {
            printf(&quot;Sector incorrecto\n&quot;);
        }
    }
    while(sec&lt;0||sec&gt;5);
    while(sec!=0)
    {
        reg.sector=sec;
        printf(&quot;Ingrese el nombre del empleado: &quot;);
        fflush(stdin);
        gets(reg.nombre);
        fwrite(&amp;reg,sizeof(emple),1,arch);


do
        {
            printf(&quot;Ingrese un numero de sector: &quot;);
            scanf(&quot;%d&quot;,&amp;sec);
            if(sec&lt;0||sec&gt;5)
            {
                printf(&quot;Sector incorrecto\n&quot;);
            }
        }
        while(sec&lt;0||sec&gt;5);
    }
    clearerr(arch);
    fseek(arch,0,SEEK_END);
    cantreg=ftell(arch)/sizeof(emple);
    p=(emple *)malloc(cantreg*sizeof(emple));
    if(p==NULL)
    {
        printf(&quot;Insuficiente memoria\n&quot;);
        exit(-1);
    }
    cargar(arch,p);
    ordenar(p,cantreg);
    mostrar(p,cantreg);
    printf(&quot;\nEmpleados agrupados por sector\n&quot;);
    mostrar2(p,cantreg);
    ordenar2(p,cantreg);
    printf(&quot;\nEmpleados agrupados por sector con nombres ordenados alfabéticamente\n&quot;);
    mostrar2(p,cantreg);
    close(arch);
    free(p);
    return 0;
}

void cargar(FILE *arch,emple *p)
{
    int i=0;
    emple reg;
    clearerr(arch);
    fseek(arch,0,SEEK_SET);
    fread(&amp;reg,sizeof(emple),1,arch);
    while(!feof(arch))
    {
        *(p+i)=reg;
        i++;
        fread(&amp;reg,sizeof(emple),1,arch);
    }
}
void ordenar(emple *p,int tam)
{
    int c,pas;
    emple aux;
    for(pas=1; pas&lt;tam; pas++)
    {
        for(c=0; c&lt;tam-pas; c++)
        {
            if((p+c)-&gt;sector&lt;(p+c+1)-&gt;sector)
            {
                aux=*(p+c);
                *(p+c)=*(p+c+1);
                *(p+c+1)=aux;
            }
        }
    }
}

void mostrar(emple *p,int tam)
{
    int i;
    for(i=0; i&lt;tam; i++)
    {
        printf(&quot;Sector : %d Nombre: %s\n&quot;, (p+i)-&gt;sector,(p+i)-&gt;nombre);
    }
}

void ordenar2(emple *p,int tam)
{
    int c,pas;
    emple aux;
    for(pas=1; pas&lt;tam; pas++)
    {
        for(c=0; c&lt;tam-pas; c++)
        {
            if((p+c)-&gt;sector&lt;(p+c+1)-&gt;sector)
            {
                aux=*(p+c);
                *(p+c)=*(p+c+1);
                *(p+c+1)=aux;
            }
            else
            {
                if((p+c)-&gt;sector==(p+c+1)-&gt;sector)
                {
                    if(strcmp((p+c)-&gt;nombre,(p+c+1)-&gt;nombre)&gt;0)
                    {
                        aux=*(p+c);
                        *(p+c)=*(p+c+1);
                        *(p+c+1)=aux;
                    }
                }
            }
        }
    }
}

void mostrar2(emple *p,int tam)
{
    int i,sector;
    for(i=0; i&lt;tam; i++)
    {
        sector=(p+i)-&gt;sector;
        printf(&quot;Sector %d\n&quot;,sector);
        while(i&lt;tam&amp;&amp;(p+i)-&gt;sector==sector)
        {
            printf(&quot;Nombre: %s\n&quot;,(p+i)-&gt;nombre);
            i++;
        }
        i--;
    }
}
