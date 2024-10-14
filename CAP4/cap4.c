#define ex4
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/* Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que são digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/

int main()
{
    setlocale(LC_ALL, "");
    char repetir;
    do
    {
        int n[10], i, j, num, posicao;

        for(i = 0; i < 10; i++)
        {
            printf("\nDigite o %dº número: ", i + 1);
            scanf("%d", &num);
            n[i] = num;

            for (j = i; j > 0 && n[j] < n[j - 1]; j--)
            {
                posicao = n[j];
                n[j] = n[j - 1];
                n[j - 1] = posicao;
            }

            printf("Ordem: ");
            for (j = 0; j <= i; j++)
            {
                printf("%d ", n[j]);
            }
            printf("\n");
        }

        printf("\nNúmeros ordenados: ");
        for (i = 0; i < 10; i++)
        {
            printf("%d ", n[i]);
        }
        printf("\n");

        printf("\nDigite 1 para repetir o cálculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}

#endif

#ifdef ex2
/*Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/
int main()
{
    char repetir;
    do
    {
        int i, vints[3];
        long vlongs[3];
        unsigned vunsigneds[3];
        float vfloats[3];
        double vdoubles[3];
        setlocale(LC_ALL, "");

        printf("\nDigite os valores inteiros (int):\n");
        for (i = 0; i < 3; i++)
        {
            printf("%d° int: ", i+1);
            scanf("%d", &vints[i]);
        }

        printf("\nDigite os valores long:\n");
        for (i = 0; i < 3; i++)
        {
            printf("%d° long: ", i+1);
            scanf("%ld", &vlongs[i]);
        }

        printf("\nDigite os valores unsigned:\n");
        for (i = 0; i < 3; i++)
        {
            printf("%d° unsigned: ", i+1);
            scanf("%u", &vunsigneds[i]);
        }

        printf("\nDigite os valores float:\n");
        for (i = 0; i < 3; i++)
        {
            printf("%d° float: ", i+1);
            scanf("%f", &vfloats[i]);
        }

        printf("\nDigite os valores double:\n");
        for (i = 0; i < 3; i++)
        {
            printf("%d° double: ", i+1);
            scanf("%lf", &vdoubles[i]);
        }

        printf("\n");
        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        for (i = 0; i < 3; i++)
        {

            printf("%3d%20ld%20u\n",vints[i], vlongs[i], vunsigneds[i]);
            printf("%16.2f%20.2lf\n",vfloats[i], vdoubles[i]);
        }

        printf("\nDigite 1 para repetir o cálculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}

#endif // ex2

#ifdef ex3
/*Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/


int main()
{
    char repetir;
    do
    {
        setlocale(LC_ALL, "");
        int v[10], u[5], w[5];
        int i, impar = 0, par = 0;

        printf("\nDigite 10 números inteiros:\n");
        for (i = 0; i < 10; i++)
        {
            printf("%d° número: ", i + 1);
            scanf("%d", &v[i]);
        }

        for (i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
                u[par] = v[i];
                par++;
            }
            else
            {
                w[impar] = v[i];
                impar++;
            }
        }

        printf("\n---- Números nas posições pares ----");
        for (i = 0; i < par; i++)
        {
            printf("\nPosição %d: %d", i * 2, u[i]);
        }

        printf("\n\n---- Números nas posições ímpares ----");
        for (i = 0; i < impar; i++)
        {
            printf("\nPosição %d: %d", i * 2 + 1, w[i]);
        }


        printf("\n\nDigite 1 para repetir o cálculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}


#endif // ex3

#ifdef ex4
/*Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.*/

int main()
{
    char repetir;
    do
    {
        int v[10], u[10], w[10];
        int i, impar = 0, par = 0;
        setlocale(LC_ALL, "");

        printf("\nDigite 10 números inteiros:\n");
        for (i = 0; i < 10; i++)
        {
            printf("%d° número: ", i+1);
            scanf("%d", &v[i]);
        }

        for (i = 0; i < 10; i++)
        {
            if (v[i] % 2 == 0)
            {
                w[par] = v[i];
                par++;
            }
            else
            {
                u[impar] = v[i];
                impar++;
            }
        }

        if (impar > 0)
        {
            printf("\nNúmeros ímpares: ");
            for (i = 0; i < impar; i++)
            {
                printf("%d ", u[i]);
            }
        }
        else
        {
            printf("\nNenhum número ímpar foi digitado.");
        }

        if (par > 0)
        {
            printf("\nNúmeros pares: ");
            for (i = 0; i < par; i++)
            {
                printf("%d ", w[i]);
            }
        }
        else
        {
            printf("\nNenhum número par foi digitado.");
        }

        printf("\n");

        printf("\nDigite 1 para repetir o cálculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");
    return 0;
}

#endif // ex4

#ifdef ex5
/*Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/

int main()
{
    char repetir;
    do
    {
        int vet1[2][3], vet2[2][3];
        int res[6];
        setlocale(LC_ALL, "");

        printf("\nDigite os números do primeiro vetor, para realizar a soma:\n");
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%d° número [Linha %d][ Coluna %d]: ", i + 1, i, j);
                scanf("%d", &vet1[i][j]);
            }
        }

        printf("\nDigite os números do segundo vetor, para realizar a soma:\n");
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%d° número [Linha %d][ Coluna %d]: ", i + 1, i, j);
                scanf("%d", &vet2[i][j]);
            }
        }

        int k = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                res[k] = vet1[i][j] + vet2[i][j];
                k++;
            }
        }

        printf("\n---- Resultados ----\n");
        printf("Índice | soma\n");
        printf("(Ordem: índice --> vetor 1 + vetor 2 --> soma)\n");
        k = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("[%d][%d] | %d + %d = %d\n", i, j, vet1[i][j], vet2[i][j], res[k]);
                k++;
            }
        }
    printf("\nDigite 1 para repetir o cálculo, e qualquer tecla para encerrar: ");
        scanf(" %c", &repetir);

    }
    while (repetir == '1');

    printf("\nSair.\n");2

    return 0;
}


#endif // ex5
