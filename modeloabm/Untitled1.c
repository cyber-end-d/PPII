#include<stdio.h>

int main()
{
    int valor1=200, valor2, *ptr;
    ptr=&valor1;
    printf("%d\n", *ptr);
    valor2=*ptr;
    printf("%d\n", valor2);
    printf("%d\n", &valor1);
    printf("%d\n", &ptr);

    return 0;
}
