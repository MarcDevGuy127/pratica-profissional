#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORIDADE 5 //definindo nivel maximo de prioridade
#define MAX_STATUS 2 //definindo valor maximo de status

typedef struct Tarefa {
    int id;
    char titulo[100];
    char descricao[200];
    char data[11];
    int prioridade;//1 a 5
    int status; //(0 = pendente, 1 = concluída)
}Tarefa;

void imprimeMenu();

int main()
{
    Tarefa tarefa1;

    tarefa1.prioridade = MAX_PRIORIDADE;
    tarefa1.status = MAX_STATUS;

    imprimeMenu();

    return 0;
}

void imprimeMenu () {
    printf("GERENCIADOR DE TAREFAS \n");
    printf("\n MENU PRINCIPAL \n");
    printf("[1] - ADICIONAR TAREFA \n");
    printf("[2] - LISTAR TAREFAS\n");
    printf("[3] - SAIR\n");
return;
}
