#include<stdio.h>
int main()
{
    int v[5]={10,20,30,40,50},*pv,i;
    pv=&v[0];
    //pv=v;
    for(i=0;i<5;i++)
    {
    printf("\n\n%d",v[i]);
    printf("\n%d",*(pv+i));
    //printf("\n%d",pv[i]);
    //printf("\n%d",*(v+i));
    printf("\n%d",pv);
    }

    return 0;
}

