#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[50];


    printf("Digite uma palavra para ser manipulada: ");
    scanf("%49s", palavra);

    for(int i = 0; i < strlen(palavra); i++){//aqui vai testar ate o tamanho da palavra
        printf("Letra pos %d  %c\n", i, palavra[i]);
    }



    return 0;
}
