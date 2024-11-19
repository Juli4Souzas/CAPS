#include <stdio.h>
#include <locale.h>

#define ex5

#ifdef ex1
/*1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char*/


int main()
{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;

    char *p_c;
    int *p_i;
    long *p_l;
    unsigned int *p_ui;
    float *p_f;
    double *p_d;
    unsigned long *p_ul;
    unsigned char *p_uc;

    p_c = &c;
    p_i = &i;
    p_l = &l;
    p_ui = &ui;
    p_f = &f;
    p_d = &d;
    p_ul = &ul;
    p_uc = &uc;

    char repetir;

    do
    {
        printf("\nDigite um valor char: ");
        scanf(" %c", p_c);
        printf("Digite um valor int: ");
        scanf("%d", p_i);
        printf("Digite um valor long: ");
        scanf("%ld", p_l);
        printf("Digite um valor unsigned int: ");
        scanf("%u", p_ui);
        printf("Digite um valor float: ");
        scanf("%f", p_f);
        printf("Digite um valor double: ");
        scanf("%lf", p_d);
        printf("Digite um valor unsigned long: ");
        scanf("%lu", p_ul);
        printf("Digite um valor unsigned char: ");
        scanf(" %u", p_uc);

        printf("\n        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-20d%-20ld%-20u\n", *p_i, *p_l, *p_ui);
        printf("              %-20.2f%-20.2lf%-20c\n", *p_f, *p_d, *p_c);
        printf("         %-20lu%-20u\n", *p_ul, *p_uc);

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}


#endif // ex1


#ifdef ex2
/*2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
funcao para compara-las usando ponteiros e retorne como resultado se
sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
Imprima o resultado na funcao main(). Declare os vetores como variavel global*/


char palavra1[11], palavra2[11];

int compara()
{
    char *p1,*p2;
    p1 = &palavra1;
    p2 = &palavra2;

    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
        {
            return 0;
        }
        p1++;
        p2++;
    }

    if (*p1 == '\0' && *p2 == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL,"");
    char repetir;
    do
    {
        printf("\nDigite a primeira palavra (até 10 caracteres): ");
        scanf("%s", palavra1);

        printf("Digite a segunda palavra (até 10 caracteres): ");
        scanf("%s", palavra2);

        // Chama a função de comparação e imprime o resultado
        if (compara())
        {
            printf("As palavras sao IGUAIS.\n");
        }
        else
        {
            printf("As palavras sao DIFERENTES.\n");
        }

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}

#endif // ex2


#ifdef ex3
/*3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
 uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
para a funcao a letra digitada usando ponteiros.(utilize o comando return).
O vetor deve ser declarado como variavel global.
vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

char vetor[] = {'b', 'B', 'd', 'D', 'f', 'F', 'h', 'H', 'j', 'J', 'k', 'K', 'm', 'M', 'o', 'O', 'q', 'Q', 's', 'S', 'u', 'U', 'w', 'W', 'y', 'Y'};


int pesquisa(char *lletra)
{
    int i;
    for (i=0; i<28; i++)   // 28: tamanho do vetor (um para cada letra, maiúscula e minúscula)
    {
        if (*lletra == vetor[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "");
    char repetir;

    do
    {
        char letra;
        char *l;
        l=&letra;

        printf("\nDigite uma letra: ");
        scanf(" %c", l);

        if (pesquisa(l))
        {
            printf("A letra '%c' está no vetor.\n", letra);
        }
        else
        {
            printf("A letra '%c' não está no vetor.\n", letra);
        }

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;
}
#endif // ex3




#ifdef ex4
/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
feitos usando ponteiro.*/


int main()
{
    setlocale(LC_ALL, "");
    char repetir;
    do
    {
        float media;
        int num, soma = 0, cont = 0;
        int *ps, *pc,*pn;
        ps = &soma;
        pc = &cont;
        pn = &num;

        printf("\nDigite números inteiros e positivos para o cálculo da média (ou um número negativo para sair)\n\n");

        while (1)
        {
            printf("Digite um número: ");
            scanf("%d", pn);

            if (*pn < 0)
            {
                break;
            }

            *ps += *pn;
            (*pc)++;
        }

        if (*pc>0)
        {
            media = (float)(*ps) / (*pc);
            printf("A média dos números digitados é: %.2f\n", media);
        }
        else
        {
            printf("Nenhum número válido foi digitado.\n");
        }

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;
}


#endif // ex4


#ifdef ex5
/*5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/


struct Endereco {
    char nome[50];
    char endereco[100];
    char cidade[50];
    char estado[3];
    char cep[10];
};

void recebe(struct Endereco *p_dados) {
    setlocale(LC_ALL, "");
    int i;
    printf("\n--- Cadastros ---\n");
    for (i=0; i<4; i++) {
        printf("\n- %d Pessoa -\n", i + 1);
        printf("Digite o nome: ");
        gets(p_dados[i].nome);
        printf("Digite o endereço: ");
        gets(p_dados[i].endereco);
        printf("Digite a cidade: ");
        gets(p_dados[i].cidade);
        printf("Digite o estado: ");
        gets(p_dados[i].estado);
        printf("Digite o CEP: ");
        gets(p_dados[i].cep);
    }
}

void imprime(struct Endereco *p_dados) {
    setlocale(LC_ALL, "");
    int i;
    printf("\n--- Dados Cadastrados ---\n");
    for (i=0; i<4; i++) {
        printf("\n- %d° Pessoa -\n", i + 1);
        printf("Nome: %s\n", p_dados[i].nome);
        printf("Endereço: %s\n", p_dados[i].endereco);
        printf("Cidade: %s\n", p_dados[i].cidade);
        printf("Estado: %s\n", p_dados[i].estado);
        printf("CEP: %s\n", p_dados[i].cep);
    }
}

int main() {
    char repetir;
    do{
        struct Endereco dados[4];
        struct Endereco *p_dados = dados;

        recebe(p_dados);
        imprime(p_dados);

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair...\n");

    return 0;
}

#endif // ex5


#ifdef ex6
/*6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano*/

struct Data
{
    int dia;
    int mes;
    int ano;
};

int bis(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int totaDiasNoMes(int mes, int ano)
{
    if (mes == 2)
    {
        return bis(ano) ? 29 : 28;
    }
    return 31;
}

int calcularTotalDias(struct Data *data1, struct Data *data2)
{
    int dias = 0;

    if (data1->ano == data2->ano && data1->mes == data2->mes)
    {
        return data2->dia - data1->dia;
    }

    dias += totaDiasNoMes(data1->mes, data1->ano) - data1->dia;

    for (int mes = data1->mes + 1; mes <= 12; mes++)
    {
        dias += totaDiasNoMes(mes, data1->ano);
    }

    // Um ano antes da data 2:
    for (int ano = data1->ano + 1; ano < data2->ano; ano++)
    {
        dias += bis(ano) ? 366 : 365;
    }

    for (int mes = 1; mes < data2->mes; mes++)
    {
        dias += totaDiasNoMes(mes, data2->ano);
    }

    dias += data2->dia;

    return dias;
}

int main()
{
    setlocale(LC_ALL, "");
    struct Data datas[2];
    char repetir;

    do
    {
        printf("Digite a primeira data (Formato: dia mês ano): ");
        scanf("%d %d %d", &datas[0].dia, &datas[0].mes, &datas[0].ano);

        printf("Digite a segunda data (Formato: dia mês ano): ");
        scanf("%d %d %d", &datas[1].dia, &datas[1].mes, &datas[1].ano);

        int diasEntreAsDuas = calcularTotalDias(&datas[0], &datas[1]);
        printf("O número da diferença entre os dias das duas datas é de: %d dias\n", diasEntreAsDuas);

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);
        getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;
}
#endif // ex6
