#include <stdio.h>

int main()
{
    int numeros[5],i;
    float media;
    
    for (i = 0; i < 5; i++)
    {
        printf("%i° Número: ", i + 1);
        scanf("%i", &numeros[i]);
        media += numeros[i];
    }
    media += numeros[i]/i;
    printf("Média: %.2f", media);
    return 0;
}
