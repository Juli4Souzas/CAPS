#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_LEN 10

#define ex5

////////////////////////////////////////////////////////////////////////////
//1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Fa�a uma
//funcao para compara-las e retorne como resultado se s�o IGUAIS 1 ou se
//DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
//Declare os vetores como variavel global (nao pode usar funcao de biblioteca).

#ifdef ex1

char str1[MAX_LEN + 1];
char str2[MAX_LEN + 1];
//comparar as duas strings:
int compararStrings() {
    for (int i = 0; i < MAX_LEN; i++) {
        if (str1[i] == '\0' && str2[i] == '\0') {
        return 1; // Iguais
        }
        if (str1[i] != str2[i]) {
            return 0; // Diferentes
        }
    }
    // Se for maior que a outra
    if (str1[MAX_LEN] != '\0' || str2[MAX_LEN] != '\0') {
        return 0; // S�o diferentes
    }
    return 1; // S�o iguais
}
int main() {
    setlocale (LC_ALL, "");
    char continuar;
    do {
        printf("Digite a primeira string (at� 10 caracteres): ");
        fgets(str1, sizeof(str1), stdin);
        for (int i = 0; i < MAX_LEN; i++) {
            if (str1[i] == '\n') {
                str1[i] = '\0';
                break;
            }
        }
        printf("Digite a segunda string (at� 10 caracteres): ");
        fgets(str2, sizeof(str2), stdin);
        for (int i = 0; i < MAX_LEN; i++) {
            if (str2[i] == '\n') {
                str2[i] = '\0';
                break;
            }
        }
        int resultado = compararStrings();
        if (resultado == 1) {
            printf("As strings s�o IGUAIS.\n");
        } else {
            printf("As strings s�o DIFERENTES.\n");
        }
        printf("Deseja Continuar? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');
    printf("Programa finalizado.\n");
    return 0;
}
#endif

////////////////////////////////////////////////////////////////////////

//2 - Escreva um programa para receber 5 nomes, com at� 7 caracteres, via teclado
//e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
// globais)
//            10        20        30        40        50
//   12345678901234567890123456789012345678901234567890
//      nome1                                   nome5
//               nome2               nome4
//                          nome3

#ifdef ex2

#define MAX_NOME 8 // 7 caracteres + 1 para o nulo
#define NUM_NOMES 5

char nomes[NUM_NOMES][MAX_NOME];
void imprimirNomes() {
    printf("           10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-40s\n", nomes[0]); // nome 1
    printf("                %-20s%-20s\n", nomes[1], nomes[3]); // nome 2 e nome 4
    printf("                          %-20s\n", nomes[2]); // nome 3
}
int main() {
    setlocale(LC_ALL, "");
    char continuar;
    do {
            for (int i = 0; i < NUM_NOMES; i++) {
            printf("Digite o nome %d (at� 7 caracteres): ", i + 1);
            fgets(nomes[i], sizeof(nomes[i]), stdin);
            for (int j = 0; j < MAX_NOME; j++) {
                if (nomes[i][j] == '\n') {
                    nomes[i][j] = '\0';
                    break;
                }
            }
        }
        imprimirNomes();
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex2
//////////////////////////////////////////////////////////////////////////////

//3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
//calcula o comprimento de uma string recebida via teclado. Mostre o valor do
//comprimento na funcao main().
//(Declare o vetor como variavel global). (nao pode usar funcao de biblioteca).

#ifdef ex3
int tamanhostr(char str[]) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}
int main() {
    setlocale(LC_ALL, "");
    char vet[] = {"dale porco"};
    char choice;
    printf("strlen: %lu\n", strlen(vet));
    printf("tamanhostrlen: %d\n", tamanhostr(vet));
    do {
        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &choice);
        if (choice == 's' || choice == 'S') {
            printf("Voc� escolheu continuar.\n");
        } else if (choice == 'n' || choice == 'N') {
            printf("Voc� escolheu sair.\n");
        } else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (choice != 'n' && choice != 'N');
    return 0;
}
#endif // ex3
//////////////////////////////////////////////////////////////////////////////

//4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
//para letras maiusculas. (nao pode usar funcao de biblioteca).
// 'A' == 65 ascii
        // 'a' == 97 ascii
        // 97 - 65 = 32 (para deixar do tamanho calcular o ascii do mai�sculo
#ifdef ex4
int main() {
    setlocale (LC_ALL, "");
    char texto[11]; // 10 caracteres + 1 nulo
    char choice;
    do {
        printf("Digite uma palavra (at� 10 caracteres): ");
        fgets(texto, sizeof(texto), stdin);
        // Convertendo para mai�sculas
        for (int i = 0; texto[i] != '\0'; i++) {
            // Verifica se � letra min�scula
            if (texto[i] >= 'a' && texto[i] <= 'z') {
                texto[i] = texto[i] - 32; // Converte para mai�scula
            }
        }
        printf("Todas as letras em mai�sculas: %s\n", texto);
        printf("Deseja finalizar o programa? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 's' && choice != 'S');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex4
/////////////////////////////////////////////////////////////////////////////////

//5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
//para letras minusculas. (nao pode usar funcao de biblioteca).
// 'A' == 65 ascii
// 'a' == 97 ascii
// 97 - 65 = + 32 (para deixar do tamanho calcular o ascii do min�sculo.

#ifdef ex5
int main() {
    setlocale (LC_ALL, "");
    char texto[11]; // 10 caracteres + 1 nulo
    char choice;
    do {

        printf("Digite uma palavra (at� 10 caracteres): ");
        fgets(texto, sizeof(texto), stdin);
        // Convertendo para min�sculas
        for (int i = 0; texto[i] != '\0'; i++) {
            // Verifica se � letra mai�scula
            if (texto[i] >= 'A' && texto[i] <= 'Z') {
                texto[i] = texto[i] + 32; // Converte para min�scula
            }
        }
        printf("Tudo em letras min�sculas: %s", texto);
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &choice);
        getchar();
    } while (choice != 'n' && choice != 'N');
    printf("Programa finalizado.\n");
    return 0;
}
#endif // ex5
//////////////////////////////////////////////////////////////////////////////////////////
