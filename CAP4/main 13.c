#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define ex1

#ifdef ex1
//1 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
//que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
//ordenados:
int main () {
setlocale(LC_ALL,"portuguese");
int i, j, a, n, num[10];
printf("Digite um valor para o vetor \n");
scanf("%d", &n);
printf("Digite o número \n");
for (i = 0; i < n; ++i)
    scanf("%d", &num[i]);
for (i = 0; i < n; ++i)
{
    for (j = i + 1; j < n; ++j)
    {
        if (num[i] > num[j])
        {
            a =  num[i];
            num[i] = num[j];
            num[j] = a;
        }
   system("cls"); }
}
printf("Abaixo, os números em ordem crescente: \n");
for (i = 0; i < n; ++i)
    printf("%d\n", num[i]);
       system ("cls");
 printf("Digite qualquer tecla para sair");
}
#endif // ex1
//////////////////////////////////////////////////////////////////////////////

//2 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
//3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:
//           10        20        30        40        50
// 12345678901234567890123456789012345678901234567890
// int                 long                unsigned
//         float               double
//int                 long                unsigned
//          float               double
// int                 long                unsigned
//       float               double

#ifdef ex2

#define MAX 3

int inteiro[MAX];
float flutuante[MAX];
long longo[MAX];
double dobro[MAX];
unsigned semsinal[MAX];

int main() {
    int i;
    for(i = 0; i < MAX; i++) {
        int valor;
        printf("\nDigite um valor para INT (ou -1 para finalizar): ");
        scanf("%d", &valor);
        if (valor == -1) {
            break;
        }
        inteiro[i] = valor;
        printf("\nDigite um valor para LONG: ");
        scanf("%ld", &longo[i]);
        printf("\nDigite um valor para UNSIGNED: ");
        scanf("%u", &semsinal[i]);
        printf("\nDigite um valor para FLOAT: ");
        scanf("%f", &flutuante[i]);
        printf("\nDigite um valor para DOUBLE: ");
        scanf("%lf", &dobro[i]);
    }
    printf("\n        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    for (int j = 0; j < i; j++) {
        printf("  %d                  %ld                  %u\n", inteiro[j], longo[j], semsinal[j]);
        printf("            %.2f               %.2lf\n", flutuante[j], dobro[j]);
    }
    return 0;
}
#endif // ex2
//////////////////////////////////////////////////////////////////////////////////

//4 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
//decomponha em dois outros vetores. Um tera´ as componentes de valor impar
//e o outro tera´ as componentes de valor par.
//Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
//programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.
#ifdef ex4

int main()
{
    setlocale (LC_ALL, " ");
    int i, num[10], par[10], impar[10], x = 0, y = 0;
    printf("Digite até 10 números inteiros (digite -1 para finalizar): \n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &num[i]);
        if (num[i] == -1) {
            break;
        }
    }
    for (int j = 0; j < i; j++) {
        if (num[j] % 2 == 0) {
            par[x] = num[j];
            x++;
        } else {
            impar[y] = num[j];
            y++;
        }
    }
    system("cls");
    printf("Números pares digitados: \n");
    for (i = 0; i < x; i++) {
        printf("%d\n", par[i]);
    }
    printf("Números ímpares digitados: \n");
    for (i = 0; i < y; i++) {
        printf("%d\n", impar[i]);
    }
    system("pause");
    return 0;
}
#endif // ex4
////////////////////////////////////////////////////////////////////////////////////////////

//3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
//decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
//e o outro tera´ as componentes de ordem par.
// Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
//deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.

#ifdef ex3

#define TAMANHO 10
#define MAX_IMPAR 5
#define MAX_PAR 5
int main() {
    setlocale(LC_ALL,"");
    int v[TAMANHO];
    int u[MAX_IMPAR];
    int w[MAX_PAR];
    char continuar;
    do {
        int i, imparIndex = 0, parIndex = 0;
        printf("Digite 10 inteiros:\n");
        for (i = 0; i < TAMANHO; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &v[i]);
        }
        for (i = 0; i < TAMANHO; i++) {
            if (i % 2 == 0) { // componentes de ordem ímpar
                u[imparIndex++] = v[i];
            } else { // componentes de ordem par
                w[parIndex++] = v[i];
            }
        }
        printf("\nVetor original: ");
        for (i = 0; i < TAMANHO; i++) {
            printf("%d ", v[i]);
        }
        printf("\nVetor de ordem ímpar: ");
        for (i = 0; i < imparIndex; i++) {
            printf("%d ", u[i]);
        }
        printf("\nVetor de ordem par: ");
        for (i = 0; i < parIndex; i++) {
            printf("%d ", w[i]);
        }
        printf("\n");
        printf("Deseja executar novamente? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex3
/////////////////////////////////////////////////////////////////////////////////////////

//5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
//que recebe os dados via teclado para esses 2 vetores. Usando o operador
//adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
//resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
//dos 6 elementos dos vetores.
#ifdef ex5

int main() {
    int i, j, vet1[2][3], vet2[2][3], vetor[2][3];
    char continuar;
    do {
       for(i = 0; i < 2; i++) {
            for(j = 0; j < 3; j++) {
                printf("\nDigite um valor para VET 1[%d][%d]: ", i, j);
                scanf("%d", &vet1[i][j]);
                printf("Digite um valor para VET 2[%d][%d]: ", i, j);
                scanf("%d", &vet2[i][j]);
                vetor[i][j] = vet1[i][j] + vet2[i][j];
            }
        }
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 3; j++) {
                printf("\nVET1[%d][%d] = %d\nVET2[%d][%d] = %d\nVETR[%d][%d] = %d\n",
                       i, j, vet1[i][j], i, j, vet2[i][j], i, j, vetor[i][j]);
            }
        }
        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &continuar); // O espaço antes de %c ignora qualquer espaço em branco
        system("cls");
    } while (continuar == 's' || continuar == 'S');
    printf("Programa encerrado.\n");
    return 0;
}
#endif // ex5
///////////////////////////////////////////////////////////////////////////////////////


