#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[50];
   char substring[50];


    printf("Digite uma palavra para ser manipulada: ");
    scanf("%49s", palavra);


    printf("Qual substring quer procurar na palavra? ");
    scanf("%49s", substring);

     char *resultado = strstr(palavra, substring);

    if(resultado != NULL){
        printf("A substring %s foi encontrada na palavra.\n", substring);
        printf("A substring comeca na posicao: %1d\n", resultado - palavra);
    }else{
         printf("A substring '%s' não foi encontrada na palavra.\n", substring);
    }

    return 0;
}
