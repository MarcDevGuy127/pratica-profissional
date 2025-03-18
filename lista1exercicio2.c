#include <stdio.h>

int main()
{
    int pNum;
    
    printf("1° Número:", pNum);
    scanf("%i", &pNum);

    if (pNum % 2 == 0)
    {
        printf("Esse número é par!");
    } else
    {
        printf("Esse número é ímpar!");
    }
    
    return 0;
}
