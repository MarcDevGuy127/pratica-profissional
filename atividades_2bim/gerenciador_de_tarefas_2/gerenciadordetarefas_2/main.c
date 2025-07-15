#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char titulo[100];
    char descricao[200];
    char data[11]; // DD/MM/AAAA
    int prioridade;
    int status; // 0 = pendente, 1 = concluida
} Tarefa;

// Salva todas as tarefas no arquivo
void salvarEmArquivo(Tarefa *tarefas, int total) {
    FILE *arquivo = fopen("arquivos/tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d|%s|%s|%s|%d|%d\n",
                tarefas[i].id,
                tarefas[i].titulo,
                tarefas[i].descricao,
                tarefas[i].data,
                tarefas[i].prioridade,
                tarefas[i].status);
    }

    fclose(arquivo);
}

// Carrega todas as tarefas do arquivo
void carregarDeArquivo(Tarefa *tarefas, int *total) {
    FILE *arquivo = fopen("arquivos/tarefas.txt", "r");
    if (arquivo == NULL) {
        *total = 0;
        return;
    }

    *total = 0;
    while (fscanf(arquivo, "%d|%99[^|]|%199[^|]|%10[^|]|%d|%d\n",
                  &tarefas[*total].id,
                  tarefas[*total].titulo,
                  tarefas[*total].descricao,
                  tarefas[*total].data,
                  &tarefas[*total].prioridade,
                  &tarefas[*total].status) == 6) {
        (*total)++;
        if (*total >= MAX) break;
    }

    fclose(arquivo);
}

// Adiciona uma nova tarefa
void adicionarTarefa(Tarefa *tarefas, int *total) {
    if (*total >= MAX) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    printf("\n--- Adicionar Tarefa ---\n");

    printf("ID: ");
    scanf("%d", &tarefas[*total].id);
    getchar();

    printf("Titulo: ");
    fgets(tarefas[*total].titulo, sizeof(tarefas[*total].titulo), stdin);
    tarefas[*total].titulo[strcspn(tarefas[*total].titulo, "\n")] = '\0';

    printf("Descricao: ");
    fgets(tarefas[*total].descricao, sizeof(tarefas[*total].descricao), stdin);
    tarefas[*total].descricao[strcspn(tarefas[*total].descricao, "\n")] = '\0';

    printf("Data (DD/MM/AAAA): ");
    fgets(tarefas[*total].data, sizeof(tarefas[*total].data), stdin);
    tarefas[*total].data[strcspn(tarefas[*total].data, "\n")] = '\0';

    printf("Prioridade (1 a 5): ");
    scanf("%d", &tarefas[*total].prioridade);

    printf("Status (0 = Pendente, 1 = Concluida): ");
    scanf("%d", &tarefas[*total].status);
    getchar();

    (*total)++;
    salvarEmArquivo(tarefas, *total);
}

// Lista as tarefas
void listarTarefas(Tarefa *tarefas, int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\n-----------------------------\n");
        printf("ID         : %d\n", tarefas[i].id);
        printf("Titulo     : %s\n", tarefas[i].titulo);
        printf("Descricao  : %s\n", tarefas[i].descricao);
        printf("Data       : %s\n", tarefas[i].data);
        printf("Prioridade : %d\n", tarefas[i].prioridade);
        printf("Status     : %s\n", tarefas[i].status == 0 ? "Pendente" : "Concluida");
    }
}

// Compara datas no formato DD/MM/AAAA
int compararDatas(const char *data1, const char *data2) {
    int d1, m1, a1, d2, m2, a2;
    sscanf(data1, "%d/%d/%d", &d1, &m1, &a1);
    sscanf(data2, "%d/%d/%d", &d2, &m2, &a2);
    if (a1 != a2) return a1 - a2;
    if (m1 != m2) return m1 - m2;
    return d1 - d2;
}

// Ordena por prioridade (decrescente)
void ordenarPorPrioridade(Tarefa *tarefas, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (tarefas[i].prioridade < tarefas[j].prioridade) {
                Tarefa temp = tarefas[i];
                tarefas[i] = tarefas[j];
                tarefas[j] = temp;
            }
        }
    }
    printf("\nTarefas ordenadas por prioridade:\n");
    listarTarefas(tarefas, total);
}

// Ordena por data (mais antiga primeiro)
void ordenarPorData(Tarefa *tarefas, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (compararDatas(tarefas[i].data, tarefas[j].data) > 0) {
                Tarefa temp = tarefas[i];
                tarefas[i] = tarefas[j];
                tarefas[j] = temp;
            }
        }
    }
    printf("\nTarefas ordenadas por data:\n");
    listarTarefas(tarefas, total);
}

// Busca por titulo (parcial)
void buscarPorTitulo(Tarefa *tarefas, int total) {
    char termo[100];
    printf("Digite o titulo a buscar: ");
    fgets(termo, sizeof(termo), stdin);
    termo[strcspn(termo, "\n")] = '\0';

    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (strstr(tarefas[i].titulo, termo) != NULL) {
            if (!encontrou) printf("\nTarefas encontradas:\n");
            listarTarefas(&tarefas[i], 1);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma tarefa com esse titulo.\n");
    }
}

// Busca por status
void buscarPorStatus(Tarefa *tarefas, int total) {
    int status;
    printf("Digite o status (0 = Pendente, 1 = Concluida): ");
    scanf("%d", &status);
    getchar();

    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (tarefas[i].status == status) {
            if (!encontrou) printf("\nTarefas encontradas:\n");
            listarTarefas(&tarefas[i], 1);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma tarefa com esse status.\n");
    }
}

int main() {
    Tarefa tarefas[MAX];
    int totalTarefas = 0;
    int opcao;

    // Carrega as tarefas ao iniciar
    carregarDeArquivo(tarefas, &totalTarefas);

    do {
        printf("\nMENU\n");
        printf("1 - Adicionar Tarefa\n");
        printf("2 - Listar Tarefas\n");
        printf("3 - Ordenar por prioridade\n");
        printf("4 - Ordenar por data\n");
        printf("5 - Buscar por titulo\n");
        printf("6 - Buscar por status\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarTarefa(tarefas, &totalTarefas);
                break;
            case 2:
                listarTarefas(tarefas, totalTarefas);
                break;
            case 3:
                ordenarPorPrioridade(tarefas, totalTarefas);
                break;
            case 4:
                ordenarPorData(tarefas, totalTarefas);
                break;
            case 5:
                buscarPorTitulo(tarefas, totalTarefas);
                break;
            case 6:
                buscarPorStatus(tarefas, totalTarefas);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 7);

    return 0;
}
