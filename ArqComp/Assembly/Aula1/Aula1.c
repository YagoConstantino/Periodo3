#include <stdio.h>

int main()
{
    register int num1 = 30;
    register int num2 = 50;
    int soma = num1 + num2;
    register int num3 = 99;

    int sub = soma - num3;

    printf("%d \n",sub);
    return 0;
}