#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para imprimir o desenho da forca com base no número de erros
void imprimirDesenhoForca(int erros) {
    const char *forca[] = {
        "  _______     \n |/      |    \n |            \n |            \n |            \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |            \n |            \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |       |    \n |            \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |      \\|    \n |            \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |      \\|/   \n |            \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |      \\|/   \n |       |    \n |            \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |      \\|/   \n |       |    \n |      /     \n_|___         \n",
        "  _______     \n |/      |    \n |      (_)   \n |      \\|/   \n |       |    \n |      / \\   \n_|___         \n"
    };

    printf("%s\n", forca[erros]);
}

// Função para imprimir a tela do jogo
void imprimirTelaJogo(int erros, const char *palavraParcial, const char *letrasTentativas) {
    printf("========== JOGO DA FORCA ==========\n\n");
    imprimirDesenhoForca(erros);
    printf("Palavra: %s\n", palavraParcial);
    printf("Letras tentadas: %s\n", letrasTentativas);
    printf("Erros: %d de 7\n", erros);
    printf("===================================\n\n");
}

// Função para verificar se letra já foi tentada
int letraJaTentada(char letra, const char *letrasTentativas) {
    for (int i = 0; i < strlen(letrasTentativas); i++) {
        if (tolower(letrasTentativas[i]) == tolower(letra)) {
            return 1;
        }
    }
    return 0;
}

// Função para processar a tentativa de uma letra
int tentativasLetras(char *palavra, char letra, int *erros, char *letrasTentativas) {
    int letraEncontrada = 0;

    if (letraJaTentada(letra, letrasTentativas)) {
        printf("Você já tentou essa letra. Tente outra!\n");
        return 0;
    }

    // Adiciona a letra na lista de tentativas
    int tam = strlen(letrasTentativas);
    letrasTentativas[tam] = toupper(letra);
    letrasTentativas[tam + 1] = '\0';

    for (int i = 0; i < strlen(palavra); i++) {
        if (toupper(letra) == toupper(palavra[i])) {
            letraEncontrada = 1;
        }
    }

    if (!letraEncontrada) {
        (*erros)++;
    }

    return letraEncontrada;
}

int main() {
    int erros = 0;
    char palavra[] = "PATO";
    char letra;
    char letrasTentativas[30] = "";
    char palavraParcial[2 * sizeof(palavra)];  // espaço com underline + espaços
    int letrasDescobertas = 0;

    // Inicializa a palavra parcial com underlines
    for (int i = 0, j = 0; i < strlen(palavra); i++, j += 2) {
        palavraParcial[j] = '_';
        palavraParcial[j + 1] = ' ';
    }
    palavraParcial[2 * strlen(palavra)] = '\0';

    while (erros < 7 && letrasDescobertas < strlen(palavra)) {
        imprimirTelaJogo(erros, palavraParcial, letrasTentativas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int encontrou = tentativasLetras(palavra, letra, &erros, letrasTentativas);

        if (encontrou) {
            for (int i = 0; i < strlen(palavra); i++) {
                if (toupper(letra) == toupper(palavra[i])) {
                    palavraParcial[i * 2] = palavra[i];
                    letrasDescobertas++;
                }
            }
        }
    }

    if (erros == 7) {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    } else {
        printf("\nVocê venceu! A palavra era: %s\n", palavra);
    }

    return 0;
}