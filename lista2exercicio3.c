#include <stdio.h>
#include <string.h>

int main()
{
    char substring[10], palavra[20];

    printf("Digite uma palavra: ");
    scanf("%19s", &palavra);

    printf("Digite uma parte da palavra: ");
    scanf("%9s", &substring);
    
    printf("Palavra digitada: %s \n", palavra);
    printf("Substring digitada: %s \n", substring);

    int tamanhoPalavra = strlen(palavra);
    int tamanhoSub = strlen(substring);

    for (int i = 0; i <= tamanhoPalavra - tamanhoSub; i++) {
        if (strncmp(&palavra[i], substring, tamanhoSub) == 0) {
            printf("Substring encontrada na posição: %d\n", i);
        }
    }
    return 0;
}