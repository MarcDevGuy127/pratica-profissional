#include <stdio.h>

int main()
{
    int i, valores[10], soma = 0;
    
    for (i = 0; i < 10; i++)
    {
        printf("%i° Número: ", i + 1);
        scanf("%i", &valores[i]);
        soma += valores[i];
    }
    printf("A soma dos 10 números é: %i", soma);
    return 0;
}