#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[50];
   char caractere;
   int contagem;


    printf("Digite uma palavra para ser manipulada: ");
    scanf("%49s", &palavra);


    printf("Qual Caracter quer procurar na palavra? ");
    scanf(" %c", &caractere);

    caractere = toupper((unsigned char)caractere);


      for (int i = 0; palavra[i] != '\0'; i++){
        palavra[i]=toupper((unsigned char)palavra[i]);
        if(palavra[i]== caractere){
            contagem++;
        }

      }

      printf("O caractere %c aparece %d vezes", caractere, contagem);



    return 0;
}
