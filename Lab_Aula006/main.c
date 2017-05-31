#include <stdio.h>
#include <stdlib.h>

void exemplo(){
    char nome[61];

    printf("Digite seu nome: ");
    scanf("%s", nome); //scanf possui a limitação de pegar apenas a primeira cadeia de caracteres...

    printf("O nome armazenado foi %s", nome);

    getch();
}
void exercicio001(){
    char frase[100], caractere[1],
        *ponteiro = &frase[0];
    int i, numeroIguais = 0, tamanhoDaFrase=0;

    printf("Digite uma frase\n\n");
    fflush(stdin);
    gets(frase);

    tamanhoDaFrase = strlen(frase);

    printf("Tamanho da Frase %d\n\n", tamanhoDaFrase);
    printf("Digite um caracterere\n");
    fflush(stdin);
    scanf("%s", caractere);

    for(i=0; i <= tamanhoDaFrase; i++){
        if(ponteiro[i - 1] == caractere[0]){
            numeroIguais++;
        }
    }

    printf("O caractere %c se repete %d na frase inserida\n\n", caractere[0], numeroIguais);
}
void exercicio002(){
    char frase1[100], frase2[100];
    int i, k = 0, numeroRepeticao = 0,
        tamanhoPrimeira = 0, tamanhoSegunda = 0;

    printf("Digite a primeira frase (MAIOR)\n");
    fflush(stdin);
    gets(frase1);
    tamanhoPrimeira = strlen(frase1);

    printf("Digite a segunda frase (MENOR)\n");
    fflush(stdin);
    gets(frase2);
    tamanhoSegunda = strlen(frase2);

    for(i = 0; i < tamanhoPrimeira; i++){
        int repeticao = 0;
        for(k=0; k < tamanhoSegunda && frase1[k] != '\0'; k++){
            if(frase1[i+k] == frase2[k]){
                repeticao++;
            }
        }
        if(repeticao == tamanhoSegunda){
            numeroRepeticao++;
        }
    }
    printf("A segunda frase esta contida %d vezes na primeira\n", numeroRepeticao);
}
void exercicio003(){
    char frase1[100], frase2[100];
    int i, k = 0, numeroRepeticao = 0,
        tamanhoPrimeira = 0, tamanhoSegunda = 0;

    printf("Digite a primeira frase (MAIOR)\n");
    fflush(stdin);
    gets(frase1);
    tamanhoPrimeira = strlen(frase1);

    printf("Digite a segunda frase (MENOR)\n");
    fflush(stdin);
    gets(frase2);
    tamanhoSegunda = strlen(frase2);

    for(i = 0; i < tamanhoPrimeira; i++){
        int repeticao = 0;
        for(k=0; k < tamanhoSegunda && frase1[k] != '\0'; k++){
            if(frase1[i+k] == frase2[k]){
                repeticao++;
            }
        }
        if(repeticao == tamanhoSegunda){
            numeroRepeticao++;
            i += tamanhoSegunda;
        }
    }
    printf("A segunda frase esta contida %d vezes na primeira\n", numeroRepeticao);

}
void exercicio004(){
   char frase1[100], frase2[100];
    int i, k = 0, numeroRepeticao = 0, posicaoInicial[100], j = 0,
        tamanhoPrimeira = 0, tamanhoSegunda = 0;

    printf("Digite a primeira frase (MAIOR)\n");
    fflush(stdin);
    gets(frase1);
    tamanhoPrimeira = strlen(frase1);

    printf("Digite a segunda frase (MENOR)\n");
    fflush(stdin);
    gets(frase2);
    tamanhoSegunda = strlen(frase2);

    for(i = 0; i < tamanhoPrimeira; i++){
        int repeticao = 0;
        for(k=0; k < tamanhoSegunda && frase1[k] != '\0'; k++){
            if(frase1[i+k] == frase2[k]){
                repeticao++;
            }
        }
        if(repeticao == tamanhoSegunda){
            numeroRepeticao++;
            posicaoInicial[j] = i+k-tamanhoSegunda;
            j++;
        }
    }
    printf("A segunda frase esta contida %d vezes na primeira\n\n", numeroRepeticao);
    for(i=0; i<j; i++){
        printf("Posicao de Repeticao: A partir do %d caractere\n", posicaoInicial[i] + 1);
    }

}

int main(){
    //exemplo();
    printf("Exercicio 01\n\n");
    exercicio001();
    system("pause");

    system("cls");
    printf("Exercicio 02\n\n");
    exercicio002();
    system("pause");

    system("cls");
    printf("Exercicio 03\n\n");
    exercicio003();
    system("pause");

    system("cls");
    printf("Exercicio 04\n\n");
    exercicio004();
    system("pause");
    return 0;
}
