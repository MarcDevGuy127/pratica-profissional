#include <stdio.h>
#include <stdlib.h>

//caso Windows 32-bits ou Unix
#ifdef _WIN32
  #define CLEAR_CMD "cls"  // Comando para limpar tela no Windows
#else
  #define CLEAR_CMD "clear" // Comando para limpar tela em Unix-like
#endif

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

int main()
{
    int opcao;
    funcaoImprimirTela();
    scanf("%d", &opcao);

    clearScreen();

    switch (opcao) {
        case 1:
            printf("A");
            getchar();
            break;
        case 2:
            printf("BB");
            getchar();
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            break;
    }
}
