#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dados{
    char filme[51];
    int quantidadeA;
    float preco;
    char dt_lancamento[10];
};

void entrada(struct dados *p_filmes){
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

    printf("\n------------ LISTA DOS FILMES ------------\n");

    FILE *file=fopen("filmesCadastrados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(1){
        int ver= fread(p_filmes, sizeof(*p_filmes), 1, file);
        if(ver==0)
        break;

        printf("\n------------ FILME ------------\n");
        printf("Nome do filme: %s",p_filmes->filme);
        printf("\nQuantidade: %d",p_filmes->quantidadeA);
        printf("\nPreço: %.2f",p_filmes->preco);
        printf("\nData de lançamento (mês/ano): %s\n",p_filmes->dt_lancamento);
    }
    fclose(file);
}

void pesquisaNome(struct dados *p_filmes){
    char nome[51];
    int achado=0;

    printf("\nDigite o nome completo do filme que deseja pesquisar: ");
    gets(nome);

    FILE *file = fopen("filmesCadastrados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)){
        int i=0, mesma=1;

        while (nome[i] !='\0' && p_filmes->filme[i] !='\0'){
            if (nome[i] !=p_filmes->filme[i]){
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && nome[i]=='\0' && p_filmes->filme[i]=='\0') {
            printf("\n------ FILME ENCONTRADO ------\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Quantidade: %d\n", p_filmes->quantidadeA);
            printf("Preço: %.2f\n", p_filmes->preco);
            printf("Data de lançamento (mês/ano): %s\n", p_filmes->dt_lancamento);
            achado=1;
            break;
        }
    }

    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    fclose(file);
}


void pesquisaData(struct dados *p_filmes){
    char data[10];
    int achado=0;

    printf("\nDigite a data de lançamento do filme para pesquisar: ");
    gets(data);

    FILE *file = fopen("filmesCadastrados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)) {
        int i=0, mesma=1;

        while (data[i] !='\0' && p_filmes->dt_lancamento[i] !='\0'){
            if (data[i] !=p_filmes->dt_lancamento[i]){
                mesma=0;
                break;
            }
            i++;
        }

        if (mesma && data[i] =='\0' && p_filmes->dt_lancamento[i] =='\0') {
            printf("\n------ FILME ENCONTRADO ------\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Quantidade: %d\n", p_filmes->quantidadeA);
            printf("Preço: %.2f\n", p_filmes->preco);
            printf("Data de lançamento (mês/ano): %s\n", p_filmes->dt_lancamento);
            achado=1;
        }
    }

    if (!achado) {
        printf("\nNenhum filme encontrado com essa data de lançamento!\n");
    }

    fclose(file);
}


void listarPreco(struct dados *p_filme) {
    setlocale(LC_ALL, "Portuguese");
    float precoMin, precoMax;
    int encontrado=0;

    printf("\n----------------Listar por faixa de preco--------------\n");
    printf("\nDigite o preço mínimo: ");
    scanf("%f", &precoMin);
    printf("Digite o preço máximo: ");
    scanf("%f", &precoMax);

    printf("\n--------------------R$%.2f / R$%.2f--------------------\n",precoMin,precoMax);
    FILE *file = fopen("filmesCadastrados.txt", "r");
    if(file == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }

    while(1) {
        int verifica = fread(p_filme,sizeof(*p_filme),1,file);
        if(verifica == 0)
            break;

        if(p_filme->preco <= precoMax && p_filme->preco >= precoMin){
            encontrado=1;
            printf("\n--------Filme de R$%.2f-----------\n", p_filme->preco);
            printf("Nome: %s\n", p_filme->filme);
            printf("Quantidade: %d\n", p_filme->quantidadeA);
            printf("Preço: R$ %.2f\n", p_filme->preco);
            printf("Data Lançamento: %s\n", p_filme->dt_lancamento);
        }
    }
    if(!encontrado)
    printf("\nNenhum filme foi encontrado dentro dessa faixa de preço\n");

    fclose(file);
}




/*
void listarPreco(struct dados *p_filmes) {
    struct dados filmes[100]; // Buffer para leitura do arquivo.
    int total = 0, i, j;

    FILE *file = fopen("filmesCadastrados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(&filmes[total], sizeof(struct dados), 1, file)) {
        total++;
    }
    fclose(file);

    // Ordena os filmes pelo preço (Bubble Sort diretamente nos campos).
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - 1 - i; j++) {
            if (filmes[j].preco > filmes[j + 1].preco) {
                // Troca manual dos campos entre filmes[j] e filmes[j+1].
                float tempPreco = filmes[j].preco;
                int tempQuantidadeA = filmes[j].quantidadeA;
                char tempFilme[50]
                char tempDtLancamento[10];

                // Copia os campos para temporários.
                for (int k = 0; k < 50; k++) tempFilme[k] = filmes[j].filme[k];
                for (int k = 0; k < 10; k++) tempDtLancamento[k] = filmes[j].dt_lancamento[k];

                // Troca os campos.
                filmes[j].preco = filmes[j + 1].preco;
                filmes[j].quantidadeA = filmes[j + 1].quantidadeA;
                for (int k = 0; k < 50; k++) filmes[j].filme[k] = filmes[j + 1].filme[k];
                for (int k = 0; k < 10; k++) filmes[j].dt_lancamento[k] = filmes[j + 1].dt_lancamento[k];

                // Reatribui os valores do próximo elemento.
                filmes[j + 1].preco = tempPreco;
                filmes[j + 1].quantidadeA = tempQuantidadeA;
                for (int k = 0; k < 50; k++) filmes[j + 1].filme[k] = tempFilme[k];
                for (int k = 0; k < 10; k++) filmes[j + 1].dt_lancamento[k] = tempDtLancamento[k];
            }
        }
    }

    printf("\n --- Filmes ordenados por preço (do mais barato ao mais caro)---\n");
    for (i = 0; i < total; i++) {
        printf("Nome do filme: %s | Preço: %.2f | Data de lançamento: %s | Quantidade: %d\n",
               filmes[i].filme, filmes[i].preco, filmes[i].dt_lancamento, filmes[i].quantidadeA);
    }
}
*/

void alteraQtd(struct dados *p_filmes) {
    char nome[51];
    int novaQuantidade;
    int achado = 0;

    printf("\nDigite o nome do filme para alterar a quantidade: ");
    gets(nome);

    FILE *file = fopen("filmesCadastrados.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)) {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_filmes->filme[i] != '\0') {
            if (nome[i] != p_filmes->filme[i]) {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_filmes->filme[i] == '\0') {
            printf("\nFilme encontrado!\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Quantidade atual: %d\n", p_filmes->quantidadeA);

            printf("Digite a nova quantidade de filmes: ");
            scanf("%d", &novaQuantidade);

            p_filmes->quantidadeA = novaQuantidade;

            long posicao = -(long)sizeof(*p_filmes);
            fseek(file, posicao, SEEK_CUR);

            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nQuantidade alterada com sucesso!\n");

            achado = 1;
            break;
        }
    }

    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    fclose(file);
}



void alteraPreco(struct dados *p_filmes){
    char nome[51];
    float novoPreco;
    int achado = 0;

    printf("\n------------- ALTERAR PREÇO -------------");
    printf("\nDigite o nome do filme para alterar o preço: ");
    gets(nome);

    FILE *file = fopen("filmesCadastrados.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)) {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_filmes->filme[i] != '\0') {
            if (nome[i] != p_filmes->filme[i]) {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_filmes->filme[i] == '\0') {
            printf("\nFilme encontrado!\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Preço atual: %.2f\n", p_filmes->preco);

            printf("Digite o novo preço: ");
            scanf("%f", &novoPreco);

            p_filmes->preco = novoPreco;

            long posicao = -(long)sizeof(*p_filmes);
            fseek(file, posicao, 1); //SEEK_CUT =1; SEEK_END=2; SEEK_SET=0

            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nPreço alterado com sucesso!\n");

            achado = 1;
            break;
        }
    }

    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    fclose(file);
}


void alterarDados(struct dados *p_filmes) {
    char nome[51];
    int achado = 0;

    printf("\n------------- ALTERAR DADOS DO FILME -------------\n");
    printf("Digite o nome do filme que deseja alterar: ");
    gets(nome);

    FILE *file = fopen("filmesCadastrados.txt", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)) {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_filmes->filme[i] != '\0') {
            if (nome[i] != p_filmes->filme[i]) {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_filmes->filme[i] == '\0') {
            printf("\nFilme encontrado!\n");
            printf("Nome do filme: %s\n", p_filmes->filme);
            printf("Quantidade atual: %d\n", p_filmes->quantidadeA);
            printf("Preço atual: %.2f\n", p_filmes->preco);
            printf("Data de lançamento atual (mês/ano): %s\n", p_filmes->dt_lancamento);

            printf("\nDigite o novo nome do filme: ");
            gets(p_filmes->filme);

            printf("Digite a nova quantidade disponível do filme: ");
            scanf("%d", &p_filmes->quantidadeA);

            printf("Digite o novo preço: ");
            scanf("%f", &p_filmes->preco);

            getchar();
            printf("Digite a nova data de lançamento (mês/ano): ");
            gets(p_filmes->dt_lancamento);

            long posicao = -(long)sizeof(*p_filmes);
            fseek(file, posicao, 1);

            fwrite(p_filmes, sizeof(*p_filmes), 1, file);
            printf("\nDados do filme alterados com sucesso!\n");

            achado = 1;
            break;
        }
    }

    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    fclose(file);
}


