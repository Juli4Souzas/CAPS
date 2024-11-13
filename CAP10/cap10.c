#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex3

#ifdef ex1
/*1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).*/

int main() {
    FILE *arquivo;
    char caractere;

    if ((arquivo = fopen("arq.txt", "w"))== NULL) {
        printf("Erro na criação do arquivo.\n");
        return 1;
    }

    printf("Digite caracteres (digite '0' para finalizar):\n");
    do {
        caractere = getchar();
        if (caractere !='0') {
            fputc(caractere, arquivo);
        }
    }
    while (caractere !='0');

    fclose(arquivo);


    if ((arquivo = fopen("arq.txt", "r"))==NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("\nConteúdo do arquivo:\n");
    while (1){
        caractere = getc(arquivo);
        if (caractere == -1){
            break;
        }
        putchar(caractere);
    }

    fclose(arquivo);
    return 0;
}

#endif // ex1


#ifdef ex2


#endif // ex2


#ifdef ex3
#include <stdio.h>
#include <stdlib.h>

struct Cliente {
    char nome[100];
    char email[100];
    char celular[15];
};

void incluirRegistro(FILE *arquivo) {
    struct Cliente cliente;

    // Recebe os dados do cliente
    printf("Digite o nome do cliente: ");
    gets(cliente.nome);
    printf("Digite o e-mail do cliente: ");
    gets(cliente.email);
    printf("Digite o celular do cliente: ");
    gets(cliente.celular);

    // Escreve os dados no arquivo
    fseek(arquivo, 0, SEEK_END);  // Vai para o final do arquivo
    fprintf(arquivo, "%s\n%s\n%s\n", cliente.nome, cliente.email, cliente.celular);
    printf("Cliente cadastrado com sucesso!\n");
}

void listarRegistros(FILE *arquivo) {
    struct Cliente cliente;
    fseek(arquivo, 0, SEEK_SET);  // Vai para o início do arquivo

    printf("\nLista de Clientes:\n");
    while (fscanf(arquivo, "%[^\n]%*c %[^\n]%*c %[^\n]%*c", cliente.nome, cliente.email, cliente.celular) != EOF) {
        printf("Nome: %s\n", cliente.nome);
        printf("E-mail: %s\n", cliente.email);
        printf("Celular: %s\n\n", cliente.celular);
    }
}

void pesquisarRegistro(FILE *arquivo, const char *nomePesquisa) {
    struct Cliente cliente;
    fseek(arquivo, 0, SEEK_SET);  // Vai para o início do arquivo

    printf("\nResultado da pesquisa:\n");
    while (fscanf(arquivo, "%[^\n]%*c %[^\n]%*c %[^\n]%*c", cliente.nome, cliente.email, cliente.celular) != EOF) {
        if (strncmp(cliente.nome, nomePesquisa, 100) == 0) {  // Comparação simples de nome
            printf("Nome: %s\n", cliente.nome);
            printf("E-mail: %s\n", cliente.email);
            printf("Celular: %s\n\n", cliente.celular);
            return;
        }
    }
    printf("Cliente não encontrado.\n");
}

void alterarRegistro(FILE *arquivo, const char *nomePesquisa) {
    struct Cliente cliente;
    long posicao;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);  // Vai para o início do arquivo
    while (fscanf(arquivo, "%[^\n]%*c %[^\n]%*c %[^\n]%*c", cliente.nome, cliente.email, cliente.celular) != EOF) {
        posicao = ftell(arquivo);  // Obtém a posição atual no arquivo

        if (strncmp(cliente.nome, nomePesquisa, 100) == 0) {
            encontrado = 1;
            // Cliente encontrado, altera os dados
            printf("Digite o novo nome: ");
            gets(cliente.nome);
            printf("Digite o novo e-mail: ");
            gets(cliente.email);
            printf("Digite o novo celular: ");
            gets(cliente.celular);

            fseek(arquivo, posicao - (sizeof(cliente.nome) + sizeof(cliente.email) + sizeof(cliente.celular) + 3), SEEK_SET);
            fprintf(arquivo, "%s\n%s\n%s\n", cliente.nome, cliente.email, cliente.celular);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    } else {
        printf("Registro alterado com sucesso!\n");
    }
}

void excluirRegistro(FILE *arquivo, const char *nomePesquisa) {
    struct Cliente cliente;
    FILE *tempFile = fopen("clientes_temp.txt", "w+");  // Arquivo temporário para armazenar os dados restantes
    long posicao;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);  // Vai para o início do arquivo
    while (fscanf(arquivo, "%[^\n]%*c %[^\n]%*c %[^\n]%*c", cliente.nome, cliente.email, cliente.celular) != EOF) {
        posicao = ftell(arquivo);  // Obtém a posição atual no arquivo

        if (strncmp(cliente.nome, nomePesquisa, 100) != 0) {
            fprintf(tempFile, "%s\n%s\n%s\n", cliente.nome, cliente.email, cliente.celular);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);  // Fecha o arquivo original
    fclose(tempFile); // Fecha o arquivo temporário

    if (encontrado) {
        // Abre novamente o arquivo original e o arquivo temporário
        arquivo = fopen("clientes.txt", "w+");  // Sobrescreve o arquivo original
        tempFile = fopen("clientes_temp.txt", "r");  // Lê o arquivo temporário

        // Copia os dados do arquivo temporário para o original
        while (fscanf(tempFile, "%[^\n]%*c %[^\n]%*c %[^\n]%*c", cliente.nome, cliente.email, cliente.celular) != EOF) {
            fprintf(arquivo, "%s\n%s\n%s\n", cliente.nome, cliente.email, cliente.celular);
        }

        printf("Registro excluído com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }

    // Remove o arquivo temporário após a operação
    fclose(tempFile);
    remove("clientes_temp.txt");
}

int main() {
    FILE *arquivo;
    int opcao;
    char nomePesquisa[100];

    arquivo = fopen("clientes.txt", "a+");  // Abre o arquivo para adicionar ou ler

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Incluir registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                incluirRegistro(arquivo);
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                printf("Digite o nome para pesquisar: ");
                gets(nomePesquisa);
                pesquisarRegistro(arquivo, nomePesquisa);
                break;
            case 4:
                printf("Digite o nome para alterar: ");
                gets(nomePesquisa);
                alterarRegistro(arquivo, nomePesquisa);
                break;
            case 5:
                printf("Digite o nome para excluir: ");
                gets(nomePesquisa);
                excluirRegistro(arquivo, nomePesquisa);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    fclose(arquivo);
    return 0;
}



#endif // ex3
