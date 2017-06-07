#include <stdio.h>
#include <stdlib.h>

int soma(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return n + soma(n-1);
}

int padovan(int n){
    if(n == 0 || n == 1 || n == 2)
        return 1;
    else if (n > 2)
        return padovan(n-2) + padovan(n-3);
}

int exponencial(int base, int expoente){
    if(expoente == 0){
        return 1;
    }else if(expoente == 1){
        return base;
    }else{
        return base*exponencial(base, expoente - 1);
    }
}

void exercicio001(){
    int somatorio, entrada;

    printf("Qual o valor de n que voce gostaria?\n");
    scanf("%d", &entrada);

    somatorio = soma(entrada);

    printf("O valor da soma eh %d\n\n", somatorio);
}

void exercicio002(){
    int entrada, numeroPadovan;

    printf("Qual o valor de n que voce gostaria?\n");
    scanf("%d", &entrada);

    numeroPadovan = padovan(entrada);

    printf("O numero de padovan para o numero %d eh: %d\n\n", entrada, numeroPadovan);
}

void exercicio003(){
    int primeiroNumero, segundoNumero, mdc,
        auxPrimeiro, auxSegundo;

    printf("Digite o PRIMEIRO numero para calcular o mdc\n");
    scanf("%d", &primeiroNumero);

    printf("Digite o SEGUNDO numero para calcular o mdc\n");
    scanf("%d", &segundoNumero);

    if(primeiroNumero >= segundoNumero){
        auxPrimeiro = primeiroNumero;
        auxSegundo = segundoNumero;
    }else{
        auxPrimeiro = segundoNumero;
        auxSegundo = primeiroNumero;
    }

    mdc = auxPrimeiro%auxSegundo;

    if(auxSegundo == 0){
        printf("O mdc eh %d\n", auxPrimeiro);
    }else if(auxPrimeiro == 0){
        printf("O mdc eh %d\n", auxSegundo);
    }else{
        printf("O mdc eh %d\n", mdc);
    }
}

void exercicio004(){
    int x, y, resultado;

    printf("Digite o PRIMEIRO valor\n");
    scanf("%d", &x);

    printf("Digite o SEGUNDO valor\n");
    scanf("%d", &y);

    resultado = exponencial(x, y);

    printf("O resultado da exponecial de x por y eh: %d\n\n", resultado);
}

int main()
{
    printf("Primeiro Exercicio\n");
    system("pause");
    system("cls");
    exercicio001();
    system("pause");

    system("cls");
    printf("Segundo Exercicio\n");
    system("pause");
    system("cls");
    exercicio002();
    system("pause");

    system("cls");
    printf("Terceiro Exercicio\n");
    system("pause");
    system("cls");
    exercicio003();
    system("pause");

    system("cls");
    printf("Quarto Exercicio\n");
    system("pause");
    system("cls");
    exercicio004();
    system("pause");

    return 0;
}
