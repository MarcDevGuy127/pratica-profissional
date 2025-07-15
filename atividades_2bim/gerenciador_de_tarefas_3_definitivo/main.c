#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estrutura.h"

#define MAX_TAREFA 100

//Equipe Ravel Rodrigues de Camargo; Matricula 2024203247
//Equipe Marcelo Henrique Costa da Silva; Matricula 2024203302
//Equipe Leonardo Sade; Matricula 2025105322


int main()
{
    tarefa tarefas[MAX_TAREFA];


    int opcao = 0;
    int ordenado = 0;
    int criterio = 0;
    int procura = 0;
    int quantidade = 0;


    carregarArquivo(tarefas, &quantidade);

    do
    {
        printf("\n");
        printf("1 - Adicionar Tarefa:\n");
        printf("2 - Listar Tarefas:\n");
        printf("3 - Procurar tarefa:\n");
        printf("4 - Editar tarefa:\n");
        printf("5 - Excluir tarefa:\n");
        printf("6 - Relatorio de tarefas pendentes:\n");
        printf("7 - Sair:\n");
        printf("Escolha uma opcao para continuarmos:");
        scanf(" %d", &opcao);

        while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7)
        {
            printf("\nOpcao nao exite tente novamente: ");
            scanf(" %d", &opcao);
        }

        switch(opcao)
        {
        case 1:
            adicionarTarefa(tarefas, &quantidade);
            //salvarEmArquivo(tarefas, quantidade);se ao inves de "w" deixar o "a" ira duplicar melhor chamar so no final
            break;
        case 2:
            listarTarefa(tarefas, &quantidade);

            while(ordenado != 1 && ordenado != 2)
            {
                printf("Deseja ordenar?\n");
                printf("1-Sim\n");
                printf("2-Nao\n");
                printf("Resposta: ");
                scanf(" %d", &ordenado);
                if(ordenado == 1)
                {
                    while(criterio != 1 && criterio != 2)
                    {
                        printf("Por qual criterio quer ordenar?\n");
                        printf("1 - por prioridade:\n");
                        printf("2 - por data:\n");
                        printf("Resposta: ");
                        scanf(" %d", &criterio);

                        if(criterio == 1)
                        {
                            ordenarPrioridade(tarefas, quantidade);
                            listarTarefa(tarefas, &quantidade);
                            break;
                        }
                        else if(criterio == 2)
                        {
                            ordenarData(tarefas, quantidade);
                            listarTarefa(tarefas, &quantidade);
                            break;
                        }

                    }

                }
            }
            ordenado = 0;
            criterio = 0;
            break;
        case 3:
            while(procura != 1 && procura != 2)
            {
                printf("Deseja Procurar por Titulo ou por Status?:\n");
                printf("1-Titulo\n");
                printf("2-Status\n");
                printf("Resposta: ");
                scanf(" %d", &procura);

                if(procura == 1)
                {
                    char titulo[50];
                    printf("Qual Titulo deseja procurar?\n");
                    scanf(" %[^\n]", titulo);

                    pesquisaTitulo(tarefas, quantidade, titulo);
                    break;
                }
                else if(procura == 2)
                {
                    int status = 0;
                    printf("Qual Status deseja procurar?(0-pendente / 1-realizada):");
                    scanf(" %d", &status);
                    pesquisaStatus(tarefas, quantidade, status);


                    break;
                }
                else
                {
                    printf("Nenhuma opção valida selecionada tente novamente!!\n");
                }
            }
            procura = 0;  // Resetar para próxima busca
            printf("\n");
            break;

        case 4:
            editarTarefa(tarefas, quantidade);
            break;
        case 5:
            excluirTarefa(tarefas, &quantidade);
            break;
        case 6:
            relatorioPendentes(tarefas, quantidade);
            break;

        case 7:
            salvarEmArquivo(tarefas, quantidade);
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;

        }

    }
    while(opcao != 7);


    return 0;
}

