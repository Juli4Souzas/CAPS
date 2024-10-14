#include <stdio.h>
#include <locale.h>


#define ex5

//1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
//dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
//data (dia, mes e ano) atual.

#ifdef ex1
int bis(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    if (mes == 2) {
        return bis(ano) ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31; // Meses 1, 3, 5, 7, 8, 10, 12
}

void calcularIdade(int diaNasc, int mesNasc, int anoNasc, int diaAtual, int mesAtual, int anoAtual) {
    int anos = anoAtual - anoNasc;
    int meses = mesAtual - mesNasc;
    int dias = diaAtual - diaNasc;

    if (dias < 0) {
        meses--;
        dias += diasNoMes(mesAtual - 1, anoAtual); // Mês anterior
    }
    if (meses < 0) {
        anos--;
        meses += 12;
    }

    printf("Idade: %d anos, %d meses e %d dias.\n", anos, meses, dias);
}

int main() {
    setlocale (LC_ALL, "");
    int diaNasc, mesNasc, anoNasc;
    int diaAtual, mesAtual, anoAtual;
    char continuar;

    do {
        printf("Digite sua data de nascimento (dia mês ano): ");
        scanf("%d %d %d", &diaNasc, &mesNasc, &anoNasc);

        printf("Digite a data atual (dia mês ano): ");
        scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

        calcularIdade(diaNasc, mesNasc, anoNasc, diaAtual, mesAtual, anoAtual);

        printf("Deseja continuar? (Digite: s ou n): ");
        scanf(" %c", &continuar);
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
            printf("Entrada inválida. Deseja continuar? (Digite: s ou n): ");
            scanf(" %c", &continuar);
        }
    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex1
////////////////////////////////////////////////////////////////////////////////////////////////////

//2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
// Determine o dia da semana desta data.

#ifdef ex2
int bis(int ano) {
    setlocale(LC_ALL, "");
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int calcularDiaDaSemana(int dia, int mes, int ano) {

    if (mes < 3) {
        mes += 12;
        ano--;
    }
    int k = ano % 100;
    int j = ano / 100;
    int diaDaSemana = (dia + (13 * (mes + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    return diaDaSemana;
}

void nomeDiaDaSemana(int diaDaSemana, char diaNome[15]) {
    switch (diaDaSemana) {
        case 0:
            sprintf(diaNome, "Sábado");
            break;
        case 1:
            sprintf(diaNome, "Domingo");
            break;
        case 2:
            sprintf(diaNome, "Segunda-feira");
            break;
        case 3:
            sprintf(diaNome, "Terça-feira");
            break;
        case 4:
            sprintf(diaNome, "Quarta-feira");
            break;
        case 5:
            sprintf(diaNome, "Quinta-feira");
            break;
        case 6:
            sprintf(diaNome, "Sexta-feira");
            break;
        default:
            sprintf(diaNome, "Inválido");
            break;
    }
}

int main() {
    int dia, mes, ano;
    char continuar;
    char diaNome[15];

    do {
        printf("Digite a data (dia mês ano): ");
        scanf("%d %d %d", &dia, &mes, &ano);

        // Verifica se a data é válida
        if (mes < 1 || mes > 12 || dia < 1 || dia > 31 || (mes == 2 && dia > (bis(ano) ? 29 : 28))) {
            printf("Data inválida.\n");
        } else {
            int diaDaSemana = calcularDiaDaSemana(dia, mes, ano);
            nomeDiaDaSemana(diaDaSemana, diaNome);
            printf("Dia da semana: %s\n", diaNome);
        }

        printf("Deseja continuar? (Digite: s ou n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex2
////////////////////////////////////////////////////////////////////////////////////

//3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//video no formato decimal e hexadecimal.

#ifdef ex3
//%x	Exibe um número em hexadecimal com letras minúsculas.
//%X	Exibe um número em hexadecimal com letras maiúsculas.
int main() {
    setlocale(LC_ALL, "");
    int num1, num2;
    char continuar;

    do {
        // Números inteiros:
        printf("Digite o primeiro número inteiro: ");
        scanf("%d", &num1);
        printf("Digite o segundo número inteiro: ");
        scanf("%d", &num2);

        // Cálculo das operações bit a bit:
        int andResult = num1 & num2;
        int orResult = num1 | num2;
        int xorResult = num1 ^ num2;

        // Imprime resultados das operações;
        printf("Resultados:\n");
        printf("AND: %d (0x%X)\n", andResult, andResult);
        printf("OR: %d (0x%X)\n", orResult, orResult);
        printf("XOR: %d (0x%X)\n", xorResult, xorResult);


        printf("Deseja continuar? (Digite: s ou n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex3
//////////////////////////////////////////////////////////////////////////////////////////////

//4 - Escreva um programa que receba via teclado 2 numeros inteiros e
//imprima-os no video com o resultado das 4 operacoes aritmeticas.

#ifdef ex4
int main() {
    setlocale(LC_ALL, "");
    int num1, num2;
    char continuar;

    do {

        printf("Digite o primeiro número inteiro: ");
        scanf("%d", &num1);
        printf("Digite o segundo número inteiro: ");
        scanf("%d", &num2);

        // Cálculo das operações:
        int soma = num1 + num2;
        int subtracao = num1 - num2;
        int multiplicacao = num1 * num2;

        // Divisão por zero:
        if (num2 != 0) {
            float divisao = (float)num1 / num2;
            printf("Resultados:\n");
            printf("Soma: %d\n", soma);
            printf("Subtração: %d\n", subtracao);
            printf("Multiplicação: %d\n", multiplicacao);
            printf("Divisão: %.2f\n", divisao);
        } else {
            printf("Resultados:\n");
            printf("Soma: %d\n", soma);
            printf("Subtração: %d\n", subtracao);
            printf("Multiplicação: %d\n", multiplicacao);
            printf("Divisão: Inválida (não se divide por zero)\n");
        }

        // Pergunta ao usuário se deseja continuar
        printf("Deseja continuar? (Digite: s ou n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex4

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//5 - Reescreva o exercicio anterior utilizando operadores de atribuicao composta.

#ifdef ex5
// &= operação AND e atribuição.
// ^=  operação OU EXCLUSIVO e atribuição.
// |=  operacção OU e atribuição.

 int main() {
     setlocale (LC_ALL, "");
    int num1, num2;
    char continuar;

    do {

        printf("Digite o primeiro número inteiro: ");
        scanf("%d", &num1);
        printf("Digite o segundo número inteiro: ");
        scanf("%d", &num2);

        // Cálculo das operações aritméticas usando operadores de atribuição composta
        int soma = 0, subtracao = 0, multiplicacao = 1;
        float divisao = 0.0;

        soma += num1;  // Composta para soma
        soma += num2;

        subtracao += num1;  // Composta para subtração
        subtracao -= num2;

        multiplicacao *= num1;  // Composta para multiplicação
        multiplicacao *= num2;

        // Divisão por zero
        if (num2 != 0) {
            divisao += num1;  // Composta para divisão
            divisao /= num2;
        } else {
            printf("Divisão: Inválida (não se divide por zero)\n");
        }


        printf("Resultados:\n");
        printf("Soma: %d\n", soma);
        printf("Subtração: %d\n", subtracao);
        printf("Multiplicação: %d\n", multiplicacao);
        if (num2 != 0) {
            printf("Divisão: %.2f\n", divisao);
        }


        printf("Deseja continuar? (Digite: s ou n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex5
/////////////////////////////////////////////////////////

