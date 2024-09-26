#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define ex1

//1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
//dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
//data (dia, mes e ano) atual.

#ifdef ex1
int main() {
    setlocale(LC_ALL, "");
    char choice;
    do {
        int dianasc, mesnasc, anonasc, diatual, mesatual, anoatual, anos, meses, dias;
        printf("Digite a data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &dianasc, &mesnasc, &anonasc);
        printf("Digite a data de hoje (dia mes ano): ");
        scanf("%d %d %d", &diatual, &mesatual, &anoatual);
        system("cls");
        anos = anoatual - anonasc;
        meses = mesatual - mesnasc;
        dias = diatual - dianasc;
        system("cls");
        if ((anos < 0) || ((anos == 0) && (meses < 0)) || ((anos == 0) && (meses == 0) && (dias < 0))) {
            printf("\nData Inv�lida\n");
        } else {
            if (meses < 0) {
                anos = anos - 1;
                meses = meses + 12;
            }
            if (dias < 0) {
                if (meses > 0)
                    meses = meses - 1;
                else
                    anos = anos - 1;
                switch (mesnasc) {
                    case 2:
                        if (anoatual % 4 == 0)
                            dias = dias + 29;  // ano bis
                        else
                            dias = dias + 28;
                        break;
                    case 4: case 6: case 9: case 11:
                        dias = dias + 30;
                        break;
                    default:
                        dias = dias + 31; // m�s com 31 dias
                        break;
                }
            }
            printf("\nIdade = %d anos, %d meses e %d dias\n", anos, meses, dias);
        }
        printf("Deseja calcular outra data? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex1
////////////////////////////////////////////////////////////////////////////////////////////////////

//2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
// Determine o dia da semana desta data.

#ifdef ex2
int main() {
    setlocale(LC_ALL, "");
    char choice;
    do {
        int Dia, Mes, Ano, DiasDoAno, Dias31, AnosBiss;
        long int Anos, NumDias;
        printf("Digite: Dia, M�s e Ano: \n");
        scanf("%d %d %d", &Dia, &Mes, &Ano);
        Anos = Ano - 1600;
        // N�mero de meses com 31 dias
        if (Mes < 9)
            Dias31 = Mes / 2;
        else
            Dias31 = (Mes + 1) / 2;
        // Fevereiro como 30 dias, ano bis
        DiasDoAno = 30 * (Mes - 1) + Dia + Dias31;
        if (Mes >= 2) {
            if ((Ano % 4 != 0) || ((Ano % 100 == 0) && (Ano % 400 != 0)))
                DiasDoAno = DiasDoAno - 2;
            else
                DiasDoAno = DiasDoAno - 1;
        }
        // N�mero de anos bissextos entre o ano dado e 1600
        AnosBiss = Ano / 4 - 400 - (Ano / 100 - 16) + (Ano / 400 - 4) + 1;
        // N�mero de dias entre a data dada e 01/01/1600
        if (Ano == 1600)
            NumDias = DiasDoAno;
        else
            NumDias = Anos * 365 + DiasDoAno + AnosBiss;
        switch (NumDias % 7) {
            case 1: printf("\nDia da semana: S�bado.\n"); break;
            case 2: printf("\nDia da semana: Domingo.\n"); break;
            case 3: printf("\nDia da semana: Segunda.\n"); break;
            case 4: printf("\nDia da semana: Ter�a.\n"); break;
            case 5: printf("\nDia da semana: Quarta.\n"); break;
            case 6: printf("\nDia da semana: Quinta.\n"); break;
            case 0: printf("\nDia da semana: Sexta.\n"); break;
        }
        printf("Deseja calcular outra data? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex2
////////////////////////////////////////////////////////////////////////////////////

//3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//video no formato decimal e hexadecimal.

#ifdef ex3
//%x	Exibe um n�mero em hexadecimal com letras min�sculas.
//%X	Exibe um n�mero em hexadecimal com letras mai�sculas.
int main() {
    setlocale(LC_ALL, "");
    char choice;
    do {
        int num1, num2;
        printf("Digite um n�mero: ");
        scanf("%d", &num1);
        printf("\nDigite outro n�mero: ");
        scanf("%d", &num2);
        printf("\nAND\nDecimal: %d\nHexadecimal: %x", num1 & num2, num1 & num2);
        printf("\n\nOU\nDecimal: %d\nHexadecimal: %x", num1 | num2, num1 | num2);
        printf("\n\nOU EXCLUSIVO\nDecimal: %d\nHexadecimal: %x", num1 ^ num2, num1 ^ num2);
        printf("\n");
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
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
    char choice;
    do {
        int num1, num2;
        printf("Digite um n�mero: ");
        scanf("%d", &num1);
        printf("\nDigite outro n�mero: ");
        scanf("%d", &num2);
        printf("\nAdi��o: %d\nSubtra��o: %d\nMultiplica��o: %d\nDivis�o: %.2f\n",
        num1 + num2, num1 - num2, num1 * num2, (float)num1 / num2);
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex4

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//5 - Reescreva o exercicio anterior utilizando operadores de atribuicao composta.

#ifdef ex5
// &= opera��o AND e atribui��o.
// ^=  opera��o OU EXCLUSIVO e atribui��o.
// |=  operac��o OU e atribui��o.

 int main() {
    setlocale(LC_ALL, "");
    char choice;
    do {
        int num1, num2, aux;
        printf("Digite um numero: ");
        scanf("%d", &num1);
        printf("\nDigite outro numero: ");
        scanf("%d", &num2);
        aux = num1;
        num1 &= num2;
        printf("\nAND\nDecimal: %d\nHexadecimal: %x", num1, num1);
        num1 = aux;
        num1 |= num2;
        printf("\n\nOU\nDecimal: %d\nHexadecimal: %x", num1, num1);
        num1 = aux;
        num1 ^= num2;
        printf("\n\nOU EXCLUSIVO\nDecimal: %d\nHexadecimal: %x", num1, num1);
        printf("\n\nDeseja continuar? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex5
/////////////////////////////////////////////////////////

#ifdef ex6
//exerc�cio 5, por�m feito de outra forma, que n�o consegui deixar redondinho.
main()
{
    setlocale(LC_ALL, "");

    char c;

    do{

    int A,B,C;

    system("cls\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%d",&A);
    C = A;
    printf("Digite o segundo n�mero: ");
    scanf("%d",&B);

    printf("A += B = %d\n",A += B);
    A = C;
    printf("A -= B = %d\n",A -= B);
    A = C;
    printf("A *= B = %d\n",A *= B);
    A = C;
    if(B==0)
    {
        printf("N�o se divide um n�mero por zero. \n");
    }
        else
        {
            printf("A /= B = %d\n",A /= B);
        }
    do{
        printf("Digite sim para continuar ou n�o para sair. \n");
        c = getche();
        c = tolower(c);
        printf("\n");
    }while((c!='s')&&(c!='n'));

    }while(c=='s');
}
#endif // ex6
/////////////////////////////////////////////////////////////////////
