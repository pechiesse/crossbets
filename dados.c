#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cassino.h"
#include "cacaniquel.h"
#include "roleta.h"

static int numDado(int min, int max){
    return rand() % (max - min + 1) + min;
}

static int escolhaUser(void){
    printf("\nQual das opcoes deseja apostar?\n");
    printf("    1 - Menor que 7 (1x)\n");
    printf("    2 - Exatamente 7 (4x)\n");
    printf("    3 - Maior que 7 (1x)\n");
    printf("    4 - Sair\n");
    printf("Opcao: ");

    return lerOpcao(1,4);
}

void mostrarSomaDado(int ganhou, int dado1, int dado2, int soma){
    printf("\n%s Numero dos dados: %i, %i\n"
            "Soma dos dados: %i\n",
           ganhou ? "Parabens, voce ganhou!" : "Voce perdeu.",
           dado1, dado2, soma);
    }


void jogarDados(double *saldo){
    int ganhou=0;
    double multiplicador = 0;
    int escolha = escolhaUser();
    
    if (escolha==4) return;
    
    double valorAposta = lerAposta(*saldo);

    int dado1 = numDado(1,6);
    int dado2 = numDado(1,6);
    int soma = dado1 + dado2;

    switch(escolha){
        case 1:
            ganhou = (soma < 7);
            multiplicador = 1;
            break;
        case 2:
            ganhou = (soma == 7);
            multiplicador = 4;
            break;
        case 3:
            ganhou = (soma > 7);
            multiplicador = 1;
            break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    if (ganhou){
        *saldo += valorAposta * multiplicador;
    }else{
        *saldo -= valorAposta;
    }

    mostrarSomaDado(ganhou,dado1,dado2,soma);

    printf("Saldo atual: R$%.2f\n",*saldo);

    return;
}