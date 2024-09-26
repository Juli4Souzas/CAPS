#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h> // função já usada em alguma das listas.

#define MAX_FILMES 3
#define MAX_NOME 25
#define ARQUIVO "filmes.dat" // não é função. É para chamar os arquivos guardados de filmes.


char filme[MAX_FILMES][MAX_NOME];
int quantidade = 0 ; // Contador para o número de filmes cadastrados
// Função para carregar dados do arquivo
void carregarDados() {
    FILE *file = fopen(ARQUIVO, "rb");
    if (file != NULL) {
        fread(&quantidade, sizeof(int), 0, file);
        fread(filme, sizeof(char), MAX_FILMES * MAX_NOME, file);
        fclose(file);
    } else {
        printf("Nenhum arquivo encontrado. Iniciando com dados vazios.\n");
    }
}
// Função para salvar dados no arquivo
void salvarDados() {
    FILE *file = fopen(ARQUIVO, "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }
    fwrite(&quantidade, sizeof(int), 1, file);
    fwrite(filme, sizeof(char), MAX_FILMES * MAX_NOME, file);
    fclose(file);
}
// Função para verificar se um filme já está cadastrado
int filmeExistente(char *nome) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filme[i], nome) == 0) {
            return 1; // Filme encontrado
        }
    }
    return 0; // Filme não encontrado
}
// Função para entrada de dados
void entradaDados() {
    if (quantidade >= MAX_FILMES) {
        printf("Limite atingido. Não é possível cadastrar mais filmes.\n");
        return;
    }
    printf("Digite o nome do filme %d: ", quantidade + 1);
    fgets(filme[quantidade], MAX_NOME, stdin);
    filme[quantidade][strcspn(filme[quantidade], "\n")] = 0; // Remove a nova linha
    if (filmeExistente(filme[quantidade])) {
        printf("Filme já cadastrado. Tente novamente.\n");
    } else {
        quantidade++; // Incrementa a quantidade de filmes
        salvarDados(); // Salva os dados após a entrada
        printf("Filme cadastrado com sucesso!\n");
    }
}
// Função para listar todos os filmes
void listarDados() {
    printf("\nLista de filmes:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d: %s\n", i + 1, filme[i]);
    }
}
// Função para pesquisar filme pelo nome completo
void pesquisaPorNome() {
    char nomeBusca[MAX_NOME];
    printf("Digite o nome completo do filme: ");
    fgets(nomeBusca, MAX_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filme[i], nomeBusca) == 0) {
            printf("Filme encontrado: %s\n", filme[i]);
            return;
        }
    }
    printf("Filme não encontrado.\n");
}
// Função para pesquisar filmes pela 1ª letra
void pesquisaPorLetra() {
    char letra;
    printf("Digite a primeira letra do filme: ");
    scanf(" %c", &letra);
    getchar();
    printf("Filmes começando com '%c':\n", letra);
    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (filme[i][0] == letra) {
            printf("%s\n", filme[i]);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum filme encontrado, começando com '%c'.\n", letra);
    }
}
// Função para alterar dados
void alterarDados() {
    char nomeBusca[MAX_NOME];
    printf("Digite o nome completo do filme para alterar: ");
    fgets(nomeBusca, MAX_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filme[i], nomeBusca) == 0) {
            printf("Digite o novo nome do filme: ");
            fgets(filme[i], MAX_NOME, stdin);
            filme[i][strcspn(filme[i], "\n")] = 0;
            if (filmeExistente(filme[i])) {
                printf("Filme já cadastrado. Alteração não realizada.\n");
            } else {
                salvarDados();
                printf("Filme alterado para: %s\n", filme[i]);
            }
            return;
        }
    }
    printf("Filme não encontrado.\n");
}
// Função para excluir dados
void excluirDados() {
    char nomeBusca[MAX_NOME];
    printf("Digite o nome completo do filme para excluir: ");
    fgets(nomeBusca, MAX_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filme[i], nomeBusca) == 0) {
            // Desloca os filmes restantes para preencher o espaço
            for (int j = i; j < quantidade - 1; j++) {
                strcpy(filme[j], filme[j + 1]);
            }
            quantidade--; // Decrementa a quantidade de filmes
            salvarDados(); // Salva após exclusão
            printf("Filme '%s' excluído.\n", nomeBusca);
            return;
        }
    }
    printf("Filme não encontrado.\n");
}
int main() {
    setlocale(LC_ALL, "");
    int opcao;
    carregarDados();
    do {
        printf("\nMenu:\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Lista todos os dados\n");
        printf("3 - Pesquisa um filme pelo nome completo\n");
        printf("4 - Pesquisa os filmes pela 1ª letra\n");
        printf("5 - Altera dados\n");
        printf("6 - Exclui dados\n");
        printf("7 - Saída\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                entradaDados();
                break;
            case 2:
                listarDados();
                break;
            case 3:
                pesquisaPorNome();
                break;
            case 4:
                pesquisaPorLetra();
                break;
            case 5:
                alterarDados();
                break;
            case 6:
                excluirDados();
                break;
            case 7:
                printf("Finalizando. Clique em qualquer tecla para sair.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 7);
    return 0;
}
