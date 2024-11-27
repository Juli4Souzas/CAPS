#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dados
{
    char filme[51];
    int quantidadeA;
    float preco;
    char dt_lancamento[10];
};

void entrada(struct dados *p_filmes)
{
    setlocale(LC_ALL, "");

    printf("\n--------------------- CADASTRO ---------------------\n\n");
    printf("(Digite os dados sobre o filme)\n\n");

    printf("Nome do filme: ");
    gets(p_filmes->filme);

    printf("Digite a quantidade disponível do filme:");
    scanf("%d", &p_filmes->quantidadeA);

    printf("Digite o preço: ");
    scanf("%f", &p_filmes->preco);

    getchar();
    printf("Digite a data de lançamento (mês/ano): ");
    gets(p_filmes->dt_lancamento);

    FILE *file=fopen("filmesCadastrados.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }
    else
    {
        fwrite(p_filmes, sizeof(*p_filmes), 1, file);
        fclose(file);
    }


    printf("\nParabéns! Filme cadastrado com sucesso!\n");
}

void lista(struct dados *p_filmes)
{
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS FILMES ------------\n");

    FILE *file=fopen("filmesCadastrados.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(1)
    {
        int ver= fread(p_filmes, sizeof(*p_filmes), 1, file);
        if(ver==0)
            break;

        if(p_filmes->filme[0]!='*')
        {
            printf("\n------------ FILME ------------\n");
            printf("Nome do filme: %s",p_filmes->filme);
            printf("\nQuantidade: %d",p_filmes->quantidadeA);
            printf("\nPreço: %.2f",p_filmes->preco);
            printf("\nData de lançamento (mês/ano): %s\n",p_filmes->dt_lancamento);
        }
    }
    fclose(file);
}

int pesquisaNome(struct dados *p_filmes)
{
    char nome[51];
    int achado=0;
    int cont=0;

    printf("\nDigite o nome completo do filme: ");
    gets(nome);

    FILE *file = fopen("filmesCadastrados.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (1)
    {
        int ver= fread(p_filmes, sizeof(*p_filmes), 1, file);
        if(ver==0)
            break;
        int i=0, mesma=1;

        while (nome[i] !='\0' && p_filmes->filme[i] !='\0')
        {
            if (nome[i] !=p_filmes->filme[i])
            {
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nome[i]=='\0' && p_filmes->filme[i]=='\0')
        {
            printf("\n------ FILME ENCONTRADO ------\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Quantidade: %d\n", p_filmes->quantidadeA);
            printf("Preço: %.2f\n", p_filmes->preco);
            printf("Data de lançamento (mês/ano): %s\n", p_filmes->dt_lancamento);
            achado=1;
            break;
        }
        cont++;
    }

    fclose(file);
    if (!achado)
    {
        printf("\nFilme não encontrado!\n");
        return -1;
    }
    else
    {
        return cont;
    }

}


void pesquisaData(struct dados *p_filmes)
{
    char data[10];
    int achado=0;

    printf("\nDigite a data de lançamento do filme para pesquisar: ");
    gets(data);

    FILE *file = fopen("filmesCadastrados.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (1)
    {
        int ver= fread(p_filmes, sizeof(*p_filmes), 1, file);
        if(ver==0)
            break;
        int i=0, mesma=1;

        while (data[i] !='\0' && p_filmes->dt_lancamento[i] !='\0')
        {
            if (data[i] !=p_filmes->dt_lancamento[i])
            {
                mesma=0;
                break;
            }
            i++;
        }
        if(p_filmes->filme[0]!='*')
        {
            if (mesma && data[i] =='\0' && p_filmes->dt_lancamento[i] =='\0')
            {
                printf("\n------ FILME ENCONTRADO ------\n");
                printf("Nome do filme: %s\n", p_filmes->filme);
                printf("Preço: %.2f\n", p_filmes->preco);
                printf("Data de lançamento (mês/ano): %s\n", p_filmes->dt_lancamento);
                achado=1;
            }
        }


    }

    if (!achado)
    {
        printf("\nNenhum filme encontrado com essa data de lançamento!\n");
    }

    fclose(file);
}


void listarPreco(struct dados *p_filmes)
{
    setlocale(LC_ALL, "Portuguese");
    float pmin, pmax;
    int achado=0;

    printf("\n----------------Listar por faixa de preço--------------\n");
    printf("\nDigite o preço mínimo: ");
    scanf("%f", &pmin);
    printf("Digite o preço máximo: ");
    scanf("%f", &pmax);

    printf("\n---- R$%.2f / R$%.2f ----\n",pmin,pmax);
    FILE *file = fopen("filmesCadastrados.txt", "r");
    if(file == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }

    while(1)
    {
        int verifica = fread(p_filmes,sizeof(*p_filmes),1,file);
        if(verifica == 0)
            break;

        if(p_filmes->filme[0]!='*')
        {
            if(p_filmes->preco <= pmax && p_filmes->preco >= pmin)
            {
                achado=1;
                printf("\n--------Filme de R$%.2f-----------\n", p_filmes->preco);
                printf("Nome: %s\n", p_filmes->filme);
                printf("Quantidade: %d\n", p_filmes->quantidadeA);
                printf("Preço: R$ %.2f\n", p_filmes->preco);
                printf("Data Lançamento: %s\n", p_filmes->dt_lancamento);
            }
        }

    }
    if(!achado)
        printf("\nNenhum filme foi encontrado dentro dessa faixa de preço\n");
    fclose(file);
}



void alteraQtd(struct dados *p_filmes)
{
    printf("\n----- ALTERAR QUANTIDADE -----");
    int novaQuantidade;
    int achado = pesquisaNome(p_filmes);


    FILE *file = fopen("filmesCadastrados.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }


    if(achado != -1)
    {
        printf("\nDigite a quantidade  que deseja adicionar ou retirar do filme: ");
        scanf("%d", &novaQuantidade);

        p_filmes->quantidadeA = p_filmes->quantidadeA+novaQuantidade;

        fseek(file, achado*sizeof(*p_filmes), 1);
        fwrite(p_filmes, sizeof(*p_filmes), 1, file);
        printf("\nQuantidade alterada com sucesso!\n");
    }
    fclose(file);
}



void alteraPreco(struct dados *p_filmes)
{

    printf("\n-------- ALTERAR PREÇO --------\n");
    float novoPreco;
    int achado = pesquisaNome(p_filmes);


    FILE *file = fopen("filmesCadastrados.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if(achado != -1)
    {
        if(p_filmes->filme[0]!='*')
        {
            printf("Digite o novo preço: ");
            scanf("%f", &novoPreco);

            p_filmes->preco = novoPreco;

            fseek(file, achado*sizeof(*p_filmes), 1);
            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nPreço alterado com sucesso!\n");
        }
    }
    fclose(file);

}


void alterarDados(struct dados *p_filmes)
{
    printf("\n------- ALTERAR DADOS -------\n");
    int achado = pesquisaNome(p_filmes);


    FILE *file = fopen("filmesCadastrados.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if(achado != -1)
    {
        if(p_filmes->filme[0]!='*')
        {
            printf("\nDigite o novo nome do filme: ");
            gets(p_filmes->filme);

            printf("Digite a nova quantidade disponível do filme: ");
            scanf("%d", &p_filmes->quantidadeA);

            printf("Digite o novo preço: ");
            scanf("%f", &p_filmes->preco);

            getchar();
            printf("Digite a nova data de lançamento (mês/ano): ");
            gets(p_filmes->dt_lancamento);

            fseek(file, achado*sizeof(*p_filmes), 1);
            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nFilme alterado com sucesso!\n");
        }
    }
    fclose(file);
}


void excluiFilme(struct dados *p_filmes)
{
    printf("\n------------- EXCLUIR FILME -------------\n");
    int achado = pesquisaNome(p_filmes);

    FILE *file = fopen("filmesCadastrados.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if(achado != -1)
    {
        if(p_filmes->filme[0]!='*')
        {

            p_filmes->filme[0]='*';
            fseek(file, achado*sizeof(*p_filmes), 1);
            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nFilme excluído com sucesso!\n");
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

main()
{
    setlocale(LC_ALL, "Portuguese");

    struct dados filmes;
    struct dados *p_filmes;
    p_filmes = &filmes;

    int opcao;

    do
    {
        printf("\n---------------- MENU ----------------\n\n");
        printf("1 - Cadastrar Filmes \n");
        printf("2 - Listar todos os Filmes\n");
        printf("3 - Pesquisar filme por nome completo\n");
        printf("4 - Pesquisar filmes pela data\n");
        printf("5 - Listar filmes pelo preço\n");
        printf("6 - Alterar a quantidade de um filme\n");
        printf("7 - Alterar preço de um filme\n");
        printf("8 - Alterar dados de um filme\n");
        printf("9 - Excluir filme\n");
        printf("10 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {
        case 1:
            entrada(p_filmes);
            break;
        case 2:
            lista(p_filmes);
            break;
        case 3:
            pesquisaNome(p_filmes);
            break;
        case 4:
            pesquisaData(p_filmes);
            break;
        case 5:
            listarPreco(p_filmes);
            break;
        case 6:
            alteraQtd(p_filmes);
            break;
        case 7:
            alteraPreco(p_filmes);
            break;
        case 8:
            alterarDados(p_filmes);
            break;
        case 9:
            excluiFilme(p_filmes);
            break;
        case 10:
            saida();
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while (opcao != 10);
}
