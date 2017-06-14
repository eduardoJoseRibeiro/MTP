#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void exercicio00(){
	int *p;
	int *aux;
	int i =0;
	
	p = (int *)malloc(10*sizeof(int));
	for(i = 0;i<10; i++){
		p[i]=i;
	}
	for(i =0; i<10;i++){
		printf("%d - %p\n",p[i], &p[i] );
	}
}

void exercicio01(){
	int n;
	int i = 0, soma = 0;
	int *p;
	
	srand(time(NULL));
	
	printf("Qual o tamanho do vetor desejado?\n");
	scanf("%d", &n);
	
	p = (int *)malloc(n*sizeof(int));
	
	printf("O vetor cadastrado eh \n"); 
	
	for(i = 0; i < n; i++){
		p[i] = rand()%100;
		printf("%d - %d\n", i+1, p[i]);		
	}
	
	printf("\n\n");
	
	for(i = 0; i < n; i++){
		if(p[i]%2 == 1){
			soma = p[i] + soma;
		}	
	}
	
	printf("A soma dos numeros impares eh : %d", soma);
	
	free(p);
}

void exercicio02(){
	
}

int main(int argc, char** argv) {
	exercicio01();
	return 0;
}
