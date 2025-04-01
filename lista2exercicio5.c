#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[20];

    printf("Escreva uma palavra: \n");
    scanf("%s", &palavra);
    printf("Palavra: %s", palavra);

    for (int i = 0; i < strlen(palavra); i++)
    {
        printf("\n %c", palavra[i]);
    }
    
    
    return 0;
}
