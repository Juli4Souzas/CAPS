#include <stdio.h>
#include <locale.h>

#define ex1

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

    printf("Digite um valor char: ");
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
       printf("    %-1c         %-9d %-9d           %-10.1f       %-19.1lf\n",valor.c,valor.i,valor.l,valor.f,valor.d);
       //printf("%17.1f%20.1f%18c\n",f,d,c);

       printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
       scanf(" %c", &repetir);
       getchar();
    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;



}

#endif // ex1
