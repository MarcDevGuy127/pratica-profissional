#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estrutura.h"

void adicionarTarefa(tarefa tarefas[], int *quantidade)
{

    if(*quantidade >= MAX_TAREFA)
    {
        printf("limite de tarefas atingido\n");
        return;
    }

    tarefa *t = &tarefas[*quantidade];//isso serve para criar uma nova teraf em uma nova celula

    printf("\nQual sera o titulo dessa tarefa?: ");
    scanf(" %[^\n]", t->titulo);

    printf("\nQual sera a descricao dessa tarefa?: ");
    scanf(" %[^\n]", t->descricao);//ta dizendo pra ler todos os caracteres menos o \n

    do
    {
        printf("\nQual sera a data dessa tarefa?(DD/MM/AAAA): ");
        scanf(" %10s", t->data);

        if(!validarData(tarefas[*quantidade].data))
        {
            printf("Data inválida! Tente novamente.\n");
        }
    }
    while(!validarData(tarefas[*quantidade].data));


    do
    {
        printf("\nQual sera a prioridade dessa tarefa?(1 a 5): ");
        scanf(" %d", &t->prioridade);

        if (t->prioridade < 1 || t->prioridade > 5)
        {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    while (t->prioridade < 1 || t->prioridade > 5);


    do
    {
        printf("\n1- para tarefa realizada / 0 - tarefa pendente.");
        scanf(" %d", &t ->status);

        if(t->status != 0 && t->status != 1)
        {
            printf("Opcao invalida! Tente novamente.\n");
        }
        printf("\n");
    }
    while(t->status != 0 && t->status != 1);

    (*quantidade)++; // incrementa a quantidade de tarefas
    printf("Tarefa adicionada com sucesso!\n");

    printf("\n");
}
void listarTarefa(tarefa tarefas[], int *quantidade)
{

    if(*quantidade==0)
    {
        printf("\nNenhuma tarefa cadastrada");
        return;
    }

    printf("\n======Lista de terefas==========\n");
    for(int i =0; i < *quantidade; i++)
    {
        printf("Tarefa %d\n", i + 1);
        printf("Titulo: %s\n", tarefas[i].titulo);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Data: %s\n", tarefas[i].data);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Status: %s\n", tarefas[i].status == 1 ? "Concluida" : "Pendente");
        printf("----------------------------\n");
    }

}
void ordenarPrioridade(tarefa *tarefas, int quantidade)
{

    tarefa temp;

    for(int i =0; i < quantidade - 1; i++)
    {
        for(int j = 0; j < quantidade - i - 1; j++)
        {
            if(tarefas[j].prioridade > tarefas[j + 1].prioridade)
            {
                temp = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = temp;
            }
        }
    }
}
void ordenarData(tarefa *tarefas, int quantidade)
{

    int i, j;
    for(i = 0; i < quantidade - 1; i++)
    {
        for(j = i + 1; j < quantidade; j++)
        {

            int dia1, mes1, ano1;
            int dia2, mes2, ano2;

            // Separar os componentes das datas
            sscanf(tarefas[i].data, "%d/%d/%d", &dia1, &mes1, &ano1);
            sscanf(tarefas[j].data, "%d/%d/%d", &dia2, &mes2, &ano2);

            //agora compara ano -> mes -> dia
            if(ano1 > ano2 ||(ano1 == ano2 && mes1 > mes2)|| (ano1 == ano2 && mes1 == mes2 && dia1 > dia2))
            {

                //faz a troca das tarefas
                tarefa temp = tarefas[i];
                tarefas[i] = tarefas[j];
                tarefas[j] = temp;
            }
        }
    }
}

int validarData(char data[])
{
    //checa tamanho
    if(strlen(data)!= 10)
    {
        return 0;
    }
    //checa se as barras estão no lugar certo
    if(data[2] != '/' || data[5] != '/')
    {
        return 0;
    }
    // Checa se os outros caracteres são dígitos
    for(int i = 0; i<10; i++)
    {
        if(i == 2 || i == 5)
            continue; // pular as barras
        if(!isdigit(data[i]))
            return 0;
    }
    // Pega os valores de dia, mês, ano
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);//, assim como scanf lê do teclado, só que sscanf lê de uma string já existente.

    // Valida valores possíveis
    if(dia < 1 || dia > 31)
        return 0;
    if(mes < 1 || mes > 12)
        return 0;
    if(ano < 1900 || ano > 2100)
        return 0;

    return 1; // válida

}

int pesquisaTitulo(tarefa *tarefas, int quantidade, char *titulo)
{
    int encontrou = 0;

    for (int i = 0; i < quantidade; i++)
    {
        // Busca parcial usando strstr
        if (strstr(tarefas[i].titulo, titulo) != NULL)
        {
            printf("\nTarefa encontrada:\n");
            printf("Titulo: %s\n", tarefas[i].titulo);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Data: %s\n", tarefas[i].data);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Status: %d\n", tarefas[i].status);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("\nNenhuma tarefa contendo \"%s\" foi encontrada.\n", titulo);
    }
    return encontrou;
}

int pesquisaStatus(tarefa *tarefas, int quantidade,int status)
{

    int encontrou = 0;

    for (int i = 0; i < quantidade; i++)
    {
        if (tarefas[i].status == status)
        {
            printf("\nTarefa encontrada:\n");
            printf("Titulo: %s\n", tarefas[i].titulo);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Data: %s\n", tarefas[i].data);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Status: %d\n", tarefas[i].status);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("\nNenhuma tarefa com status %d foi encontrada.\n", status);
    }
}


