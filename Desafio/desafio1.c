#include <stdio.h>
#include <locale.h>

char filmes[3][25];
int quantidade[3];

void CarregarFilmes()
{
    FILE *file = fopen("filmes.txt", "rb");
    if (file == NULL) {
        for (int i = 0; i < 3; i++) {
            filmes[i][0] = '\0';
            quantidade[i] = 0;
        }

    } else {

        fread(quantidade, sizeof(quantidade), 1, file);
        fread(filmes, sizeof(filmes), 1, file);
        fclose(file);
    }

}


void SalvarFilmes()
{
    FILE *file = fopen("filmes.txt", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");

    } else {

        fwrite(quantidade, sizeof(quantidade), 1, file);
        fwrite(filmes, sizeof(filmes), 1, file);
        fclose(file);
    }
}

void CadastrarFilme() {
    int i, j, k=0, existente;

    printf("\n************************ CADASTRO ************************\n\n");
    printf("(Digite o nome dos filmes com até 25 caracteres)\n\n");

    for (i = 0; i < 3; i++) {
        do {
            existente = 0;

            printf("Digite o nome do %d° filme: ", i + 1);
            gets(filmes[i]);

            // Filme primary kay
            for (j = 0; j < i; j++) {
                while (filmes[j][k] != '\0' || filmes[i][k] != '\0') {
                    if (filmes[j][k] != filmes[i][k]) {
                        break;

                    }
                    k++;
                }
                if (filmes[j][k] == '\0' && filmes[i][k] == '\0') {
                    printf("\nFilme já cadastrado, escolha outro nome.\n");
                    existente = 1;
                    break;
                }
            }
        } while (existente);

        printf("Digite a quantidade do %d° filme: ", i + 1);
        scanf("%d", &quantidade[i]);
        getchar();
    }

    SalvarFilmes();

    printf("\nParabéns! Filmes cadastrados com sucesso!\n");
}



