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
    for(int i = 0; progresso[i] != '\0';i++){
            if(progresso[i]=='_'){
                contador++;
            }
    }
    return contador;
}

int main()
{
    int erros = 0, totalTentativas = 0;
    char palavra[]="programa";
    char progresso[strlen(palavra)+1];//vai ser igual a palavra
    char tentativas[26];
    char letra;

   for(int i =0; palavra[i] != '\0';i++){//isso vai servir para iniciar a forca com os traços em baixo
    progresso[i]='_';
   }
   progresso[strlen(palavra)] = '\0';

   while(erros < 6 && letrasFaltando(progresso) > 0){//mais de 6 perde e maior que zero ainda resta palavra a ser descoberta
        printf("\nPalavra: %s\n", progresso);//irá mostrar os pontilhados
        printf("Tentativas erradas: %d/6\n", erros);// mostra os erros 2/6
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);//transforma tudo em minusculas para não ter erro

        //verifica a letra na palavra
        int acertou = 0;
        for(int i =0; palavra[i] != '\0';i++){
            if(tolower(palavra[i])==letra){
                progresso[i]= palavra[i];// Substitui o traço pela letra correta
                acertou = 1;
            }
        }
        if(!acertou){
                erros++;
            printf("Não acertou\n");
        }
        desenharForca(erros);

   }
   if(letrasFaltando(progresso)==0){
    printf("\nParabéns você descobriu a palavra: %s\n", palavra);
   }else{
       printf("\nVocê perdeu! A palavra era: %s\n", palavra);
   }



    return 0;
}

