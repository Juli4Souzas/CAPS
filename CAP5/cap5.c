#include <stdio.h>
#include <locale.h>


#define ex5
#ifdef ex1
/* Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)*/

char palavra1[11];
char palavra2[11];

int retorno()
{
    int i = 0;

    while (palavra1[i] != '\0' && palavra2[i] != '\0')
    {
        if (palavra1[i] != palavra2[i])
        {
            return 0;
        }
        i++;
    }

    return (palavra1[i] == palavra2[i]) ? 1 : 0;
}

int main()
{
    char repetir;
    do
    {
        int res;
        setlocale(LC_ALL,"");
        printf("Digite a primeira palavra vom no máximo 10 caracteres: ");
        scanf("%s", palavra1);

        printf("Digite a segunda string (máx. 10 caracteres): ");
        scanf("%s", palavra2);

        res = retorno();

        if (res == 1)
        {
            printf("As palavras são iguais.\n");
        }
        else
        {
            printf("As palavras são diferentes.\n");
        }
        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("sair");
    return 0;
}


#endif // ex1

#ifdef ex2
/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3*/
char nome1[8], nome2[8], nome3[8],nome4[8], nome5[8];

int main() {
setlocale(LC_ALL, "");
char repetir;
do{

    printf("Digite o 1° nome com no máximo 7 caracteres: ");
    scanf("%s", nome1);

    printf("Digite o 2° nome com no máximo 7 caracteres: ");
    scanf("%s", nome2);

    printf("Digite o 3° nome com no máximo 7 caracteres: ");
    scanf("%s", nome3);

    printf("Digite o 4° nome com no máximo 7 caracteres: ");
    scanf("%s", nome4);

    printf("Digite o 5° nome com no máximo 7 caracteres: ");
    scanf("%s", nome5);

    printf("\n");
    printf("            10        20        30        40        50 \n");
    printf("    12345678901234567890123456789012345678901234567890\n");

    printf("      %s",nome1);
    printf("                                   %s\n",nome5);
    printf("                %s", nome2);
    printf("               %s\n", nome4);
    printf("                          %s\n", nome3);

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("sair");
    return 0;
}

#endif // ex2

#ifdef ex3

/*Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/


#include <stdio.h>
#include <locale.h>

char palavra[100];

int medir() {
    int tamanho = 0;
    while (palavra[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

int main() {
    char repetir;
    setlocale(LC_ALL,"");

    do {
        int comp;
        do {
            printf("Digite uma palavra com no máximo 99 caracteres: ");
            scanf("%s", palavra);

            comp = medir();

            if (comp > 99) {
                printf("A palavra tem mais de 99 caracteres! Tente novamente.\n");
            }

        } while (comp > 99);

        printf("\nO comprimento da palavra é: %d\n", comprimento);

        printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    } while (repetir == '1');

    printf("Sair\n");
    return 0;
}


#endif // ex3


#ifdef ex4

/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca)*/



int main() {
    setlocale(LC_ALL, "");
    char repetir;
    do{
    char palavra[11];
    int i=0, tamanho;

    do {
        printf("\nDigite uma palavra de até 10 caracteres: ");
        scanf("%s", palavra);
        tamanho = 0;

        while (palavra[tamanho] != '\0') {
            tamanho++;
        }

        if (tamanho > 10) {
            printf("Erro: A palavra contém mais de 10 caracteres. Tente novamente.\n");
        }

    } while (tamanho > 10);

    for (i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            palavra[i] -= 32;
        }
    }

    printf("Palavra em letras maiúsculas: %s\n", palavra);

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
    scanf(" %c", &repetir);

    } while (repetir == '1');

    printf("Sair\n");
    return 0;
}


#endif // ex4


#ifdef ex5

/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)*/


int main() {
    setlocale(LC_ALL, "");
    char repetir;
    do{
    char palavra[11];
    int i=0, tamanho;

    do {
        printf("\nDigite uma palavra de até 10 caracteres: ");
        scanf("%s", palavra);

        tamanho = 0;
        while (palavra[tamanho] != '\0') {
            tamanho++;
        }

        if (tamanho > 10) {
            printf("Erro: A palavra contém mais de 10 caracteres. Tente novamente.\n");
        }

    } while (tamanho > 10);


    for (i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
            palavra[i] += 32;
        }
    }

    printf("Palavra convertida para minúsculas: %s\n", palavra);

    printf("\nDigite 1 para repetir o programa, e qualquer tecla para encerrar: ");
    scanf(" %c", &repetir);

    } while (repetir == '1');

    printf("Sair\n");
    return 0;
}


#endif // ex5
