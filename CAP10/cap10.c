#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex4

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
/*3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/

struct cliente {
    char nome[100];
    char email[100];
    char celular[15];
};

void incluirRegistro(struct cliente *p_dados) {
    setlocale(LC_ALL, "");

    printf("\n--------------------- CADASTRO ---------------------\n\n");
    printf("(Digite os dados sobre o cliente)\n\n");

    printf("Nome: ");
    gets(p_dados->nome);

    printf("Digite o email: ");
    gets(p_dados->email);

    printf("Digite o celular: ");
    gets(p_dados->celular);



    FILE *file=fopen("registros.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    } else {
        fwrite(p_dados, sizeof(*p_dados), 1, file);
        fclose(file);
    }


    printf("\nParabéns! registro cadastrado com sucesso!\n");
}


void lista(struct cliente *p_dados){
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS REGISTROS ------------\n");

    FILE *file=fopen("registros.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(1){
        int ver= fread(p_dados, sizeof(*p_dados), 1, file);
        if(ver==0)
        break;

        printf("\n------------ Cliente ------------\n");
        printf("Nome: %s",p_dados->nome);
        printf("\nEmail: %s",p_dados->email);
        printf("\nCelular: %s\n\n",p_dados->celular);
    }
    fclose(file);
}

void pesquisaNome(struct cliente *p_dados){
    char nomeB[51];
    int achado=0;

    printf("\nDigite o nome do cliente que deseja pesquisar: ");
    gets(nomeB);

    FILE *file = fopen("registros.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file)){
        int i=0, mesma=1;

        while (nomeB[i] !='\0' && p_dados->nome[i] !='\0'){
            if (nomeB[i] !=p_dados->nome[i]){
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nomeB[i]=='\0' && p_dados->nome[i]=='\0') {
            printf("\n------ REGISTRO ENCONTRADO ------\n");
            printf("Nome: %s\n", p_dados->nome);
            printf("Email: %s\n", p_dados->email);
            printf("Celular: %s\n", p_dados->celular);
            achado=1;
            break;
        }
    }

    if (!achado) {
        printf("\nRegistro não encontrado!\n");
    }

    fclose(file);
}


void alterar(struct cliente *p_dados) {
    char nomeB[51];
    int achado = 0;

    printf("\n------------- ALTERAR DADOS -------------\n");
    printf("Digite o nome do registro que deseja alterar: ");
    gets(nomeB);

    FILE *file = fopen("registros.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file)){
        int i=0, mesma=1;

        while (nomeB[i] !='\0' && p_dados->nome[i] !='\0'){
            if (nomeB[i] !=p_dados->nome[i]){
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nomeB[i] == '\0' && p_dados->nome[i] == '\0') {
            printf("\nRegistro encontrado!\n");
            printf("Nome: %s\n", p_dados->nome);
            printf("Email: %s\n", p_dados->email);
            printf("Celular: %s\n", p_dados->celular);

            printf("\nDigite o novo nome: ");
            gets(p_dados->nome);

            printf("Digite o novo Email: ");
            gets(p_dados->email);

            printf("Digite o celular: ");
            gets(p_dados->celular);

            long posicao = -(long)sizeof(*p_dados);
            fseek(file, posicao, 1);

            fwrite(p_dados, sizeof(*p_dados), 1, file);
            printf("\nDados do registre alterados com sucesso!\n");

            achado = 1;
            break;
        }
    }

    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    fclose(file);
}
/*
void excluir(struct cliente *p_dados){
    char nomeB[100];
    int achado=0;
    long posicaoInicial, posicaoAtual;

    printf("\n------------- EXCLUIR REGISTRO -------------\n");
    printf("Digite o nome do cliente que deseja excluir: ");
    gets(nomeB);

    FILE *file = fopen("registros.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file)){
        int i=0, mesma=1;

        while (nomeB[i] !='\0' && p_dados->nome[i] !='\0'){
            if (nomeB[i] !=p_dados->nome[i]){
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nomeB[i] == '\0' && p_dados->nome[i] == '\0') {
            printf("\nRegistro encontrado e será excluído!\n");
            printf("Nome: %s\n", p_dados->nome);
            printf("Email: %s\n", p_dados->email);
            printf("Celular: %s\n", p_dados->celular);
            achado = 1;

            posicaoInicial = ftell(file) - sizeof(*p_dados);

            // Move e reescreve todos os registros seguintes para "cobrir" o excluído
            while (fread(p_dados, sizeof(*p_dados), 1, file)) {
                posicaoAtual = ftell(file);
                fseek(file, posicaoInicial, SEEK_SET);
                fwrite(p_dados, sizeof(*p_dados), 1, file);
                posicaoInicial += sizeof(*p_dados);
                fseek(file, posicaoAtual, SEEK_SET);
            }

            // Ajusta o tamanho do arquivo para eliminar o espaço residual
            fflush(file);
            ftruncate(fileno(file), posicaoInicial);
            break;
        }
    }

    fclose(file);

    if (achado) {
        printf("\nRegistro excluído com sucesso!\n");
    } else {
        printf("\nRegistro não encontrado!\n");
    }
}
*/


