#include <stdio.h>
#include <stdlib.h>

//caso Windows 32-bits ou Unix
#ifdef _WIN32
  #define CLEAR_CMD "cls"  // Comando para limpar tela no Windows
#else
  #define CLEAR_CMD "clear" // Comando para limpar tela em Unix-like
#endif

#define MAX_CHAR 120 //Limitando numero de caracteres

// Fun��o que chama o sistema para limpar a tela
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

int main()
{
    int opcao;
    char texto[MAX_CHAR];
    funcaoImprimirTela();
    scanf("%d", &opcao); //<-- adicionar testes de entrada

    clearScreen(); //limpat tela

    switch (opcao) {
        case 1:
            printf("Escreva a tarefa que voce deseja adicionar:\n");
            scanf("%c", &texto);
            printf("A tarefa '%c' foi adicionada!", &texto);
            getchar();
            break;
        case 2:
            printf("Listando tarefas disponiveis:\n");
            getchar();
            break;
        case 3:
            printf("Digite a tarefa que deseja consultar:\n");
            getchar();
            break;
        case 4:
            printf("Ordenando as tarefas disponiveis:\n");
            getchar();
            break;
        case 5:
            printf("Exibindo tarefas disponiveis:\n");
            //funcao() <--local para reutilizar funcao para exibir tarefas registradas.
            printf("Selecione o numero de uma tarefa para realizar edicao:\n");
            scanf("%d", &opcao);
            printf("A seguinte tarefa foi selecionada para edicao:"); //ver se da para adicionar uma condicional igual o popup Voce tem certeza? S ou N

            //printf(scanf("%c", &texto)); //deixar o texto placeholder da tarefa escolhida para editar na digita�ao
            getchar();
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            break;
    }
}
