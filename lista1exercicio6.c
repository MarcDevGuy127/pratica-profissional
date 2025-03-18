#include <stdio.h>


int main()
{
    int valores[10];
    int soma, i;
    for (i = 0; i < 10; i++)
    {
        printf("%i° Número: ", i + 1);
        scanf("%i", &valores[i]);
        soma += valores[i]; //atribuição composta
    }
    printf("A soma dos 10 números é: %i", soma);
    
    return 0;
}