void saida(){
    printf("\nFinalizando :)");
    exit(0);
}

int main() {
    setlocale(LC_ALL, "");
    struct cliente dados;
    struct cliente *p_dados;
    p_dados = &dados;

    int opcao;



    do {
        printf("\n-------- Menu --------\n");
        printf("1 - Incluir registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                incluirRegistro(p_dados);
                break;
            case 2:
                lista(p_dados);
                break;
            case 3:
                pesquisaNome(p_dados);
                break;
            case 4:
                alterar(p_dados);
                break;
            case 5:
                excluir(p_dados);
                break;
            case 6:
                saida();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}


#endif // ex3

#ifdef ex4
/*4 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/


struct mercadoria {
    int cod;
    char nomeP[100];
    int quantidadeA;
};

void incluirProduto(struct mercadoria *p_dados){
    setlocale(LC_ALL, "");

    printf("\n---------------- CADASTRO DE PRODUTOS ----------------\n\n");
    printf("(Digite os dados sobre o produto)\n\n");

    printf("Código: ");
    scanf("%d",&p_dados->cod);

    getchar();

    printf("Digite nome do produto: ");
    gets(p_dados->nomeP);

    printf("Digite a quantidade: ");
    scanf("%d",&p_dados->quantidadeA);



    FILE *file=fopen("produtos.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    } else {
        fwrite(p_dados, sizeof(*p_dados), 1, file);
        fclose(file);
    }


    printf("\nParabéns! registro cadastrado com sucesso!\n");
}


void lista(struct mercadoria *p_dados){
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS REGISTROS ------------\n");

    FILE *file = fopen("produtos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file)) {
        // Verifica se a leitura foi bem-sucedida
        printf("\n------------ Produto ------------\n");
        printf("Código: %d\n", p_dados->cod);  // Use %d para inteiros
        printf("Nome do Produto: %s\n", p_dados->nomeP);
        printf("Quantidade: %d\n\n", p_dados->quantidadeA);  // Use %d para inteiros
    }

    fclose(file);
}




void pesquisaDescricao(p_dados){}
void listaIndisponivel(p_dados){}


void alterarQtd(struct mercadoria *p_dados) {
    char nome[51];
    int novaQuantidade;
    int achado = 0;

    printf("\nDigite o nome da mercadoria para alterar a quantidade: ");
    gets(nome);  // Leitura do nome do filme

    FILE *file = fopen("produtos.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file)) {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_dados->nomeP[i] != '\0') {
            if (nome[i] != p_dados->nomeP[i]) {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_dados->nomeP[i] == '\0') {
            printf("\nFilme encontrado!\n");
            printf("Nome do filme: %s\n", p_dados->nomeP);
            printf("Quantidade atual: %d\n", p_dados->quantidadeA);

            printf("Digite a nova quantidade de filmes: ");
            scanf("%d", &novaQuantidade);

            p_dados->quantidadeA = novaQuantidade;

            long posicao = -(long)sizeof(*p_dados);
            fseek(file, posicao, SEEK_CUR);

            fwrite(p_dados, sizeof(*p_dados), 1, file);
            printf("\nQuantidade alterada com sucesso!\n");

            achado = 1;
            break;
        }
    }

    if (!achado) {
        printf("\nProduto não encontrado!\n");
    }

    fclose(file);
}

void alterar(p_dados){}
void excluir(p_dados){}


void saida(){
    printf("\nFinalizando :)");
    exit(0);
}

int main() {
    setlocale(LC_ALL, "");
    struct mercadoria dados;
    struct mercadoria *p_dados;
    p_dados = &dados;

    int opcao;

    do {
        printf("\n-------- Menu --------\n");
        printf("1 - Incluir registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                incluirProduto(p_dados);
                break;
            case 2:
                lista(p_dados);
                break;
            case 3:
                pesquisaDescricao(p_dados);
                break;
            case 4:
                listaIndisponivel(p_dados);
                break;
            case 5:
                alterarQtd(p_dados);
                break;
            case 6:
                alterar(p_dados);
                break;
            case 7:
                excluir(p_dados);
                break;
            case 8:
                saida();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}


#endif // ex4
