#define ex2
#include <stdio.h>
#include <locale.h>


#ifdef ex1
/* 1 - Escreva um programa que permute o conte�do de duas vari�veis sem utilizar uma vari�vel auxiliar. */
main()
{
    int N1,N2;
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("Digite um n�mero para a vari�vel N1: ");
    scanf("%d",&N1);
    printf("Digite um n�mero para a vari�vel N2: ");
    scanf("%d",&N2);
    printf("\n");
    printf("Vari�veis iniciais: \nN1: %d   N2: %d \n\n", N1, N2);

    N1 = N1 + N2;
    N2 = N1 - N2;
    N1 = N1 - N2;
    printf("Vari�veis trocadas: \nN1: %d   N2: %d\n", N1, N2);
    return 0;
}

#endif // ex1

#ifdef ex2
/* Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:
             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char */

int main()
{
    short s;
    long l;
    int i;
    float f;
    double d;
    char c;

    printf("Digite um valor short: ");
    scanf("%hd", &s);
    printf("Digite um valor long: ");
    scanf("%ld", &l);
    printf("Digite um valor int: ");
    scanf("%d", &i);
    printf("Digite um valor float: ");
    scanf("%f", &f);
    printf("Digite um valor double: ");
    scanf("%lf", &d);
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
      /*printf("    %-11hd%-17ld%-11d\n", s, l, i);
    printf("          %-11f%-17lf%-11c\n", f, d, c);*/
    printf("%5d%20d%20d\n",s,l,i);
    printf("%17.1f%20.1f%18c\n",f,d,c);
}
#endif // ex2


#ifdef ex3
/*  Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s. */

main()
{
    setlocale(LC_ALL, "");
    int s, hr, min, seg;

    printf("Digite um determinado tempo em segundos: ");
    scanf("%d", &s);
    //horas
    hr = s / 3600;
    //minutos
    min = (s % 3600) / 60;
    //segundos
    seg = s % 60;

    printf("%d segundos � equivalente a %dh %dmin %ds\n", s, hr, min, seg);
    return 0;
}

#endif // ex3

#ifdef ex4

main()
{
    setlocale(LC_ALL, "");
    /* Fa�a um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro n�mero formado pelos d�gitos invertidos do n�mero lido.
    Ex:   N�meroLido = 123
        N�meroGerado = 321 */

    int num, cent, dez, uni, inver;
    printf("Digite um n�mero inteiro positivo de tr�s d�gitos: ");
    scanf("%d", &num);

    cent = num / 100;
    dez = (num % 100) / 10;
    uni = num % 10;

    inver = (uni*100) + (dez*10) + cent;
    printf("N�mero Lido: %d\n", num);
    printf("N�mero Gerado: %d\n", inver);
    return 0;

}
#endif // ex4

#ifdef ex5
main()
{
    /* Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/

    setlocale(LC_ALL, "");
    int num,limt,mult;
    printf("Digite o n�mero para encontrar o m�ltiplo: ");
    scanf("%d", &num);
    printf("Digite o limite m�nimo: ");
    scanf("%d", &limt);

    mult = (limt/num) * num;
    if (mult <= limt) {
        mult += num;
    }
    printf("O menor m�ltiplo de %d maior que %d �: %d\n", num, limt, mult);
    return 0;
}
#endif // ex5
