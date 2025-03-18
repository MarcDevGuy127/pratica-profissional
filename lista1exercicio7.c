#include <stdio.h>

int main()
{
    int numeros[5],i;
    
    for (i = 0; i < 5; i++)
    {
        printf("%i° Número: ", i + 1);
        scanf("%i", &numeros[i]);
    }
    
    for (i = 5 - 1; i >= 0; i--)
    {
        printf("%i° Número: %i \n", i + 1 , numeros[i]);
    }
    
    return 0;
}
