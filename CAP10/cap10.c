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

int main()
{
    FILE *arquivo;
    char caractere;

    if ((arquivo = fopen("arq.txt", "w"))== NULL)
    {
        printf("Erro na cria��o do arquivo.\n");
        return 1;
    }

    printf("Digite caracteres (digite '0' para finalizar):\n");
    do
    {
        caractere = getchar();
        if (caractere !='0')
        {
            fputc(caractere, arquivo);
        }
    }
    while (caractere !='0');

    fclose(arquivo);


    if ((arquivo = fopen("arq.txt", "r"))==NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("\nConte�do do arquivo:\n");
    while (1)
    {
        caractere = getc(arquivo);
        if (caractere == -1)
        {
            break;
        }
        putchar(caractere);
    }

    fclose(arquivo);
    return 0;
}


#endif // ex1


#ifdef ex2
/*2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do m�s.
    6 - altera contato
    7 - exclui contato
    8 - saida*/

struct contatos
{
    char nome[100];
    char telefone[15];
    char niver[7];
};

void incluirRegistro(struct contatos *p_dados)
{
    printf("\n--------------------- CADASTRO ---------------------\n\n");



    for (int i = 0; i < 4; i++)
    {
        printf("Contato %d:\n", i + 1);

        printf("Nome: ");
        gets(p_dados[i].nome);

        printf("Telefone: ");
        gets(p_dados[i].telefone);

        printf("Anivers�rio (m�s/ano): ");
        gets(p_dados[i].niver);




    FILE *file = fopen("contatosCadastrados.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    else
    {
        fwrite(&p_dados[i], sizeof(*p_dados[i]), 1, file);
        fclose(file);
    }


    printf("\nParab�ns! Filme cadastrado com sucesso!\n");
}
}


void lista(struct contatos *p_dados)
{
    printf("\n------------ LISTA DOS CONTATOS ------------\n");

    FILE *file = fopen("contatosCadastrados.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ver= fread(&p_dados[i], sizeof(*p_dados[i]), 1, file);
        if(ver==0)
            break;
        if (p_dados[i].nome[0] != '*')
        {
            printf("\n------------ CONTATO %d ------------\n", i + 1);
            printf("Nome: %s\n", p_dados[i].nome);
            printf("Telefone: %s\n", p_dados[i].telefone);
            printf("Anivers�rio: %s\n", p_dados[i].niver);
        }
    }

    fclose(file);
}

int pesquisaNome(struct contatos *p_dados)
{
    char nomeN[51];
    int achado = 0;
    int cont = 0;

    printf("\nDigite o nome completo do contato: ");
    gets(nomeN);

    FILE *file = fopen("contatosCadastrados.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    for (int i = 0; i < 4; i++)
    {
        int ver = fread(&p_dados[i], sizeof(*p_dados[i]), 1, file);
        if (ver == 0)
        {
            break;
        }

        int mesma = 1;
        int j = 0;

        while (nomeN[j] != '\0' && p_dados[i].nome[j] != '\0')
        {
            if (nomeN[j] != p_dados[i].nome[j])
            {
                mesma = 0;
                break;
            }
            j++;
        }

        if (mesma && nomeN[j] == '\0' && p_dados[i].nome[j] == '\0')
        {
            printf("\n---------- CONTATO ENCONTRADO ----------\n");
            printf("Nome: %s\n", p_dados[i].nome);
            printf("Telefone: %s\n", p_dados[i].telefone);
            printf("Anivers�rio: %s\n", p_dados[i].niver);
            achado = 1;
            break;
        }

        cont++;
    }

    fclose(file);

    if (!achado)
    {
        printf("\nContato n�o encontrado!\n");
        return -1;
    }
    else
    {
        return cont; // Retorna o �ndice do contato encontrado
    }
}


listarLetra(p_dados) {}
imprimirNiver(p_dados) {}
alterar(p_dados) {}

void excluir(struct contatos *p_dados)
{
    printf("\n------------- EXCLUIR FILME -------------\n");

    int achado = pesquisaNome(p_dados);

    FILE *file = fopen("contatosCadastrados.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (achado != -1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (p_dados[i].nome[0] != '*')
            {
                p_dados[i].nome[0] = '*';

                p_filmes->filme[0]='*';
                fseek(file, achado*sizeof(*p_filmes), 1);
                fwrite(p_filmes, sizeof(*p_filmes), 1, file);
                printf("\nContato exclu�do com sucesso!\n");
                achado=1;
                break;
            }
        }
    }

    fclose(file);
}



void saida()
{
    printf("\nFinalizando :)");
    exit(0);
}

int main()
{
    setlocale(LC_ALL, "");
    struct contatos dados[4];
    struct contatos *p_dados= dados;

    int opcao;

    do
    {
        printf("\n-------- Menu --------\n");
        printf("1 - Incluir contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Pesquisar contato pelo nome\n");
        printf("4 - Listar pela Letra\n"); // Corrigir o n�mero do case
        printf("5 - Imprimir aniversariante do m�s\n");
        printf("6 - Alterar contato\n");
        printf("7 - Excluir contato\n");
        printf("8 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
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
            listarLetra(p_dados);
            break;
        case 5:
            imprimirNiver(p_dados);
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
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 8);

    return 0;
}


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

struct cliente
{
    char nome[100];
    char email[100];
    char celular[15];
};

void incluirRegistro(struct cliente *p_dados)
{
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

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }
    else
    {
        fwrite(p_dados, sizeof(*p_dados), 1, file);
        fclose(file);
    }


    printf("\nParab�ns! registro cadastrado com sucesso!\n");
}


void lista(struct cliente *p_dados)
{
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS REGISTROS ------------\n");

    FILE *file=fopen("registros.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(1)
    {
        int ver= fread(p_dados, sizeof(*p_dados), 1, file);
        if(ver==0)
            break;

        if(p_dados->nome[0]!='*'){
        printf("\n------------ Cliente ------------\n");
        printf("Nome: %s",p_dados->nome);
        printf("\nEmail: %s",p_dados->email);
        printf("\nCelular: %s\n\n",p_dados->celular);
        }
    }
    fclose(file);
}

int pesquisaNome(struct cliente *p_dados)
{
    char nomeB[51];
    int achado=0;
    int cont=0;

    printf("\nDigite o nome do cliente que deseja pesquisar: ");
    gets(nomeB);

    FILE *file = fopen("registros.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (1)
    {
        int ver= fread(p_dados, sizeof(*p_dados), 1, file);
        if(ver==0)
            break;
        int i=0, mesma=1;

        while (nomeB[i] !='\0' && p_dados->nome[i] !='\0')
        {
            if (nomeB[i] !=p_dados->nome[i])
            {
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nomeB[i]=='\0' && p_dados->nome[i]=='\0')
        {
            printf("\n----- Registro encontrado -----\n");
            printf("Nome: %s\n", p_dados->nome);
            printf("Email: %s\n", p_dados->email);
            printf("Celular: %s\n", p_dados->celular);
            achado=1;
            break;
        }
        cont++;
    }

    fclose(file);
    if (!achado)
    {
        printf("\nFilme n�o encontrado!\n");
        return -1;
    }
    else
    {
        return cont;
    }

}


void alterar(struct cliente *p_dados)
{
    char nomeB[51];
    int achado = 0;

    printf("\n------------- ALTERAR DADOS -------------\n");
    printf("Digite o nome do registro que deseja alterar: ");
    gets(nomeB);

    FILE *file = fopen("registros.txt", "r+b");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file))
    {
        int i=0, mesma=1;

        while (nomeB[i] !='\0' && p_dados->nome[i] !='\0')
        {
            if (nomeB[i] !=p_dados->nome[i])
            {
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nomeB[i] == '\0' && p_dados->nome[i] == '\0')
        {
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

    if (!achado)
    {
        printf("\nFilme n�o encontrado!\n");
    }

    fclose(file);
}

void excluir(struct cliente *p_dados){
    printf("\n------------- EXCLUIR FILME -------------\n");
    int achado = pesquisaNome(p_dados);

    FILE *file = fopen("registros.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if(achado != -1)
    {
        if(p_dados->nome[0]!='*')
        {

            p_dados->nome[0]='*';
            fseek(file, achado*sizeof(*p_dados), 1);
            fwrite(p_dados, sizeof(*p_dados), 1, file);
            printf("\nFilme exclu�do com sucesso!\n");
            achado=1;
        }
    }
    fclose(file);
}



void saida()
{
    printf("\nFinalizando :)");
    exit(0);
}

int main()
{
    setlocale(LC_ALL, "");
    struct cliente dados;
    struct cliente *p_dados;
    p_dados = &dados;

    int opcao;



    do
    {
        printf("\n-------- Menu --------\n");
        printf("1 - Incluir registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
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
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 6);

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
    3 - pesquisar uma mercadoria pela descri��o
    4 - listar os produtos n�o dispon�veis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/


struct mercadoria
{
    int cod;
    char nomeP[100];
    int quantidadeA;
};

void incluirProduto(struct mercadoria *p_dados)
{
    setlocale(LC_ALL, "");

    printf("\n---------------- CADASTRO DE PRODUTOS ----------------\n\n");
    printf("(Digite os dados sobre o produto)\n\n");

    printf("C�digo: ");
    scanf("%d",&p_dados->cod);

    getchar();

    printf("Digite nome do produto: ");
    gets(p_dados->nomeP);

    printf("Digite a quantidade: ");
    scanf("%d",&p_dados->quantidadeA);



    FILE *file=fopen("produtos.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }
    else
    {
        fwrite(p_dados, sizeof(*p_dados), 1, file);
        fclose(file);
    }


    printf("\nParab�ns! registro cadastrado com sucesso!\n");
}


void lista(struct mercadoria *p_dados)
{
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS REGISTROS ------------\n");

    FILE *file = fopen("produtos.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file))
    {
        // Verifica se a leitura foi bem-sucedida
        printf("\n------------ Produto ------------\n");
        printf("C�digo: %d\n", p_dados->cod);  // Use %d para inteiros
        printf("Nome do Produto: %s\n", p_dados->nomeP);
        printf("Quantidade: %d\n\n", p_dados->quantidadeA);  // Use %d para inteiros
    }

    fclose(file);
}




void pesquisaDescricao(p_dados) {}
void listaIndisponivel(p_dados) {}


void alterarQtd(struct mercadoria *p_dados)
{
    char nome[51];
    int novaQuantidade;
    int achado = 0;

    printf("\nDigite o nome da mercadoria para alterar a quantidade: ");
    gets(nome);  // Leitura do nome do filme

    FILE *file = fopen("produtos.txt", "r+b");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_dados, sizeof(*p_dados), 1, file))
    {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_dados->nomeP[i] != '\0')
        {
            if (nome[i] != p_dados->nomeP[i])
            {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_dados->nomeP[i] == '\0')
        {
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

    if (!achado)
    {
        printf("\nProduto n�o encontrado!\n");
    }

    fclose(file);
}

void alterar(p_dados) {}
void excluir(p_dados) {}


void saida()
{
    printf("\nFinalizando :)");
    exit(0);
}

int main()
{
    setlocale(LC_ALL, "");
    struct mercadoria dados;
    struct mercadoria *p_dados;
    p_dados = &dados;

    int opcao;

    do
    {
        printf("\n-------- Menu --------\n");
        printf("1 - Incluir registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
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
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    while (opcao != 8);

    return 0;
}


#endif // ex4