void ListarFilme(){
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

void PesquisarPorNome(){
    int i,j=0;
     char nomeBusca[25];
     printf("\n**************** PESQUISAR FILME ***************\n");
     printf("Digite o nome completo do filme que deseja pesquisar: ");
     gets(nomeBusca);

    for (i = 0; i <3; i++) {
        if (quantidade[i] > 0) {
            while (filmes[i][j] != '\0' || nomeBusca[j] != '\0') {
                if (filmes[i][j] != nomeBusca[j]) break;
                j++;
            }
            if (filmes[i][j] == '\0' && nomeBusca[j] == '\0') {
                printf("\n--- Filme encontrado! ---\nNome: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);
                return;
            }
        }
    }
    printf("Filme não encontrado! \n");



}

void PesquisarPorLetra(){
    char letra;
    int filmeAchado = 0;
    printf("\n********* PESQUISAR FILME PELA LETRA **********\n");
    printf("\nDigite a primeira letra do filme: ");
    letra = getchar();
    getchar();

    printf("Filmes começando com a letra '%c':\n", letra);

    for (int i = 0; i < 3; i++) {
        if (quantidade[i] > 0 && filmes[i][0] == letra) {
            printf("\n----- Filme encontrado! -----\nNome: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);
            filmeAchado = 1;
        }
    }
    if (!filmeAchado) {
        printf("Nenhum filme encontrado começando com a letra: '%c'.\n", letra);
    }
}



void AlterarFilme() {
    int i, j, k;
    char nomeBusca[25];
    char novoNome[25];
    int duplicado;

    printf("\n*************** ALTERAR FILME ***************\n");
    printf("Digite o nome completo do filme que deseja alterar: ");
    gets(nomeBusca);

    // Busca o filme a ser alterado
    for (i = 0; i < 3; i++) {
        if (quantidade[i] > 0) {
            j = 0; // Resetando o índice j para cada filme

            // Comparação de nome do filme
            while (filmes[i][j] != '\0' || nomeBusca[j] != '\0') {
                if (filmes[i][j] != nomeBusca[j]) break;
                j++;
            }

            // Filme encontrado
            if (filmes[i][j] == '\0' && nomeBusca[j] == '\0') {
                printf("\n--- Filme encontrado! ---\nNome: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);

                // Verifica duplicidade
                do {
                    duplicado = 0;  // Flag para verificar duplicidade

                    printf("Digite o novo nome do filme (até 25 caracteres): ");
                    gets(novoNome);

                    // Verifica se o novo nome já existe em outro filme
                    for (k = 0; k < 3; k++) {
                        if (k != i) { // Ignora a comparação com o próprio filme
                            int l = 0;
                            while (filmes[k][l] != '\0' || novoNome[l] != '\0') {
                                if (filmes[k][l] != novoNome[l]) break;
                                l++;
                            }
                            // Se o nome já existir
                            if (filmes[k][l] == '\0' && novoNome[l] == '\0') {
                                printf("Filme já cadastrado, escolha outro nome.\n");
                                duplicado = 1;  // Nome duplicado
                                break;
                            }
                        }
                    }
                } while (duplicado == 1);

                // Se não houver duplicidade, copia manualmente o novo nome para o vetor filmes[i]
                for (j = 0; j < 25; j++) {
                    filmes[i][j] = novoNome[j];  // Copia caractere por caractere
                    if (novoNome[j] == '\0') break; // Para a cópia ao encontrar o final da string
                }

                printf("Digite a nova quantidade do filme: ");
                scanf("%d", &quantidade[i]);
                getchar();

                SalvarFilmes();
                printf("\nFilme alterado com sucesso!\n");
                return;
            }
        }
    }

    printf("Filme não encontrado!\n");
}



/*

void AlterarFilme() { // duas formas, r e c
    int i, j=0;
    char nomeBusca[25];

    printf("\n*************** ALTERAR FILME ***************\n");
    printf("Digite o nome completo do filme que deseja alterar: ");
    gets(nomeBusca);

    for (i = 0; i < 3; i++) {
        if (quantidade[i] > 0) {

            while (filmes[i][j] != '\0' || nomeBusca[j] != '\0') {
                if (filmes[i][j] != nomeBusca[j]) break;
                j++;
            }
            if (filmes[i][j] == '\0' && nomeBusca[j] == '\0') {
                printf("\n--- Filme encontrado! ---\nNome: %s\nQuantidade: %d\n", filmes[i], quantidade[i]);

                printf("Digite o novo nome do filme (até 25 caracteres): ");
                gets(filmes[i]);

                printf("Digite a nova quantidade do filme: ");
                scanf("%d", &quantidade[i]);
                getchar();

                SalvarFilmes();
                printf("\nFilme alterado com sucesso!\n");
                return;
            }
        }
    }
    printf("Filme não encontrado!\n");



}
*/


void ExcluirFilme() {
   int i,j;

    char nomeBusca[25];
    int filmeAchado = 0;

    printf("\n*************** EXCLUIR FILMES ***************\n\n");
    printf("Digite o nome do filme qa ser excluido: ");
    gets(nomeBusca);


    for (i = 0; i < 3; i++) {
        for (j = 0; nomeBusca[j] != '\0'; j++) {
            if (nomeBusca[j] != filmes[i][j])
                break;
        }

        if (nomeBusca[j] == '\0' && filmes[i][j] == '\0') {
            filmes[i][0] = '\0';
            quantidade[i] = 0;

            printf("Filme %s excluído!\n", nomeBusca);
            filmeAchado = 1;
            break;
        }

        if (filmeAchado)
            break;
    }

    if (filmeAchado) {
        SalvarFilmes();
    } else {
        printf("Filme não encontrado!\n");
    }
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
            printf("Aperte 'enter' para sair...");
            exit(0);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while (opcao != 7);
}
