#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[50];
   char antigo, novo;


    printf("Digite uma palavra para ser manipulada: ");
    scanf("%49s", palavra);

    printf("Digite o caractere a ser substituido: ");
    scanf(" %c", &antigo);

    printf("Digite o caractere um novo caractere no lugar: ");
    scanf(" %c", &novo);

    for(int i = 0; i < strlen(palavra); i++){//aqui vai testar ate o tamanho da palavra

        if(palavra[i]== antigo){
            palavra[i] = novo;
        }
    }

    printf("Palavra modificada %s\n", palavra);



    return 0;
}
