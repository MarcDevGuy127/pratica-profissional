#include <stdio.h>

int main()
{
    float notaA, notaB, media;
    
    printf("1° Nota:");
    scanf("%f", &notaA);
    printf("2° Nota:");
    scanf("%f", &notaB);

    media = (notaA + notaB)/2;
    printf("Média: %.2f \n", media);
    return 0;
}
