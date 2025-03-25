#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char palavra[20];
    printf("Digite uma palavra: ");
    scanf("%s", palavra); // Remove o operador & e limita para evitar overflow

    for (int i = 0; i < strlen(palavra); i++)
    {
        printf("%c", toupper(palavra[i])); // Usa %c para caracteres individuais
    }
    printf("\n");
    for (int i = 0; i < strlen(palavra); i++)
    {
        printf("%c", tolower(palavra[i])); // Usa %c para caracteres individuais
    }
    printf("\nSTRUCPR: %s\n", strupr(palavra));

    return 0;
}