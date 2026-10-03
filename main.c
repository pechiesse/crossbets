#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cassino.h"
#include "cacaniquel.h"
#include "roleta.h"

int main(void){
    srand(time(NULL));
    double saldo= lerSaldo();
    int jogo;
    int acao = 1;

    do{
        printf("\nQual jogo deseja jogar?\n");
        printf("    1 - Caca-niquel\n");
        printf("    2 - Roleta\n");
        printf("    3 - Black-Jack\n");
        printf("    4 - Sair\n");
        printf("Opcao: ");

        jogo = lerOpcao(1, 4);

        if(jogo!=4){
            do{
                switch(jogo){
                    case 1:
                        jogarCacaNiquel(&saldo);
                        break;
                    case 2:
                        jogarRoleta(&saldo);
                        break;
                    case 3:
                        printf("Em breve\n");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
                }
                if(saldo<0.01){
                    printf("Nenhum dinheiro na conta!\n");
                    printf("Jogo encerrado!\n");
                    acao = 3;
                }else{
                    printf("\nO que deseja fazer?\n");
                    printf("    1 - Continuar neste jogo\n");
                    printf("    2 - Trocar de jogo\n");
                    printf("    3 - Encerrar\n");
                    printf("Opcao: ");
                    acao = lerOpcao(1, 3);
                }
            }while (acao == 1);
        }
    }while(jogo!=4 && acao !=3);
    
    printf("Saldo final: R$%.2f\n", saldo);

    return 0;
}