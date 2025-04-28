#include <stdio.h>
#include <stdlib.h>


void desenharForca(int erros) {
    printf("\n");
    printf("  _______\n");
    printf(" |       |\n");
    printf(" |       %c\n", (erros >= 1) ? 'O' : ' ');
    printf(" |      %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
    printf(" |      %c %c\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
    printf(" |\n");
    printf("_|_\n");
}

int main()
{
    char palavra[] =" carro";
    int erros = 0;

   for(erros = 0; erros <= 6; erros++){
    printf("\nErros: %d\n", erros);
    desenharForca(erros);
   }

    return 0;
}