void salvarEmArquivo(tarefa *tarefas, int quantidade)
{
    FILE *arquivo = fopen("tarefas.txt", "w");// "w" para toda chamada refazer o txt e a para somar ao que ja tem

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0; i < quantidade; i++)
    {
        fprintf(arquivo,"%s;%s;%s;%d;%d\n",
                tarefas[i].titulo,
                tarefas[i].descricao,
                tarefas[i].data,
                tarefas[i].prioridade,
                tarefas[i].status);
    }
    fclose(arquivo);
    printf("Tarefas salvas com sucesso!\n");
}

void carregarArquivo(tarefa *tarefas, int *quantidade)
{


    FILE *arquivo = fopen("tarefas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nenhum arquivo encontrado. Começando do zero.\n");
        return;
    }
    *quantidade = 0;
    while (*quantidade < MAX_TAREFA &&
            fscanf(arquivo, " %99[^;];%199[^;];%10[^;];%d;%d\n",
                   tarefas[*quantidade].titulo,
                   tarefas[*quantidade].descricao,
                   tarefas[*quantidade].data,
                   &tarefas[*quantidade].prioridade,
                   &tarefas[*quantidade].status) == 5)
    {
        (*quantidade)++;
    }

    fclose(arquivo);
    printf("Tarefas carregadas com sucesso!\n");

}

void excluirTarefa(tarefa *tarefas, int *quantidade)
{
    if (*quantidade == 0)
    {
        printf("Nenhuma tarefa para excluir.\n");
        return;
    }

    listarTarefa(tarefas, quantidade); // mostra as tarefas numeradas

    int indice;
    printf("Digite o número da tarefa que deseja excluir: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > *quantidade)
    {
        printf("Número inválido.\n");
        return;
    }

    indice--; // ajusta para índice de vetor

    for (int i = indice; i < *quantidade - 1; i++)
    {
        tarefas[i] = tarefas[i + 1];
    }

    (*quantidade)--;

    printf("Tarefa excluída com sucesso!\n");
}

void editarTarefa(tarefa *tarefas, int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma tarefa para editar.\n");
        return;
    }

    listarTarefa(tarefas, &quantidade); // mostra tarefas numeradas

    int indice;
    printf("Digite o numero da tarefa que deseja editar: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > quantidade)
    {
        printf("Número inválido.\n");
        return;
    }

    indice--; // ajusta para índice de vetor

    tarefa *t = &tarefas[indice];

    printf("\nNovo titulo (atual: %s): ", t->titulo);
    scanf(" %[^\n]", t->titulo);

    printf("Nova descricao (atual: %s): ", t->descricao);
    scanf(" %[^\n]", t->descricao);

    do
    {
        printf("Nova data (atual: %s) (DD/MM/AAAA): ", t->data);
        scanf(" %10s", t->data);
        if (!validarData(t->data))
        {
            printf("Data invalida! Tente novamente.\n");
        }
    }
    while (!validarData(t->data));

    do
    {
        printf("Nova prioridade (1 a 5, atual: %d): ", t->prioridade);
        scanf(" %d", &t->prioridade);
        if (t->prioridade < 1 || t->prioridade > 5)
        {
            printf("Opção invalida! Tente novamente.\n");
        }
    }
    while (t->prioridade < 1 || t->prioridade > 5);

    do
    {
        printf("Novo status (1 - Concluida, 0 - Pendente, atual: %d): ", t->status);
        scanf(" %d", &t->status);
        if (t->status != 0 && t->status != 1)
        {
            printf("Opção invalida! Tente novamente.\n");
        }
    }
    while (t->status != 0 && t->status != 1);

    printf("Tarefa editada com sucesso!\n");
}
void relatorioPendentes(tarefa *tarefas, int quantidade)
{
    int encontrou = 0;

    printf("\n===== Tarefas Pendentes =====\n");

    for (int i = 0; i < quantidade; i++)
    {
        if (
            tarefas[i].status == 0 &&
            strlen(tarefas[i].titulo) > 0 &&
            strlen(tarefas[i].data) == 10 &&
            tarefas[i].prioridade >= 1 && tarefas[i].prioridade <= 5 &&
            validarData(tarefas[i].data)
        )
        {
            printf("Tarefa %d\n", i + 1);
            printf("Titulo: %s\n", tarefas[i].titulo);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Data: %s\n", tarefas[i].data);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("----------------------------\n");
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma tarefa pendente encontrada.\n");
    }
}

void buscarPorPrioridade(tarefa *tarefas, int *quantidade)
{
    int prioridade;
    int encontrou = 0;

    printf("Digite a prioridade que deseja buscar (1 a 5): ");
    scanf(" %d", &prioridade);

    for (int i = 0; i < *quantidade; i++)
    {
        if (tarefas[i].prioridade == prioridade)
        {
            printf("\nTarefa %d:\n", i + 1);
            printf("Titulo: %s\n", tarefas[i].titulo);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Data: %s\n", tarefas[i].data);
            printf("Status: %s\n", tarefas[i].status == 1 ? "Concluida" : "Pendente");
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma tarefa com prioridade %d foi encontrada.\n", prioridade);
    }
}

void buscaPorData(tarefa *tarefas, int *quantidade)
{
    char dataBusca[11];
    int encontrou = 0;

    printf("Digite a data que deseja buscar (DD/MM/AAAA): ");
    scanf(" %10s", dataBusca);

    for (int i = 0; i < *quantidade; i++)
    {
        if (strcmp(tarefas[i].data, dataBusca) == 0)
        {
            printf("\nTarefa %d:\n", i + 1);
            printf("Titulo: %s\n", tarefas[i].titulo);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Status: %s\n", tarefas[i].status == 1 ? "Concluida" : "Pendente");
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma tarefa encontrada para a data %s.\n", dataBusca);
    }
}

