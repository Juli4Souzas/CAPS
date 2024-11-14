#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dados{
    char filme[51];
    int quantidadeA;
    float preco;
    char dt_lancamento[10];
};
/*
void CarregarFilmes(struct dados *p_filmes){
    FILE *file = fopen("filmes.txt", "a");
    if (file == NULL) {
            p_filmes = '\0';
    } else {
        fread(p_filmes, sizeof(p_filmes), 1, file);
        fclose(file);
    }
}


void SalvarFilmes(struct dados *p_filmes)
{
    FILE *file = fopen("filmes.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");

    } else {
        fwrite(p_filmes, sizeof(p_filmes), 1, file);
        fclose(file);
    }
}
*/

void entrada(struct dados *p_filmes){
    setlocale(LC_ALL, "");

    printf("\n--------------------- CADASTRO ---------------------\n\n");
    printf("(Digite os dados sobre o filme)\n\n");

    printf("Nome do filme: ");
    gets(p_filmes->filme);

    printf("Digite  a quantidade disponível do filme:");
    scanf("%d", &p_filmes->quantidadeA);

    printf("Digite o preço: ");
    scanf("%f", &p_filmes->preco);

    getchar();
    printf("Digite a data de lançamento: ");
    gets(p_filmes->dt_lancamento);

    FILE *file=fopen("filmesCadastrados.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    } else {
        fwrite(p_filmes, sizeof(*p_filmes), 1, file);
        fclose(file);
    }


    printf("\nParabéns! Filme cadastrado com sucesso!\n");
}

void lista(struct dados *p_filmes){
    setlocale(LC_ALL,"");

    printf("\n------------ LISTA DOS FILMES ------------\n\n");

    FILE *file=fopen("filmesCadastrados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(1){
        int ver= fread(p_filmes, sizeof(*p_filmes), 1, file);
        if(ver==0)
        break;

        printf("\n------------ FILME ------------\n\n");
        printf("\nNome do filme: %s",p_filmes->filme);
        printf("\nQuantidade: %d",p_filmes->quantidadeA);
        printf("\nPreço: %f",p_filmes->preco);
        printf("\nDta de lançamento: %s",p_filmes->dt_lancamento);
    }
    fclose(file);
}

void pesquisaNome(struct dados *p_filmes){}

void pesquisaData(struct dados *p_filmes){}

void listarPreco(struct dados *p_filmes){}

void alteraQtd(struct dados *p_filmes){}

void alteraPreco(struct dados *p_filmes){}

void alterarDdos(struct dados *p_filmes){}

void excluiFilme(struct dados *p_filmes){}

void saida(){
    printf("\nFinalizando :)");
    exit(0);
}

main(){
    setlocale(LC_ALL, "Portuguese");

    struct dados filmes;
    struct dados *p_filmes;
    p_filmes = &filmes;

    int opcao;

    //CarregarFilmes(p_filmes);

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
           alterarDdos(p_filmes);
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
