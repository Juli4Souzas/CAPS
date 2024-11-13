#include <stdio.h>
#include <locale.h>

#define ex4

#ifdef ex3

struct Data {
    int dia;
    int mes;
    int ano;
};

// ANO BIS?
int bis(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// DIAS EM UM MÊS
int totalDiasMes(int mes, int ano) {
    if (mes == 2) {
        return bis(ano) ? 29 : 28;
    }
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : 31;
}

// DIFERENÇA DE DIAS ENTRE AS DUAS DATAS:
int calculoDeDif(struct Data primeira, struct Data segunda) {
    int dias = 0;

    // PRA NÃO DAR DATA NEGATIVA, COLOCA A DATA MAIOR ANTES DA MENOR (NO CÁLCULO):
    if (primeira.ano > segunda.ano ||
        (primeira.ano == segunda.ano && primeira.mes > segunda.mes) ||
        (primeira.ano == segunda.ano && primeira.mes == segunda.mes && primeira.dia > segunda.dia)) {
        struct Data temp = primeira;
        primeira = segunda;
        segunda = temp;
    }

    // DIAS ENTRE ELAS:
    while (primeira.ano < segunda.ano ||
           (primeira.ano == segunda.ano && segunda.mes < segunda.mes) ||
           (primeira.ano == segunda.ano && primeira.mes == segunda.mes && primeira.dia < segunda.dia)) {

        dias++;
        primeira.dia++;

        // DIA > DIAS NO MÊS?
        if (primeira.dia > totalDiasMes(primeira.mes, primeira.ano)) {
            primeira.dia = 1;
            primeira.mes++;
        }

        // MÊS > 12?
        if (primeira.mes > 12) {
            primeira.mes = 1;
            primeira.ano++;
        }
    }

    return dias;
}

int main() {
    setlocale(LC_ALL, "");
    char continuar;

    do {
        struct Data datas[2];

        // RECEBER AS DATAS:
        for (int i = 0; i < 2; i++) {
            printf("Digite uma DATA (dia mês ano): ", i + 1);
            scanf("%d %d %d", &datas[i].dia, &datas[i].mes, &datas[i].ano);
        }

        // DIFERENÇA DOS DIAS:
        int diasEntre = calculoDeDif(datas[0], datas[1]);

        printf("Número de diferença de dias entre as duas datas digitadas: %d\n", diasEntre);

        printf("Deseja continuar e calcular outra data? (Digite: s para sim / n para não): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Finalizado! Digite qualquer tecla para sair. \n");
    return 0;
}


#endif // ex3

///////////////////////////////////////////////////////////////////////////////////////////////

#ifdef ex4

#define MAX_PESSOAS 4

// ARMAZENA DADOS:
struct Pessoa {
    char nome[50];
    float peso;
    float altura;
};

int main() {
    setlocale(LC_ALL, "");
    struct Pessoa pessoas[MAX_PESSOAS];
    int contador = 0;
    int opcao;

    do {
        printf("\n ********MENU: ********\n");
        printf("1 - RECEBER DADOS: \n");
        printf("2 - IMPRIMIR DADOS: \n");
        printf("3 - CALCULAR O IMC DAS 4 PESSOAS: \n");
        printf("4 - FINALIZAR: \n");
        printf("ESCOLHA UMA OPÇÃO: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // RRECEBE DADOS:
            for (contador = 0; contador < MAX_PESSOAS; contador++) {
                printf("Digite o nome da pessoa %d: ", contador + 1);
                scanf("%s", &pessoas[contador].nome);
                printf("Digite o peso da pessoa %d (em kg, coloque vírgula): ", contador + 1);
                scanf("%f", &pessoas[contador].peso);
                printf("Digite a altura da pessoa %d (em metros, coloque vírgula): ", contador + 1);
                scanf("%f", &pessoas[contador].altura);
            }
        }
        else if (opcao == 2) {
            // IMPRIMI DADOS:
            for (int i = 0; i < MAX_PESSOAS; i++) {
                printf("\nPessoa %d:\n", i + 1);
                printf("Nome: %s\n", pessoas[i].nome);
                printf("Peso: %.2f kg\n", pessoas[i].peso);
                printf("Altura: %.2f m\n", pessoas[i].altura);
            }
        }
        else if (opcao == 3) {
            // IMC:
            for (int i = 0; i < MAX_PESSOAS; i++) {
                float imc = pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura);
                printf("IMC de %s: %.2f\n", pessoas[i].nome, imc);
            }
            char continuar;
            printf("Deseja continuar ou sair? (Digite s para sim ou n para sair): ");
            scanf(" %c", &continuar);
            if (continuar == 's' || continuar == 'S') {
                opcao = 4;
            }
        }
        else if (opcao == 4) {
            printf("Finalizando! Aperte qualquer tecla. \n");
        }
        else {
            printf("Inválido! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
#endif // ex4

/////////////////////////////////////////////////////////////////////////////
