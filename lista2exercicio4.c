#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[20];

    printf("Digite uma palavra: \n");
    scanf("%s", &palavra);
    //printf("Palavra digitada: %s \n", palavra); //checando palavra salva

    while (strlen(palavra) > 20)
    {
        printf("Digite uma nova palavra: \n");
        scanf("%s", &palavra);
        //printf("Palavra digitada: %s \n", palavra); //checando palavra salva

    }

    return 0;
}
