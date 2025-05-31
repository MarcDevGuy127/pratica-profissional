#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n 1 - Adicionar Tarefa -- FEITO");
    printf("\n 2 - Listar Tarefas -- FEITO");
    printf("\n 3 - Buscar Tarefa -- FEITO");
    printf("\n 4 - Ordenar Tarefas -- FEITO");
    printf("\n 5 - Editar Tarefa");
    printf("\n 6 - Excluir Tarefa");
    printf("\n 7 - Relatorio de tarefas pendentes");
    printf("\n 8 - Salvar e sair -- FEITO");
    printf("\n");
    printf("\nDigite uma opcao: \n");
    return;
}

//para melhorar a funcaoPopup() tem que transformar cada case em uma funcao! Ex: funcaoBuscaTarefa(), funcaoListarTarefas(), funcaoEditarTarefas(), etc.
void funcaoPopUp() {
    char opcaoPopup;

    printf("\n Voce tem certeza?");
    printf("\n S - Prosseguir");
    printf("\n N - Cancelar \n");
    scanf("%c",&opcaoPopup);
    getchar();
    return;
}

void funcaoAdicionaTarefa()
{
    FILE *arquivo;
    char texto[MAX_CHAR];
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt

    printf("Escreva a tarefa que voce deseja adicionar:\n");
    fgets(texto, sizeof(texto), stdin);
    fprintf(arquivo, "%s", texto);
    return;
}

void funcaoListarTarefas()
{
    FILE *arquivo;
    char texto[MAX_CHAR];
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt

    printf("Listando tarefas disponiveis:\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("* %s", linha);
    }
    return;
}

void funcaoBuscarTarefa()
{
    FILE *arquivo;
    char chave[120];
    int encontrado = 0;
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt

    printf("Digite o registro que deseja buscar: ");
    fgets(chave, sizeof(chave), stdin);

    chave[strcspn(chave, "\n")] = '\0';

    while (fgets(linha, sizeof(linha), arquivo)) {
    if (strstr(linha, chave)) {
        printf("Registro encontrado: %s", linha);
        encontrado = 1;
        break;
        }
    }

    if(!encontrado)
    {
        printf("Registro nao encontrado.\n");
    }
    return;
}

void funcaoOrdenaTarefas()
{
    FILE *arquivo;
    char texto[MAX_CHAR];
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt
    int i = 1;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        printf("%d - %s", i, linha);
        i++;
    }

    fgets(texto, sizeof(texto), stdin);
    fprintf(arquivo, "%s", texto);

    return;
}

void funcaoEditarTarefa()
{
    FILE *arquivo;
    int opcaoTarefa;
    char texto[MAX_CHAR];
    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt

    printf("Exibindo tarefas disponiveis:\n");
    //funcao() <--local para reutilizar funcao para exibir tarefas registradas.

    while (fgets(linha, sizeof(linha), arquivo))
    {
        //printf("%d - %s", i, linha);
        printf("%s", linha);
    }

    fgets(texto, sizeof(texto), stdin);
    fprintf(arquivo, "%s", texto);
    printf("Selecione o numero de uma tarefa para realizar edicao:\n");
    scanf("%d", &opcaoTarefa);
    printf("A seguinte tarefa foi selecionada para edicao:"); //ver se da para adicionar uma condicional igual o popup Voce tem certeza? S ou N
    return;
}

void funcaoExcluirTarefa()
{
    return;
}
int main()
{
    FILE *arquivo;
    arquivo = fopen("arquivos/teste.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int opcao, i = 1;
//    char texto[MAX_CHAR];
//    char linha[100]; //quantidade de linhas que irao ser lidas/impressas em teste.txt

    while(opcao != 8){

    funcaoImprimirTela(); //funcao para imprimir menu
    scanf("%d", &opcao);

    if (opcao == "" || opcao == NULL || opcao >= 9 || opcao < 1) {
        clearScreen();
        printf("Opcao invalida!");
        //getchar();
    }

    getchar();
    clearScreen(); //limpar tela

    //rever funcoes
    switch (opcao) {
        case 1: //ADICIONAR
            arquivo = fopen("arquivos/teste.txt", "a");

            if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
            }

            funcaoAdicionaTarefa();

            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();

            break;
        case 2: //LISTAR
            arquivo = fopen("arquivos/teste.txt", "r");

            if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
            }

            funcaoListarTarefas();

            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;
        case 3: //BUSCAR
            arquivo = fopen("arquivos/teste.txt", "r");

            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            funcaoBuscarTarefa();

            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;

        case 4: //ORDENAR
            arquivo = fopen("arquivos/teste.txt", "r");
            printf("Ordenando as tarefas disponiveis:\n");

            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            funcaoOrdenaTarefas();

            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;
        case 5: //EDITAR
            arquivo = fopen("arquivos/teste.txt", "r+");
            //int i = 1;

            if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
            }

            funcaoEditarTarefa();

            //printf(scanf("%c", &texto)); //deixar o texto placeholder da tarefa escolhida para editar na digita�ao
            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;
        case 6: //EXCLUIR
            arquivo = fopen("arquivos/teste.txt", "r+");

            if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
            }

            printf("Escolha uma tarefa para deletar!\n");
            printf("Listando tarefas disponiveis:\n");

            if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
            }

            funcaoListarTarefas();
            funcaoExcluirTarefa();

            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;
        case 7: //RELATORIO
            printf("imprimindo relatorio:\n");

            /*aqui daria para imprimir:
            - Total de tarefas adicionadas.
            - Total de tarefas reescritas.
            - Total de tarefas excluidas.
            - Impressao final.
            */
            funcaoPopUp(); //Exibe a tela: Voce tem certeza?Sim ou nao.
            fclose(arquivo);

            getchar();
            clearScreen();
            break;
        case 8:
            arquivo = fopen("arquivos/teste.txt", "r");
            printf("Saindo do menu");
            fclose(arquivo);
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            clearScreen();
            break;
        }
    }
}
