#include <stdio.h>

int main()
{
    int numero[10], maior, menor, i;

    for (i = 0; i < 10; i++)
    {
        printf("%i° Número: ", i + 1);
        scanf("%i", &numero[i]);
    }

    maior = numero[0];
    menor = numero[0];

    for (i = 1; i < 10; i++)
    {
        if (numero[i] > maior)
        {
            maior = numero[i];
        }
        if (numero[i] < menor)
        {
            menor = numero[i];
        }
    }

    printf("Maior número: %i\n", maior);
    printf("Menor número: %i\n", menor);

    return 0;
}