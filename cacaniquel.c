#include <stdio.h>
#include <stdlib.h>
#include "cassino.h"
#include "cacaniquel.h"

void jogarCacaNiquel(double *saldo){
    int min=1;
    int max=7;
    double multiplicador = 10;

    double aposta = lerAposta(*saldo);

        int sorte1 = rand() % (max - min + 1) + min;
        int sorte2 = rand() % (max - min + 1) + min;
        int sorte3 = rand() % (max - min + 1) + min;
        printf("%i %i %i\n",sorte1,sorte2,sorte3);\

        if ((sorte1==sorte2)&&(sorte1==sorte3)){
            printf("parabens, voce ganhou\n");
            *saldo += aposta * multiplicador;
        }else{
            printf("Voce perdeu!\n");
            *saldo -= aposta;

        }
        printf("Saldo atual: R$%.2f\n",*saldo);
}