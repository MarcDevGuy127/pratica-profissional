#include <stdio.h>

int main()
{
    int numeros1[5], numeros2[5], numerosSoma[5], i;
    
    for (i = 0; i < 5; i++)
    {
        printf("%i° Número1: ", i + 1);
        scanf("%i", &numeros1[i]);

        printf("%i° Número2: ", i + 1);
        scanf("%i", &numeros2[i]);

        numerosSoma[i] = numeros1[i] + numeros2[i];
    }

    for (i = 0; i < 5; i++)
    {
        printf("Soma: %d \n", numerosSoma[i]);        
    }

    return 0;
}
