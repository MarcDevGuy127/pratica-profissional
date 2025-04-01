#include <stdio.h>
#include <string.h>

int main()
{
    char localizar, substituir;
    char palavra[20];

    printf("Digite uma palavra: ");
    scanf("%19s", &palavra);

    printf("Digite qual letra para localizar: ");
    scanf(" %c", &localizar);

    printf("Digite o que por para substituir: ");
    scanf(" %c", &substituir);

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == localizar)
        {
            palavra[i] = substituir;
        }
    }
    
    // Exibindo resultado
    printf("Palavra alterada: %s\n", palavra);
    
    return 0;
}