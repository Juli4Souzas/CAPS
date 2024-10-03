#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/* Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6. */


int fatorial(int n) {
    int res = 1;

    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    printf("4! = %d\n", res);
    return res;
}

int somaA(int res) {
    int soma = 0;
    while (res > 0) {
        soma += res % 10;
        res /= 10;
    }
    return soma;
}

int main() {
    int N;

    setlocale(LC_ALL, "");
    printf("Digite um número: ");
    scanf("%d", &N);

    int fat = fatorial(N);
    int soma = somaA(fat);

    printf("Soma dos algarismos: %d\n", N, soma);

    return 0;
}

#endif // ex1

#ifdef ex2
/* Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles. */

#endif // ex2

#ifdef ex3
/* Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/

    int soma(int n1, int n2){
        int res;
        res = n1 + n2;
        return res;
    }

    int sub(int n1, int n2){
        int res;
        res = n1 - n2;
        return res;
    }

    int mult(int n1, int n2){
        int res;
        res = n1 * n2;
        return res;
    }

    int div(int n1, int n2){
        int res;
        res = n1 / n2;
    }
        return res;


    main(){
        int n1, n2;
        setlocale(LC_ALL, "");

        printf("Digite o primeiro número: ");
        scanf("%d", &n1);
        printf("Digite o segundo número: ");
        scanf("%d", &n2);

        int resSoma = soma(n1, n2);
        printf("\nSoma: %d\n", resSoma);

        int resSub = sub(n1, n2);
        printf("Subtração: %d\n", resSub);

        int resMult = mult(n1, n2);
        printf("Multiplicação: %d\n", resMult);

        int resDiv = div(n1, n2);
        printf("Divisão: %d\n", resDiv);
    }

#endif // ex3


#ifdef ex4
/* Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente. */



#endif // ex4


#ifdef ex5
/* Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main(). */



#endif // ex5
