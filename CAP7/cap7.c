#include <stdio.h>
#include <locale.h>

#define ex4

#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

struct variaveis{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

struct variaveis valor;

receber(){

    printf("\nDigite um valor char: ");
    scanf("%c", &valor.c);
    printf("Digite um valor int: ");
    scanf("%d", &valor.i);
    printf("Digite um valor long: ");
    scanf("%ld", &valor.l);
    printf("Digite um valor float: ");
    scanf("%f", &valor.f);
    printf("Digite um valor double: ");
    scanf("%lf", &valor.d);
    printf("Digite um valor unsigned char: ");
    scanf("%u", &valor.uc);
    printf("Digite um valor unsigned int: ");
    scanf("%u", &valor.ui);
    printf("Digite um valor unsigned long: ");
    scanf("%lu", &valor.ul);
}

main()
{
    char repetir;
    do{
       receber();
       printf("\n        10        20        30        40        50        60        70\n");
       printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
       printf("    %-2c        %-6d    %-11d         %-10.2f          %-10.2lf\n",valor.c,valor.i,valor.l,valor.f,valor.d);
       printf("          %-2u                  %-5u               %-10ld\n",valor.uc,valor.ui,valor.ul);


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
/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Fa a um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep*/

struct dados{
    char nome;
    char end;
    char cidade;
    char estado;
    char cep;
};

#endif // ex2

#ifdef ex3
/*3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano*/

struct data{
    int dia;
    int mes;
    int ano;
};


struct data d[2];


int calcularDias() {
    int resAno, dias;
    /*for (int i = 0; i < 2; i++) {
            printf("\nData %d: %d / %d / %d", i+1, d[i].dia, d[i].mes, d[i].ano);
        }*/

    if(d[0].ano>d[1].ano){
        resAno= d[0].ano - d[1].ano;
    }
    else if(d[1].ano>d[0].ano){
        resAno= d[1].ano - d[0].ano;
    }
    else{
        resAno=0;
    }


    dias=resAno*365;
    return dias;
}


main()
{
    char repetir;
    do{
       setlocale(LC_ALL, "");

       for(int i=0; i<2; i++){
            printf("\nDigite a %d° data (dia mês ano): ", i+1);
            scanf("%d %d %d", &d[i].dia, &d[i].mes, &d[i].ano);
       }

       int diferenca = calcularDias();
       printf("\nDiferença de dias entre as datas: %d dias\n", diferenca);

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
/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura*/



#endif // ex4
