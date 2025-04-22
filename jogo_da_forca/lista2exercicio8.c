#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para imprimir o desenho da forca com base no número de erros
void imprimirDesenhoForca(int erros)
{
    const char *forca[] = {
        "  _______     \n"
        " |/      |    \n"
        " |            \n"
        " |            \n"
        " |            \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |            \n"
        " |            \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |       |    \n"
        " |            \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |      \\|    \n"
        " |            \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |      \\|/   \n"
        " |            \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |      \\|/   \n"
        " |       |    \n"
        " |            \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |      \\|/   \n"
        " |       |    \n"
        " |      /     \n"
        "_|___         \n",

        "  _______     \n"
        " |/      |    \n"
        " |      (_)   \n"
        " |      \\|/   \n"
        " |       |    \n"
        " |      / \\   \n"
        "_|___         \n"};

    printf("%s\n", forca[erros]);
}

// Função para imprimir a tela do jogo
void imprimirTelaJogo(int erros, const char *palavraParcial, const char *letrasTentativas)
{
    printf("========== JOGO DA FORCA ==========\n\n");

    imprimirDesenhoForca(erros);

    printf("Palavra: %s\n", palavraParcial);
    printf("Letras tentadas: %s\n", letrasTentativas);
    printf("Erros: %d de 7\n", erros);
    printf("===================================\n\n");
}

// Função que conta as letras faltando
int contarLetrasFaltando(const char *palavra, const char *letrasAdivinhadas)
{
    int letrasFaltando = 0;

    // Percorre a palavra secreta
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] != ' ' && !strchr(letrasAdivinhadas, tolower(palavra[i]))) {
            letrasFaltando++;
        }
    }

    return letrasFaltando;
}

// Função para processar a tentativa de uma letra
void tentativasLetras(char *palavra, char letra, int *erros, char *letrasTentativas, int *letrasDescobertas)
{
    int letraEncontrada = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        if (tolower(letra) == tolower(palavra[i])) {
            letraEncontrada = 1;
            (*letrasDescobertas)++;
        }
    }

    if (!letraEncontrada) {
        (*erros)++;
    }

    // Adiciona a letra na lista de tentativas
    int tam = strlen(letrasTentativas);
    letrasTentativas[tam] = letra;
    letrasTentativas[tam + 1] = '\0';
}

int main()
{
    int erros = 0;
    int letrasDescobertas = 0;  // Contador para letras descobertas
    char palavra[] = "PATO";
    char letra;
    char letrasTentativas[30] = "";  // Lista de letras tentadas
    char palavraParcial[] = "_ _ _ _";  // Palavra parcial para exibir

    while (erros < 7 && letrasDescobertas < strlen(palavra)) {
        // Imprime a tela do jogo
        imprimirTelaJogo(erros, palavraParcial, letrasTentativas);

        // Lê uma nova tentativa
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Processa a tentativa de letra
        tentativasLetras(palavra, letra, &erros, letrasTentativas, &letrasDescobertas);

        // Atualiza a palavra parcial
        for (int i = 0; i < strlen(palavra); i++) {
            if (strchr(letrasTentativas, tolower(palavra[i]))) {
                palavraParcial[i * 2] = palavra[i];  // Atualiza a letra
            }
        }

        // Exibe o progresso
        printf("\nPalavra atual: %s\n", palavraParcial);
    }

    if (erros == 7) {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    } else {
        printf("\nVocê venceu! A palavra era: %s\n", palavra);
    }

    return 0;
}