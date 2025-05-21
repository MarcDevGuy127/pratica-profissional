#include <stdio.h>
#include <stdlib.h>

//caso Windows 32-bits ou Unix
#ifdef _WIN32
  #define CLEAR_CMD "cls"  // Comando para limpar tela no Windows
#else
  #define CLEAR_CMD "clear" // Comando para limpar tela em Unix-like
#endif

#define MAX_CHAR 120 //Limitando numero de caracteres

// Função que chama o sistema para limpar a tela
void clearScreen() {
    system(CLEAR_CMD);
}

void funcaoImprimirTela() {
    printf("\n============MENU============");
    printf("\n 1 - Adicionar Tarefa");
    printf("\n 2 - Listar Tarefas");
    printf("\n 3 - Buscar Tarefa");
    printf("\n 4 - Ordenar Tarefas");
    printf("\n 5 - Editar Tarefa");
    printf("\n 6 - Excluir Tarefa");
    printf("\n 7 - Relatorio de tarefas pendentes");
    printf("\n 8 - Salvar e sair \n");
    return;
}

//void funcaoPopUp() {
//    char opcaoPopup;
//    int opcao;
//
//    printf("\n Voce tem certeza?");
//    printf("\n S - Prosseguir");
//    printf("\n N - Cancelar \n");
//    scanf("%c",&opcaoPopup);
//
//    switch(opcaoPopup) {
//    case 'S':
//        funcaoImprimirTela();
//        break;
//
//    case 'N':
//        opcao = 1;
//        //considerar opcao como 1 e reimprimir tela do case 1
//        break;
//    default:
//        printf("Opcao invalida!\n");
//        getchar();
//        break;
//    }
//    getchar();
//    return;
//}

int main()
{
    FILE *arquivo;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int opcao;
    char texto[MAX_CHAR];
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt
    funcaoImprimirTela();
    scanf("%d", &opcao); //<-- adicionar testes de entrada

    clearScreen(); //limpar tela

    switch (opcao) {
        case 1:
            printf("Escreva a tarefa que voce deseja adicionar:\n");
            arquivo = fopen("arquivos/teste.txt", "w");

            fgets(texto, sizeof(texto), stdin);
            fprintf(arquivo, "%s\n", texto);

            //funcaoPopUp();//Exibe: Voce tem certeza?Sim ou nao.

            fclose(arquivo);
            getchar();

            clearScreen();
            break;
        case 2:
            printf("Listando tarefas disponiveis:\n");

            arquivo = fopen("arquivos/teste.txt", "r");

            while (fgets(linha, sizeof(linha), arquivo)) {
                printf("%s", linha);
            }

            fclose(arquivo); //Salvar alteracoes e fechar arquivo
            getchar();

            clearScreen();
            break;
        case 3:
            printf("Digite a tarefa que deseja consultar:\n");

            fclose(arquivo);
            getchar();

            clearScreen();
            break;
        case 4:
            printf("Ordenando as tarefas disponiveis:\n");

            fclose(arquivo);
            getchar();

            clearScreen();
            break;
        case 5:
            printf("Exibindo tarefas disponiveis:\n");
            //funcao() <--local para reutilizar funcao para exibir tarefas registradas.
            printf("Selecione o numero de uma tarefa para realizar edicao:\n");
            scanf("%d", &opcao);
            printf("A seguinte tarefa foi selecionada para edicao:"); //ver se da para adicionar uma condicional igual o popup Voce tem certeza? S ou N

            //printf(scanf("%c", &texto)); //deixar o texto placeholder da tarefa escolhida para editar na digitaçao
            fclose(arquivo);
            getchar();

            clearScreen();
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            clearScreen();
            break;
    }
}
