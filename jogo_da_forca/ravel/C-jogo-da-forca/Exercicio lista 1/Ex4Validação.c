#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[21];

    while (1) {

        printf("Digite uma palavra (máximo 20 caracteres): ");
        scanf("%20s", palavra);


        if (strlen(palavra) > 20) {
            printf("Erro: A palavra não pode ter mais de 20 caracteres. Tente novamente.\n");
        } else {
            break;
    }


    printf("Você digitou: %s\n", palavra);

    return 0;
}
