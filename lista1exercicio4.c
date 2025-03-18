#include <stdio.h>

int main()
{
    //aceitando números decimais
    int i = 0;
    float numero, resultado;
    printf("Digite um número:");
    scanf("%f", &numero);
    
    for (
        i = 0; i <= 10; i++)
    {
        resultado = numero * i;
        printf("%.1f * %d = %.1f \n", numero, i, resultado); 
    }
    return 0;
}