void excluiFilme(struct dados *p_filmes) {
    char nome[51];
    int achado = 0;
    long posicao;
    FILE *file = fopen("filmesCadastrados.txt", "r+b");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\n------------- EXCLUIR FILME -------------\n");
    printf("Digite o nome do filme que deseja excluir: ");
    gets(nome);

    while (fread(p_filmes, sizeof(*p_filmes), 1, file)) {
        int i = 0;
        int mesma = 1;

        while (nome[i] != '\0' && p_filmes->filme[i] != '\0') {
            if (nome[i] != p_filmes->filme[i]) {
                mesma = 0;
                break;
            }
            i++;
        }

        if (mesma && nome[i] == '\0' && p_filmes->filme[i] == '\0') {
            printf("\nFilme encontrado: %s\n", p_filmes->filme);

            }

            printf("\nFilme excluído com sucesso!\n");
            achado = 1;
            break;
        }


    if (!achado) {
        printf("\nFilme não encontrado!\n");
    }

    // Fecha o arquivo
    fclose(file);
}






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

------- Lista -------
[x]Na palma da mão
[]Cap 7
[]Cap 8
[x]Cap 9
[]Cap 10
[]Desafio 2
[x]Backlog
[x]ABC Strore
[]Documentação Engenharia
[]P2 Cáculo
[x]T5
[]T6
