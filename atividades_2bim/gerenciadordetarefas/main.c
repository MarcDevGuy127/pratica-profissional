#include <stdio.h>
#include <stdlib.h>

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
