#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int totaLetras;
    char palavra[] = "maca";
    printf("Palavra: %s", palavra);
    //acentos são letras nesse código
    totaLetras = strlen(palavra);
    printf("Há %i letras", totaLetras);
    return 0;
}
