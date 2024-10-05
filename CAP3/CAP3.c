#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/* Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e� 2 + 4 = 6. */


int fatorial(int n)
{
    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

int somaA(int res)
{
    int soma = 0;
    while (res > 0)
    {
        soma += res % 10;
        res /= 10;
    }
    return soma;
}

int main()
{
    char repetir;
    do
    {
        int N;

        setlocale(LC_ALL, "");
        printf("\nDigite um n�mero: ");
        scanf("%d", &N);

        int fat = fatorial(N);
        int soma = somaA(fat);

        printf("Fatorial de %d! = %d\n", N, fat);
        printf("Soma dos algarismos de %d! = %d\n", N, soma);

        printf("\nDigite 1 para repetir o c�lculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;
}

#endif // ex1

#ifdef ex2
/* Escreva um programa que receba dois numeros inteiros e execute as seguintes
    fun�oes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles. */

int returnn(int num) {
    if (num > 0)
        return 1;
    else if (num < 0)
        return 0;
    else
        return -1;
}


int soma(int num1, int num2) {
    int soma;
    soma=num1+num2;
    return soma;
}

int mult(int num1, int num2) {
    int produto;
    produto=num1*num2;
    return produto;
}


float div(int num1, int num2) {
    float divisao;
    divisao=num1/num2;
    return divisao;
}

int main() {
    char repetir;
    setlocale(LC_ALL, "");
    do{
    int num1, num2;
    printf("\nDigite o primeiro n�mero: ");
    scanf("%d", &num1);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);

    int N1 = returnn(num1);
    int N2 = returnn(num2);

    if (N1 == 1 && N2 == 1) {
        printf("A soma dos n�meros positivos %d + %d �: %d\n", num1, num2, soma(num1, num2));
    }
    else if (N1 == 0 && N2 == 0) {
        printf("A multiplica��o dos n�meros negativos %d X %d �: %d\n", num1, num2, mult(num1, num2));
    }
    else if (N1 == 1 && N2 == 0) {
        printf("A divis�o de %d por %d �: %.1f\n", num1, num2, div(num1, num2));
    }
    else {
        printf("A divis�o de %d por %d �: %.1f\n", num2, num1, div(num2, num1));
    }
    getchar();

     printf("\nDigite 1 para repetir o c�lculo, e qualquer tecla para encerrar: ");
     scanf("%c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");

    return 0;
}

#endif // ex2

#ifdef ex3
/* Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/

int soma(int n1, int n2)
{
    int res;
    res = n1 + n2;
    return res;
}

int sub(int n1, int n2)
{
    int res;
    res = n1 - n2;
    return res;
}

int mult(int n1, int n2)
{
    int res;
    res = n1 * n2;
    return res;
}


float div(int n1, int n2) {
    float res;
    res = (float)n1 / n2;
    return res;
}

int main()
{
    char repetir;
    do
    {
        int n1, n2;
        setlocale(LC_ALL, "");

        printf("Digite o primeiro n�mero: ");
        scanf("%d", &n1);
        printf("Digite o segundo n�mero: ");
        scanf("%d", &n2);

        int resSoma = soma(n1, n2);
        printf("\nSoma: %d\n", resSoma);

        int resSub = sub(n1, n2);
        printf("Subtra��o: %d\n", resSub);

        int resMult = mult(n1, n2);
        printf("Multiplica��o: %d\n", resMult);

        float resDiv = div(n1, n2);
        printf("Divis�o: %.2f\n", resDiv);

         printf("\nDigite 1 para repetir o c�lculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}

#endif // ex3


#ifdef ex4
/* Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente. */

//Fun��es
int soma(int n1, int n2)
{
    int res;
    res = n1 + n2;
    return res;
}

int sub(int n1, int n2)
{
    int res;
    res = n1 - n2;
    return res;
}

int mult(int n1, int n2)
{
    int res;
    res = n1 * n2;
    return res;
}


float div(int n1, int n2) {
    float res;
    res = (float)n1 / n2;
    return res;
}


main() {
    char repetir;
    int n1, n2;
    setlocale(LC_ALL, "");

    do {
        printf("\nDigite um n�mero: ");
        scanf("%d",&n1);
        printf("Digite outro n�mero: ");
        scanf("%d",&n2);

        int resSoma = soma(n1, n2);
        printf("\nSoma: %d\n", resSoma);

        int resSub = sub(n1, n2);
        printf("Subtra��o: %d\n", resSub);

        int resMult = mult(n1, n2);
        printf("Multiplica��o: %d\n", resMult);

        float resDiv = div(n1, n2);
        printf("Divis�o: %.2f\n", resDiv);

        printf("\nDigite 1 para repetir o c�lculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');
    printf("\nSair.\n");
    return 0;
}




#endif // ex4


#ifdef ex5
/* Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main(). */

int soma(int n1, int n2)
{
    int res;
    res = n1 + n2;
    return res;
}

int sub(int n1, int n2)
{
    int res;
    res = n1 - n2;
    return res;
}

int mult(int n1, int n2)
{
    int res;
    res = n1 * n2;
    return res;
}

float div(int n1, int n2) {
    float res;
    res = (float)n1 / n2;
    return res;
}

int main() {
    setlocale(LC_ALL, "");
    int n1, n2, operacao;
    char repetir;
    float res;

    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);
    res = n1;


    do {
        printf("Digite o pr�ximo valor: ");
        scanf("%d", &n2);

        printf("\n----- Escolha a opera��o -----\n1 - soma\n2 - subtra��o\n3 - multiplica��o\n4 - divis�o\n");
        printf("\nOpera��o: ");
        scanf(" %d", &operacao);



        switch (operacao) {
            case 1:
                res = soma(res, n2);
                break;
            case 2:
                res = sub(res, n2);
                break;
            case 3:
                res = mult(res, n2);
                break;
            case 4:
                res = div(res, n2);

                break;
            default:
                printf("Op��o inv�lida.\n");
                continue;
        }

        printf("\nResultado: %.2f\n", res);
        printf("\nDeseja continuar a opera��o com outro n�mero? (1 = sim): ");
        scanf(" %c", &repetir);

    } while (repetir == '1');

    printf("\nResultado final: %.2f\n", res);
    return 0;
}
#endif // ex5
