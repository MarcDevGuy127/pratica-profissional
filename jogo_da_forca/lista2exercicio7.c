#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Desenha a forca com base no número de erros
void desenharForca(int erros) {
    const char *forca[] = {
        "  _______\n |/      |\n |\n |\n |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |\n |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |       |\n |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |      \\|\n |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |      \\|/\n |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |      \\|/\n |       |\n |\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |      \\|/\n |       |\n |      /\n_|___\n",
        "  _______\n |/      |\n |      (_)\n |      \\|/\n |       |\n |      / \\\n_|___\n"
    };
    printf("%s\n", forca[erros]);
}

// Conta letras ainda não descobertas
int contarLetrasFaltando(const char *palavra, const char *letrasTentadas) {
    int faltando = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] != ' ' && !strchr(letrasTentadas, tolower(palavra[i]))) {
            faltando++;
        }
    }
    return faltando;
}

// Verifica se a letra já foi tentada
int letraTentada(const char *letrasTentadas, char letra) {
    return strchr(letrasTentadas, tolower(letra)) != NULL;
}

int main() {
    int erros = 0, letrasDescobertas = 0;
    char palavra[] = "PATO";
    char letra, letrasTentadas[30] = "", palavraParcial[] = "_ _ _ _";

    while (erros < 7 && letrasDescobertas < strlen(palavra)) {
        desenharForca(erros);
        printf("\nPalavra: %s\nLetras tentadas: %s\nErros: %d/7\n", palavraParcial, letrasTentadas, erros);
        printf("Letras faltando: %d\nDigite uma letra: ", contarLetrasFaltando(palavra, letrasTentadas));
        scanf(" %c", &letra);

        if (letraTentada(letrasTentadas, letra)) {
            printf("Você já tentou essa letra. Tente outra.\n");
            continue;
        }

        letrasTentadas[strlen(letrasTentadas)] = tolower(letra);

        int acerto = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (tolower(letra) == tolower(palavra[i])) {
                palavraParcial[i * 2] = palavra[i];
                letrasDescobertas++;
                acerto = 1;
            }
        }

        if (!acerto) erros++;

        if (letrasDescobertas == strlen(palavra)) {
            printf("\nParabéns! Você venceu! A palavra era: %s\n", palavra);
            break;
        }

        if (erros == 7) {
            printf("\nVocê perdeu! A palavra era: %s\n", palavra);
        }
    }

    return 0;
}
