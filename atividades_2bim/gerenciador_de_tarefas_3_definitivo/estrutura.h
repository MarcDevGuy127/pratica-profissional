#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#define MAX_TAREFA 100

#define SUCESSO_BUSCA 1
#define FALHA_BUSCA 0

typedef struct Tarefa //com o typedef eu digo que esse Tarefa terá um apelido
{
    char titulo[100];
    char descricao[200];
    char data[11];//(formato "DD/MM/AAAA")
    int prioridade;//(1 a 5)
    int status;// (0 = pendente, 1 = concluída)

} tarefa; //necessario esse apelido para não ter que toda hora escrever struct Tarefa

void adicionarTarefa(tarefa tarefas[], int *quantidade);
void listarTarefa(tarefa tarefas[], int *quantidade);
void buscarPorPrioridade(tarefa *tarefas, int *quantidade);
void buscaPorData(tarefa *tarefas, int *quantidade);

int pesquisaTitulo(tarefa *tarefas, int quantidade,char *titulo);
int pesquisaStatus(tarefa *tarefas, int quantidade,int status);

void ordenarPrioridade(tarefa *tarefas, int quantidade);
void ordenarData(tarefa *tarefas, int quantidade);

int validarData(char data[]);

//=============PARTE DE SALVAMENTO E ESCRITA DE ARQUIVOS ============================
//salvando arquivos
void salvarEmArquivo(tarefa *tarefas, int quantidade);
void carregarArquivo(tarefa *tarefas, int *quantidade);

void editarTarefa(tarefa *tarefas, int quantidade);
void excluirTarefa(tarefa *tarefas, int *quantidade);
void relatorioPendentes(tarefa *tarefas, int quantidade);


#endif
