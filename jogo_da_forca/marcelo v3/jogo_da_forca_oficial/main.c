#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"  // Comando para limpar tela no Windows
#else
  #define CLEAR_CMD "clear" // Comando para limpar tela em Unix-like
#endif

// Função que chama o sistema para limpar a tela
void clearScreen() {
    system(CLEAR_CMD);
}

//Funcao que sorteia palavras
const char* sortear_palavra() {
    const char* palavras[] = {
        "cachorro",
        "banana",
        "futebol",
        "janela",
        "brasil"
    };

    int total = sizeof(palavras) / sizeof(palavras[0]); //divide tamanho total do array pelo tamanho de um elemento

    srand(time(NULL)); //aqui é gerado números aleatórios a cada execucao do programa

    int indice = rand() % total; //aqui é gerado um numero aleatorio entre 0 e total-1 no indice

    return palavras[indice]; //retorna a string correspondente ao indice
}

// Exibe informações do grupo no topo da tela
void printGrupo() {
    printf("Grupo\n");
    printf("Nome: Marcelo Henrique Costa da Silva   Matricula: 2024203302\n");
    printf("Nome: Leonardo Sade                     Matricula: 2025105322\n");
    printf("Nome: Ravel Rodrigues de Camargo        Matricula: 2024203247\n\n");
}

// Desenha a forca de acordo com o número de erros
void desenharForca(int erros) {
    printf("  _______\n");
    printf(" |       |\n");
    // Cabeça aparece a partir de 1 erro
    printf(" |       %c\n", (erros >= 1) ? 'O' : ' ');
    // Corpo e braços aparecem conforme erros
    printf(" |      %c%c%c\n",
           //operador ternário - condição ? valorSeVerdadeiro : valorSeFalso
           (erros >= 3) ? '/' : ' ',  // braço esquerdo
           (erros >= 2) ? '|' : ' ',  // tronco
           (erros >= 4) ? '\\' : ' ' // braço direito
    );
    // Pernas aparecem a partir de 5 e 6 erros
    printf(" |      %c %c\n",
           (erros >= 5) ? '/' : ' ',  // perna esquerda
           (erros >= 6) ? '\\' : ' ' // perna direita
    );
    printf(" |\n");
    printf("_|_\n\n");
}

// Conta quantos underscores ainda existem no progresso (letras faltando)
int letrasFaltando(char progresso[]){
    int contador = 0;
    for(int i = 0; progresso[i] != '\0'; i++){
        if(progresso[i] == '_') contador++;
    }
    return contador; // retorna quantas posições ainda não foram reveladas
}

// Checa se uma letra já foi tentada anteriormente
int letraJaTentada(char tentativas[], int totalTentativas, char letra){
    for(int i = 0; i < totalTentativas; i++){
        if(tentativas[i] == letra) return 1; // já tentou -> retorna verdadeiro
    }
    return 0; // nunca tentou -> retorna falso
}

int main() {
    const char *palavra = sortear_palavra(); // palavra a ser adivinhada
    char progresso[strlen(palavra) + 1];
    char tentativas[26] = {0}; // armazena letras já chutadas (inicializa com zeros)
    int erros = 0, totalTentativas = 0;
    char letra;

    // Inicializa o progresso com underscores
    for(int i = 0; palavra[i] != '\0'; i++)
        progresso[i] = '_';
    progresso[strlen(palavra)] = '\0'; // finaliza string

    // Loop principal: continua enquanto erros < 6 e ainda faltarem letras
    while (erros < 6 && letrasFaltando(progresso) > 0) {
        clearScreen();          // limpa tela a cada iteração
        printGrupo();           // mostra legenda do grupo
        desenharForca(erros);   // desenha forca conforme erros

        // Exibe estado atual da palavra e número de erros
        printf("Palavra: %s\n", progresso);
        printf("Erros: %d/6\n", erros);
        printf("Digite uma letra: ");
        scanf(" %c", &letra); // lê um único caractere, ignorando espaços anteriores
        letra = tolower(letra); // converte pra minúscula para padronizar

        // Se a letra já foi tentada, avisa e aguarda ENTER antes de continuar
        if (letraJaTentada(tentativas, totalTentativas, letra)) {
            printf("Voce ja tentou essa letra! Pressione ENTER para continuar...");
            fflush(stdout);
            int c;
            // Limpa eventuais restos de '' no buffer
            while ((c = getchar()) != '\n' && c != EOF) { }
            getchar(); // aguarda ENTER do usuário
            continue;  // volta pro início do loop sem processar chute
        }

        // Registra nova tentativa
        tentativas[totalTentativas++] = letra;

        int acertou = 0;
        // Verifica se a letra aparece em alguma posição da palavra
        for(int i = 0; palavra[i] != '\0'; i++){
            if (tolower(palavra[i]) == letra) {
                progresso[i] = palavra[i]; // revela a letra na posição correta
                acertou = 1;
            }
        }
        if (!acertou) {
            erros++; // incrementa erro se não acertou nenhuma vez
        }
    }

    // Fase final: limpa tela, mostra resultado e palavra completa
    clearScreen();
    printGrupo();
    desenharForca(erros);
    if (letrasFaltando(progresso) == 0) {
        printf("Parabens! Voce descobriu a palavra: %s\n", palavra);
    } else {
        printf("Voce perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
