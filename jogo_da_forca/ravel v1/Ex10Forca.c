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
int letrasFaltando(char progresso[]){
    int contador = 0;
    for(int i = 0; i < progresso[i] != '\0';i++){
        if(progresso[i] == '_'){
            contador++;
        }

    }
    return contador;
}
int letraJaTentada(char tentativas[], char totalTentativas, char letra){

    for(int i =0; i < totalTentativas; i++){
        if(tentativas[i] == letra){
            return 1; //letra ja foi tentada
        }
    }
    return 0;// Letra ainda não foi tentada
}
int main()
{
    printf("Grupo\n");
    printf("Nome:Marcelo Henrique Costa da Silva Matricula: 2024203302\n");
    printf("Nome:Leonardo Sade Matricula:2025105322\n");
    printf("Nome:Ravel Rodrigues de Camargo  Matricula:2024203247");
   char palavra[] = "programacao";
   char progresso[strlen(palavra)+1];;  // ERRO! Falta espaço para o '\0' por isso o + 1
   char tentativas[26];
   int erros = 0,totalTentativas = 0;
   char letra;

    for(int i = 0; palavra[i]!= '\0';i++){//isso serve para tentarmos até o final da palavra
            progresso[i]= '_';//aqui preenchemos o progresso com __ __
    }
    progresso[strlen(palavra)] = '\0';//Isso adiciona o caractere nulo \0 no final, transformando progresso em uma string válida.

    while(erros < 6 && letrasFaltando(progresso) > 0){
        printf("\nPalavra: %s\n", progresso);
        printf("Tentativas erradas: %d/6\n", erros);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        if(letraJaTentada(tentativas, totalTentativas, letra)){
            printf("Voce ja tentou essa letra antes! \n");
            continue;
        }
        tentativas[totalTentativas] = letra;
        totalTentativas++;

        int acertou = 0;

        for(int i = 0; palavra[i] != '\0';i++){
            if(tolower(palavra[i])== letra){
                progresso[i] = palavra[i];
                acertou = 1;
            }
        }
        if(!acertou){
            erros++;
            printf("Letra errada");
        }else{
            printf("Palavra correta");
        }
        desenharForca(erros);
    }

    if(letrasFaltando(progresso) == 0){
        printf("Parabens você descobriu a palavra: %s", palavra);
    }else{
        printf("Voce perdeu a palavra era: %s", palavra);
    }

    return 0;
}

