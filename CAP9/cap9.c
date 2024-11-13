#include <stdio.h>
#include <locale.h>
#define ex6

#ifdef ex1


/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(tamb m numa fun  o).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

struct info {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

void receber(struct info *dados) {
    printf("\nDigite um valor char: ");
    scanf(" %c", &dados->c);
    printf("Digite um valor int: ");
    scanf("%d", &dados->i);
    printf("Digite um valor long: ");
    scanf("%ld", &dados->l);
    printf("Digite um valor unsigned int: ");
    scanf("%u", &dados->ui);
    printf("Digite um valor float: ");
    scanf("%f", &dados->f);
    printf("Digite um valor double: ");
    scanf("%lf", &dados->d);
    printf("Digite um valor unsigned long: ");
    scanf("%lu", &dados->ul);
    printf("Digite um valor unsigned char: ");
    scanf(" %u", &dados->uc);
}

void imprimir(struct info *dados) {
    printf("\n      10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-10c%-10d%-20ld%-20.2f%-20.2lf\n", dados->c, dados->i, dados->l, dados->f, dados->d);
    printf("          %-20u%-20u%-20lu\n", dados->uc,  dados->ui, dados->ul);
}

int main() {
    char repetir;
    do{
    struct info dados;

    receber(&dados);
    imprimir(&dados);

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
    scanf(" %c", &repetir);
    getchar();
    }
    while (repetir == '1');

    printf("\nSaindo...\n");
    return 0;
}

#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/

int comparar(char *p1, char *p2) {
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            return 0;
        }
        p1++;
        p2++;
    }

    if (*p1 == '\0' && *p2 == '\0') {
        return 1;
    }

    return 0;
}

int main() {
    char repetir;
    do{
        char palavra1[11], palavra2[11];
        char *p1, *p2;
        p1=palavra1;
        p2=palavra2;

        printf("\nDigite a primeira string (até 10 caracteres): ");
        scanf(" %s", p1);

        printf("Digite a segunda string (até 10 caracteres): ");
        scanf(" %s", p2);

        if (comparar(p1, p2)) {
            printf("As palavras sao IGUAIS.\n");
        }
        else {
            printf("As palavras sao DIFERENTES.\n");
        }

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
    scanf(" %c", &repetir);
    getchar();
    }
    while (repetir == '1');

    printf("\nSaindo...\n");
    return 0;
}

#endif // ex2


#ifdef ex3

/*3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/


void soma(float *res, float valor) {
    *res += valor;
}

void sub(float *res, float valor) {
    *res -= valor;
}

void mult(float *res, float valor) {
    *res *= valor;
}

void div(float *res, float valor) {
    if (valor != 0) {
        *res /= valor;
    } else {
        printf("\nErro: Divisão por zero não é permitida.\n");
    }
}

void receber(float *res) {
    float valor;
    char conta;

    *res = 0;
    printf("\nDigite um valor: ");
    scanf("%f", &valor);
    *res = valor;

    while (1) {
        printf("\nDigite a operação desejada (+, -, *, /) ou '=' para exibir o resultado: ");
        scanf(" %c", &conta);

        if (conta == '=') {
            break;
        }

        printf("\nDigite o próximo valor: ");
        scanf("%f", &valor);

        if (conta == '+') {
            soma(res, valor);
        } else if (conta == '-') {
            sub(res, valor);
        } else if (conta == '*') {
            mult(res, valor);
        } else if (conta == '/') {
            div(res, valor);
        } else {
            printf("\nOperação inválida.\n");
        }
    }
}

int main() {
    char repetir;
    do {
        float num;
        receber(&num);
        printf("\nResultado total: %.2f\n", num);

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    } while (repetir == '1');

    printf("\nSaindo...\n");
    return 0;
}

#endif // ex3


#ifdef ex4
/*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
usando ponteiros.(utilize o comando return).
O vetor deve ser declarado como variavel LOCAL na funcao main().
vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/


int pesquisa(char *p_letra, char *vetor, int *p_tamanho) {
    int i;
    for (i=0; i<p_tamanho; i++) {
        if (*(vetor + i) == *p_letra) {
            return 1;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL,"");
    char repetir;
    do{
    char vetor[] = {'b', 'B', 'd', 'D', 'f', 'F', 'h', 'H', 'j', 'J', 'k', 'K', 'm', 'M', 'o', 'O', 'q', 'Q', 's', 'S', 'u', 'U', 'w', 'W', 'y', 'Y'};
    char letra;
    int tamanho=26;
    char *p_letra = &letra;
    int *p_tamanho;

    printf("\nDigite uma letra para pesquisar: ");
    scanf(" %c", p_letra);

    if (pesquisa(p_letra, vetor, p_tamanho)) {
        printf("A letra '%c' está no vetor.\n", letra);
    }
    else {
        printf("A letra '%c' NÃO está no vetor.\n", letra);
    }

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
    scanf(" %c", &repetir);
    getchar();
    } while (repetir == '1');

    printf("\nSaindo...\n");
    return 0;
}



#endif // ex4


#ifdef ex5
/*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
sequencialmente pelo teclado numa funcao e imprima todos os registros no
video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
Coloque no menu a opcao de sair tambem. Utilize o comando switch.
(vetor de estruturas)
estutura: nome, end, cidade, estado, cep*/

