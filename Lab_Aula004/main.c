#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

void quadrado(int *num){
    *num = *num**num;
}

void exercicio003(){
    int a, *b = &a;
    printf("Digite um numero\n");
    scanf("%d", &a);
    printf("Voce digitou %d \n", a);
    quadrado(b);
    printf("O numero elevado ao quadrado eh %d \n", *b);
}

void exercicio004(){
    int a = 5, b = 2,
        *c = &a, *d = &b;
    *d = *c + *d;

    printf("%d\n", b);
}

void reordenar(int *a, int *b, int *c){
    int aux;

    if(*a > *b){
        aux = *b;
        *b = *a;
        *a = aux;
    }
    if(*a > *c){
        aux = *c;
        *c = *a;
        *a = aux;
    }
    if(*b > *c){
        aux = *c;
        *c = *b;
        *b = aux;
    }
}

void exercicio01(){
    int primeiroValor, segundoValor, terceiroValor;

    printf("Digite o PRIMEIRO valor\n");
    scanf("%d", &primeiroValor);
    printf("Digite o SEGUNDO valor\n");
    scanf("%d", &segundoValor);
    printf("Digite o TERCEIRO valor\n");
    scanf("%d", &terceiroValor);

    reordenar(&primeiroValor , &segundoValor, &terceiroValor);

    printf("Os valores em ordem crescente eh...\n %d - %d - %d\n", primeiroValor, segundoValor, terceiroValor);
}

void converter_cm(double *r, double *c, double *a){
    *r = *r*100;
    *c = 2*PI**r;
    *r = *r*100;
    *a = PI**r**r;
    *r = *r/100;
}

void exercicio02(){
    double raio, circunferencia, area;
    double *r, *c,*a;
    r = &raio;
    c = &circunferencia;
    a = &area;

    printf("Digite o valor do Raio em metros\n");
    scanf("%lf", &raio);

    converter_cm(r, c, a);
    printf("Raio: %.2lf cm\nArea: %.2lf cm\nCircunferencia: %.2lf cm\n", raio, area, circunferencia);
}

int main()
{
    printf("Exercicios Aula Passada\n");
    system("pause");
    system("cls");

    printf("Exercicio 03\n");
    exercicio003();
    system("pause");
    system("cls");

    printf("Exercicio 04\n");
    exercicio004();
    system("pause");
    system("cls");

    printf("Exercicios Aula de Hoje\n\nExercicio 01\n");
    exercicio01();
    system("pause");
    system("cls");

    printf("Exercicio 02\n");
    exercicio02();
    return 0;
}
