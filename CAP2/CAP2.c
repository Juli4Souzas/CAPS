#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/* Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else. */
main()
{
    setlocale(LC_ALL, "");
    int min = 1, max = 99, num;
    char res;

    printf("Irei adivinhar o número que você está pensando entre 1 e 99!!\n");
    printf("Regras: Digite > para maior, < para menor, = para correto \n\n");

    while (min <= max)
    {
        num = (min + max) / 2;
        printf("O número que você pensou é %d? ", num);
        scanf(" %c", &res);

        if (res == '=')
        {
            printf("O número é %d.\n", num);
            break;
        }
        else if (res == '>')
        {
            min = num + 1;
        }
        else if (res == '<')
        {
            max = num - 1;
        }
        else
        {
            printf("Resposta inválida. Por favor, digite apenas >, < ou =.\n");
        }
    }

    return 0;

}
#endif // ex1

#ifdef ex2
/* Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video. */



int main()
{
    setlocale(LC_ALL, "");
    int min = 1, max = 99, num, tent = 0;
    char res;

    printf("Irei adivinhar o número que você está pensando entre 1 e 99!!\n");
    printf("Regras: Digite > para maior, < para menor, = para correto \n\n");

    while (min <= max)
    {
        tent++;
        num = (min + max) / 2;
        printf("O número que você pensou é %d? ", num);
        scanf(" %c", &res);

        switch (res)
        {
            case '=':
                printf("O número é %d.\n", num);
                printf("Número de tentativas: %d\n", tent);
                return 0;

            case '>':
                min = num + 1;
                break;

            case '<':
                max = num - 1;
                break;

            default:
                printf("Resposta inválida. Por favor, digite apenas >, < ou =.\n");
                tent--;
                break;
        }
    }

    return 0;
}

#endif // ex2

#ifdef ex3
/* Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados. */

main(){
    int n, soma=0, cont=0;
    float media;

    setlocale (LC_ALL, "");
    printf("Digite números positivo para a realização da média\n\n");
     do{
         printf("número: ");
         scanf("%d", & n);

         if(n>=0){
            soma += n;
            cont ++;
         }
     }while(n>=0);

      if (cont>0)
    {
        media = soma/cont;
        printf("A média é: %.2f\n", media);
    }
    else
    {
        printf("Não foram digitados números positivos.\n");
    }

    return 0;
}

#endif // ex3

#ifdef ex4
/* Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico! */

main(){
    float dist, litros, cons;

    setlocale(LC_ALL, "");

    printf("Digite a distância percorrida (em km): ");
    scanf("%f", &dist);
    printf("Digite a quantidade de litros de gasolina consumidos: ");
    scanf("%f", &litros);

    cons = dist / litros;

    if (cons <8){
        printf("Venda o carro!\n");
    }
    else if (cons >=8 && cons <=14){
        printf("Econômico!\n");
    }
    else{
        printf("Super econômico!\n");
    }

    return 0;
}
#endif // ex4

#ifdef ex5
/* As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles. */


int main() {
    int hr_ini, min_ini, seg_ini;
    int hr_fim, min_fim, seg_fim;
    int hr, min, seg;

    setlocale(LC_ALL, "");

    printf("Digite o horário de início da ligação (hora minuto segundo, ex: 21 10 30): ");
    scanf("%d %d %d", &hr_ini, &min_ini, &seg_ini);

    printf("Digite o horário de fim da ligação (hora minuto segundo, ex: 21 10 30): ");
    scanf("%d %d %d", &hr_fim, &min_fim, &seg_fim);

    seg= seg_fim - seg_ini;
    if (seg< 0) {
        seg += 60;
        min_fim--;
    }

    min = min_fim - min_ini;
    if (min < 0) {
        min += 60;
        hr_fim--;
    }

    hr = hr_fim - hr_ini;
    if (hr < 0) {
        hr += 24;
    }

    printf("Duração da ligação: %02d:%02d:%02d\n", hr, min, seg);

    return 0;
}


#endif // ex5
