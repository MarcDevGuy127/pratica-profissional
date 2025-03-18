#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%i", &numero);

    if (numero <= 1) {
        printf("Não é primo!");
    } else {
        for (int i = 2; i < numero; i++) {
            if (numero % i == 0) {
                printf("Não é primo!");
            }
        }
        printf("Esse número é primo!");
    }

    return 0;
}