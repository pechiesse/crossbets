#include <stdio.h>

double lerSaldo(void){
    double saldo = 0.0;
    int resultado;
    int c;

    printf("Quanto quer depositar? R$");
    resultado=scanf("%lf", &saldo);

    while(resultado!=1 || saldo<=0){
        while ((c=getchar()) != '\n' && c!=EOF);
        printf("Saldo invalido! Escolha um valor valido! R$");
        resultado = scanf("%lf", &saldo);
    }
    while ((c=getchar()) != '\n' && c!=EOF);

    printf("Valor depositado = R$%.2f\n",saldo);

    return saldo;
}

double lerAposta(double saldo){
    double aposta;
    int resultado;
    int clear;

    printf("Quanto deseja apostar?  ");
    resultado=scanf("%lf",&aposta);

    while(resultado!=1 || aposta>saldo || aposta<=0){
        while ((clear=getchar()) != '\n' && clear!=EOF);
        printf("Aposta invalida! Escolha um valor valido! R$");
        resultado = scanf("%lf", &aposta);
    }
    while((clear=getchar()) != '\n' &&clear!=EOF);

    return aposta;
    
}

int lerOpcao(int min, int max){
    int escolha;
    int resultado;
    int c;

    resultado=scanf("%i",&escolha);

    while(resultado!=1 || escolha<min || escolha>max){
        while ((c=getchar()) != '\n' && c!=EOF);
        printf("Valor invalido! Escolha uma das opcoes: %i - %i! ",min,max);
        resultado=scanf("%i",&escolha);
    }
    while ((c=getchar()) != '\n' && c!=EOF);

    return escolha;
}