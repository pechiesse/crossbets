#include <stdio.h>
#include <stdlib.h>
#include "cassino.h"
#include "cacaniquel.h"

typedef struct {
    int tipo;   
    int valor;  
} Aposta;

static void limparBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int NumSorteado(int min, int max){
    return rand() % (max - min + 1) + min;
}

int ehVermelho(int n){
    int numVermelho[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    for (int i = 0; i < 18; i++)
        if (n == numVermelho[i]) return 1;
    return 0;
}

char* tipoNum(int n){
    return (n % 2 == 0) ? "par" : "impar";
}

char* corNum(int n){
    if (n == 0) return "verde";
    return ehVermelho(n) ? "vermelho" : "preto";
}

char* grupoNum(int n){
    if (n == 0)  return "Duzia zero";
    if (n <= 12) return "1a duzia (1-12)";
    if (n <= 24) return "2a duzia (13-24)";
    return "3a duzia (25-36)";
}

int numValido(void){
    int num;
    printf("Escolha um numero de 0 a 36: ");
    while (scanf("%i", &num) != 1 || num < 0 || num > 36){
        limparBuffer();
        printf("Digite um numero valido: ");
    }
    return num;
}

Aposta escolhaUser(void){
    Aposta aposta = {-1, 0};
    int opcao = 0;
    char letra;

    printf("\nEscolha em qual opcao quer apostar:\n");
    printf("    1 - Numero 0 - 36 (x35)\n");
    printf("    2 - Cor: Vermelho / Preto (x2)\n");
    printf("    3 - Par ou impar (x2)\n");
    printf("    4 - Duzias (x3)\n");
    printf("    5 - Voltar\n");

    if (scanf("%i", &opcao) != 1){
        limparBuffer();
        return aposta;
    }

    switch (opcao){
    case 1:
        aposta.tipo = 1;
        aposta.valor = numValido();
        break;

    case 2:
        aposta.tipo = 2;
        printf("Escolha: (V)ermelho ou (P)reto: ");
        while (scanf(" %c", &letra) != 1 || (letra != 'V' && letra != 'v' && letra != 'P' && letra != 'p')){
            limparBuffer();
            printf("Escolha um valor valido: V ou P: ");
        }
        aposta.valor = (letra == 'V' || letra == 'v');
        break;

    case 3:
        aposta.tipo = 3;
        printf("Escolha: (P)ar ou (I)mpar: ");
        while (scanf(" %c", &letra) != 1 || (letra != 'I' && letra != 'i' && letra != 'P' && letra != 'p')){
            limparBuffer();
            printf("Escolha um valor valido: I ou P: ");
        }
        aposta.valor = (letra == 'P' || letra == 'p');
        break;

    case 4:
        aposta.tipo = 4;
        printf("Escolha entre as duzias:\n");
        printf("    1 - 1-12\n");
        printf("    2 - 13-24\n");
        printf("    3 - 25-36\n");
        while (scanf("%i", &aposta.valor) != 1 || aposta.valor < 1 || aposta.valor > 3){
            limparBuffer();
            printf("Opcao invalida! Escolha entre 1 - 2 - 3: ");
        }
        break;

    case 5:
        aposta.tipo = 0;
        break;

    default:
        printf("Opcao invalida\n");
        break;
    }

    return aposta;
}


int verificarAposta(Aposta a, int sorteado){
    switch (a.tipo){
    case 1: return a.valor == sorteado;
    case 2: return sorteado != 0 && ehVermelho(sorteado) == a.valor;
    case 3: return sorteado != 0 && (sorteado % 2 == 0) == a.valor;
    case 4: return sorteado >= 12 * (a.valor - 1) + 1 && sorteado <= 12 * a.valor;
    default: return 0;
    }
}

void mostrarResultado(int ganhou, int sorteado){
    printf("\n%s Numero sorteado: %i, %s, %s, %s\n",
           ganhou ? "Parabens, voce ganhou!" : "Voce perdeu.",
           sorteado, tipoNum(sorteado), grupoNum(sorteado), corNum(sorteado));
}

void jogarRoleta(double *saldo){

    Aposta aposta;


    do{
            aposta = escolhaUser();
        } while (aposta.tipo == -1);
        
    if (aposta.tipo == 0) return;     

    double valorAposta = lerAposta(*saldo);

    int sorteado = NumSorteado(0, 36);
    int ganhou = verificarAposta(aposta,sorteado);
    
    double multiplicador;
    switch(aposta.tipo){
        case 1: multiplicador = 35;
        break;
        case 2: case 3: multiplicador = 1;
        break;
        case 4: multiplicador = 2;
        break;
        default: multiplicador = 0;
        break;
    }

    if(ganhou){
        *saldo += valorAposta * multiplicador;
    }else{
        *saldo -= valorAposta;
    }

    mostrarResultado(verificarAposta(aposta, sorteado), sorteado);

    printf("Saldo atual: R$%.2f\n",*saldo);

    return;
}
