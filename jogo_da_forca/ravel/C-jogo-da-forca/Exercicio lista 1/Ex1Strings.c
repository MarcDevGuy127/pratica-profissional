#include <stdio.h>
#include <stdlib.h>

int main()
{
   char palavra[50], palavraMinus[50];


    printf("Digite uma palavra para ser manipulada: ");
    scanf("%49s", &palavra);// Lê a entrada do usuário (limita a 49 caracteres)



      for (int i = 0; palavra[i] != '\0'; i++){//O laço percorre a string até encontrar o caractere nulo ('\0'), aplicando toupper() em cada caractere.
        palavra[i]=toupper((unsigned char)palavra[i]);
        palavraMinus[i]=tolower((unsigned char)palavra[i]);
      }


     //strupr(palavra); muda todas para maiuscula
     //strlwr(palavraMinus); muda todas para minuscula

     printf("Palavra em maiusculas: %s\n", palavra);
     printf("Palavra em minusculo: %s\n", palavraMinus);



    return 0;
}