struct Endereco {
    char nome[100];
    char end[200];
    char cidade[100];
    char estado[50];
    char cep[10];
};

void receber(struct Endereco *vetor) {
    printf("\n--- Insira os dados ---");
    for (int i=0; i<4; i++) {
        printf("\nDigite o nome da %d° pessoa: ", i + 1);
        gets(vetor[i].nome);

        printf("Digite o endereço da %d° pessoa: ", i + 1);
        gets(vetor[i].end);

        printf("Digite a cidade da %d° pessoa: ", i + 1);
        gets(vetor[i].cidade);
        printf("Digite o estado da %d° pessoa: ", i + 1);
        gets(vetor[i].estado);

        printf("Digite o CEP da %d° pessoa: ", i + 1);
        gets(vetor[i].cep);

        printf("\n");
    }
}

void imprimir(struct Endereco *vetor) {
    printf("\n--- Dados Cadastrados ---");
    for (int i=0; i<4; i++) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Endereço: %s\n", vetor[i].end);
        printf("Cidade: %s\n", vetor[i].cidade);
        printf("Estado: %s\n", vetor[i].estado);
        printf("CEP: %s\n", vetor[i].cep);
    }
}


int main() {
    setlocale(LC_ALL, "");
    struct Endereco vetor[4];
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("Escolha uma opção:\n");
        printf("1 - Ler Dados\n");
        printf("2 - Imprimir Dados\n");
        printf("3 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                receber(vetor);
                break;
            case 2:
                imprimir(vetor);
                break;
            case 3:
                printf("\nSaindo...\n");
                exit(0);
                break;
            default:
                printf("\nEntrada inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    printf("\nSaindo...\n");
    return 0;
}
#endif // ex5


#ifdef ex6
/*6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
exclui um registro sempre usando ponteiros.*/

struct Endereco {
    char nome[100];
    char end[200];
    char cidade[100];
    char estado[50];
    char cep[10];
};

void receber(struct Endereco *vetor) {
    printf("\n--- Insira os dados ---");
    for (int i=0; i<4; i++) {
        printf("\nDigite o nome da %d° pessoa: ", i + 1);
        gets(vetor[i].nome);

        printf("Digite o endereço da %d° pessoa: ", i + 1);
        gets(vetor[i].end);

        printf("Digite a cidade da %d° pessoa: ", i + 1);
        gets(vetor[i].cidade);
        printf("Digite o estado da %d° pessoa: ", i + 1);
        gets(vetor[i].estado);

        printf("Digite o CEP da %d° pessoa: ", i + 1);
        gets(vetor[i].cep);

        printf("\n");
    }
}

void imprimir(struct Endereco *vetor) {
    printf("\n--- Dados Cadastrados ---");
    for (int i=0; i<4; i++) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Endereço: %s\n", vetor[i].end);
        printf("Cidade: %s\n", vetor[i].cidade);
        printf("Estado: %s\n", vetor[i].estado);
        printf("CEP: %s\n", vetor[i].cep);
    }
}


void procurar(struct Endereco *vetor) {
    setlocale(LC_ALL,"");
    char nome[100];
    int i, acho=0;

    printf("\n--- Procurar Registro --- ");
    printf("\nDigite o nome da pessoa que deseja procurar: ");
    gets(nome);

    for (i=0; i<4; i++) {
        int j=0, igual=1;
        while (vetor[i].nome[j] !='\0' && nome[j] !='\0'){
            if (vetor[i].nome[j] != nome[j]){
                igual =0;
                break;
            }
            j++;
        }
        if (igual && vetor[i].nome[j] =='\0' && nome[j] =='\0'){
            printf("\nRegistro encontrado:\n");
            printf("Nome: %s\n", vetor[i].nome);
            printf("Endereço: %s\n", vetor[i].end);
            printf("Cidade: %s\n", vetor[i].cidade);
            printf("Estado: %s\n", vetor[i].estado);
            printf("CEP: %s\n", vetor[i].cep);
            acho=1;
            break;
        }
    }
    if (!acho){
        printf("\nRegistro não encontrado.\n");
    }
}


void alterar(struct Endereco *vetor){
    setlocale(LC_ALL,"");
    char nome[100];
    int i, acho=0;

    printf("\n--- Alterar Registro --- ");
    printf("\nDigite o nome da pessoa que deseja alterar: ");
    gets(nome);

    for (i=0; i<4; i++) {
        int j=0, igual=1;
        while (vetor[i].nome[j] !='\0' && nome[j] !='\0'){
            if (vetor[i].nome[j] != nome[j]) {
                igual=0;
                break;
            }
            j++;
        }
        if (igual && vetor[i].nome[j] == '\0' && nome[j] =='\0'){
            printf("\nDigite os novos dados:\n");
            printf("Novo nome: ");
            gets(vetor[i].nome);

            printf("Novo endereço: ");
            gets(vetor[i].end);

            printf("Nova cidade: ");
            gets(vetor[i].cidade);

            printf("Novo estado: ");
            gets(vetor[i].estado);

            printf("Novo CEP: ");
            gets(vetor[i].cep);

            printf("\nDados atualizados com sucesso!\n");
            acho=1;
            break;
        }
    }
    if (!acho) {
        printf("\nRegistro não encontrado.\n");
    }
}


void excluir(struct Endereco *vetor){
    setlocale(LC_ALL,"");
    char nome[100];
    int i, acho=0;

    printf("\n--- Excluir Registro --- ");
    printf("\nDigite o nome da pessoa que deseja excluir: ");
    gets(nome);

    for (i=0; i<4; i++){
            int j=0, igual=1;
        while (vetor[i].nome[j] !='\0' && nome[j] !='\0'){
            if (vetor[i].nome[j] != nome[j]){
                igual=0;
                break;
            }
            j++;
        }
        if (igual && vetor[i].nome[j] =='\0' && nome[j] =='\0'){
            vetor[i].nome[0] ='\0';
            vetor[i].end[0] ='\0';
            vetor[i].cidade[0] ='\0';
            vetor[i].estado[0] ='\0';
            vetor[i].cep[0] ='\0';

            printf("\nRegistro excluído com sucesso.\n");
            acho=1;
            break;
        }
    }
    if (!acho) {
        printf("\nRegistro não encontrado.\n");
    }
}



int main() {
    setlocale(LC_ALL, "");
    struct Endereco vetor[4];
    int opcao;
    char nome[100];

    do {
        printf("\n--- MENU ---\n");
        printf("Escolha uma opção:\n");
        printf("1 - Ler Dados\n");
        printf("2 - Imprimir Dados\n");
        printf("3 - Procurar Dados\n");
        printf("4 - Alterar Dados\n");
        printf("5 - Excluir Dados\n");
        printf("6 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                receber(vetor);
                break;
            case 2:
                imprimir(vetor);
                break;
            case 3:
                procurar(vetor);
                break;
            case 4:
                alterar(vetor);
                break;
            case 5:
                excluir(vetor);
                break;
            case 6:
                printf("\nSaindo...\n");
                exit(0);
                break;
            default:
                printf("\Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    printf("\nSaindo...\n");
    return 0;
}

#endif // ex6




