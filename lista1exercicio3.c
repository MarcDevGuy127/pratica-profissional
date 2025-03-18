#include <stdio.h>

int main()
{
    int numero;

    printf("Número:", &numero);
    scanf("%i", &numero);

    if (numero > 0)
    {
        printf("Esse número é positivo!");
    } else if (numero < 0)
    {
        printf("Esse número é negativo!");
    } else if (numero == 0)
    {
        printf("Esse número é zero!");
    }
    
    
    
    return 0;
}
