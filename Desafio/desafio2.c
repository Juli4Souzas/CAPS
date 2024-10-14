#include <stdio.h>
#include <locale.h>

char filmes[3][25];
int quantidade[3];

void CarregarFilmes()
{
    FILE *file = fopen("filmes.txt", "r");
    if (file == NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            filmes[i][0] = '\0';
            quantidade[i] = 0;
        }
    }
    else
    {
        fread(filmes, sizeof(filmes), 1, file);
        fread(quantidade, sizeof(quantidade), 1, file);
        fclose(file);
    }
}


void SalvarFilmes()
{
    FILE *file = fopen("filmes.txt", "w");
    if (file != NULL)
    {
        fwrite(quantidade, sizeof(quantidade), 1, file);
        fwrite(filmes, sizeof(filmes), 1, file);
        fclose(file);
    }
    else
    {
        printf("Nenhum arquivo encontrado! \n");
    }
}


void CadastrarFilme()
{
    int i;

    printf("\n************************ CADASTRO ************************\n\n");
    printf("(Digite o nome dos filmes com até 25 caracteres)\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("Digite o nome do %d° filme: ", i + 1);
        gets(filmes[i]);


        printf("Digite a quantidade do %d° filme: ", i + 1);
        scanf("%d", &quantidade[i]);
        getchar();
    }
    SalvarFilmes();

    printf("\nParabéns! Filmes cadastrados com sucesso!\n");
}


void ListarFilme()
{
    int i;
    CarregarFilmes();

    printf("\n*************** LISTA DOS FILMES *****************\n\n");

    for (i = 0; i < 3; i++)
    {
        if(filmes[i][0] == '\0')
        {
            continue;
        }
        else
        {
            printf("--- %d° Filme --- \nNome: %s \nQuantidade: %d \n\n", i+1, filmes[i], quantidade[i]);
        }
    }
}




void PesquisarPorNome() {
    char nomeBusca[25];
    int filmeAchado = 0;

    printf("**************** PESQUISAR FILME ***************\n\n");
    printf("\nDigite o nome completo do filme que deseja pesquisar: ");
    gets(nomeBusca);

    for (int i = 0; i < 3; i++) {
        int j = 0;
        while (filmes[i][j] != '\0' && nomeBusca[j] != '\0' && filmes[i][j] == nomeBusca[j]) {
            j++;
        }

        if (filmes[i][j] == '\0' && nomeBusca[j] == '\0') {
            printf("Filme encontrado: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);
            filmeAchado = 1;
            break;
        }
    }

    if (!filmeAchado) {
        printf("Filme não encontrado.\n");
    }



}


void PesquisarPorLetra() {
     char letraBusca;
    int filmeAchado = 0;

    printf("\n************ PESQUISAR FILME POR LETRA *********\n\n");
    printf("\nDigite a primeira letra do filme que deseja pesquisar: ");
    letraBusca = getchar();
    getchar();

    for (int i = 0; i < 3; i++) {
        if (filmes[i][0] == letraBusca) {
            printf("Filme encontrado: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);
            filmeAchado = 1;
        }
    }

    if (!filmeAchado) {
        printf("Nenhum filme encontrado com a letra '%c'.\n", letraBusca);
    }
}
/*
void AlterarFilme() {
    int j;
    int i;
    char nomePesquisa[25];
    int encontrado = 0;

    printf("\n*********** EDITAR FILMES ***********\n");
    printf("Digite o nome do filme que deseja alterar: ");
    gets(nomePesquisa);

    for (i = 0; i < 3; i++) {
        for (j = 0; nomePesquisa[j] != '\0'; j++) {
            if (nomePesquisa[j] != filmes[i][j])
                break;
        }

        if (nomePesquisa[j] == '\0' && filmes[i][j] == '\0') {
            printf("Digite o novo nome do filme: ");
            gets(filmes[i]);

            printf("Digite a nova quantidade: ");
            scanf("%d", &quantidade[i]);
            getchar();
            encontrado = 1;
            break;

            if (encontrado) break;
        }
    }

    if (encontrado) {
        SalvarFilmes();
    } else {
        printf("Filme não encontrado!\n");
    }
}
*/


void AlterarFilme() {
    int j;
    int i;

    char nomePesquisa[25];
    int encontrado = 0;
    system("cls");
    printf("\n-------------- ADICIONAR FILMES --------------\n");
    printf("Digite o nome completo do filme que deseja alterar: ");
    gets(nomePesquisa);

    for (i = 0; i < 3; i++) {
        for (j = 0; nomePesquisa[j] != '\0'; j++) {
            if (nomePesquisa[j] != filmes[i][j])
                break;
        }

        if (nomePesquisa[j] == '\0' && filmes[i][j] == '\0') {
            printf("Digite o novo nome do filme: ");
            gets(filmes[i]);

            printf("Digite a nova quantidade: ");
            scanf("%d", &quantidade[i]);
            getchar();
            encontrado = 1;
            break;

            if (encontrado) break;
        }
    }

    if (encontrado) {
        SalvarFilmes();
    } else {
        printf("Filme não encontrado!\n");
    }
    printf("----------------------------------------------\n");
}



void ExcluirFilme() {
    int j;
    int i;

    char nomePesquisa[25];
    int encontrado = 0;

    printf("\n-------------- EXCLUIR FILMES --------------\n");
    printf("Digite o nome completo do filme que deseja excluir: ");
    gets(nomePesquisa);


    for (i = 0; i < 3; i++) {
        for (j = 0; nomePesquisa[j] != '\0'; j++) {
            if (nomePesquisa[j] != filmes[i][j])
                break;
        }

        if (nomePesquisa[j] == '\0' && filmes[i][j] == '\0') {
            filmes[i][0] = '\0'; // Exclui o nome do filme
            quantidade[i] = 0;  // Exclui a quantidade
            printf("Filme %s excluído!\n", nomePesquisa);
            encontrado = 1;
            break;
        }

        if (encontrado)
            break;
    }



    if (encontrado) {
        SalvarFilmes();
    } else {
        printf("Filme não encontrado!\n");
    }
    printf("----------------------------------------------\n");

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    CarregarFilmes();

    do
    {
        printf("\n******************** MENU **********************\n\n");
        printf("1 - Cadastrar Filmes \n");
        printf("2 - Listar todos os Filmes\n");
        printf("3 - Pesquisar filme por nome completo\n");
        printf("4 - Pesquisar filmes pela primeira letra\n");
        printf("5 - Alterar dados de um filme\n");
        printf("6 - Excluir filme\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {
        case 1:
            CadastrarFilme();
            break;
        case 2:
            ListarFilme();
            break;
        case 3:
            PesquisarPorNome();
            break;
        case 4:
            PesquisarPorLetra();
            break;
        case 5:
            AlterarFilme();
            break;
        case 6:
            ExcluirFilme();
            break;
        case 7:
            printf("Sair");
            exit(0);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while (opcao != 7);
}



