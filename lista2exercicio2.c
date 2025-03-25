#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int numLetras, aparicoes = 0;
    char letra, palavra[20];
    printf("Digite uma palavra: ");
    scanf("%s", &palavra);
    printf("Escolha uma letra: ");
    scanf(" %c", &letra);

    printf("Palavra: %s \n", palavra);
    printf("Letra: %c \n", letra);
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (letra == palavra[i])
        {
            aparicoes++;
        }
    }
    printf("Na palavra %s a letra %c aparece %i vezes.",  palavra, letra, aparicoes);
    
    return 0;
}
