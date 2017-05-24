#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void exercicio01(){
	int array[]={1,2,3,4,5};
	int *p = &array[1];
	printf("Endereco apontado: %d \nValor apontado: %d \n", p, *p);
	
	printf("Endereco apontado + 1: %d \nValor apontado + 1: %d \n", (p+1), *(p+1));
}

void exercicio02(){
	int g[] = {2,4,5,8,10,32,78};
	int *ptr1 = &g[0], //2 do array
		*ptr2 = &g[3]; //8 do array
	printf("Endereco de *g: %d \nValor de *g: %d \n\n", g, *g);
	printf("Endereco de *g + 1: %d \nValor de *g + 1: %d \n\n", g+1, *g+1);
	printf("Endereco de *ptr1: %d \nValor de *ptr1: %d \n\n", ptr1, *ptr1);
	printf("Endereco de *(ptr1 + 1): %d \nValor de *(ptr1 + 1): %d \n\n", (ptr1 + 1), *(ptr1 + 1));
	printf("Endereco de *(g + 1): %d \nValor de *(g + 1): %d \n\n", (g + 1), *(g + 1));
	printf("Endereco de *(g + 5): %d \nValor de *(g + 5): %d \n\n", (g + 5), *(g + 5));
	printf("Endereco de *ptr2: %d \nValor de *ptr2: %d \n\n", ptr2, *ptr2);
	printf("Endereco de *(ptr2 + 2): %d \nValor de *(ptr2 + 2): %d \n\n", (ptr2 + 2), *(ptr2 + 2));
}

void exercicio03(){
	int array[10], 
		inicio, final, i, entrada;
	
	printf("---------------------------------\n");
	printf("--GERADOR DE NUMEROS ALEATORIOS--\n");
	printf("---------------------------------\n\n");
	
	
	printf("Digite qual o valor inicial: \n");
	scanf("%d", &inicio);
	printf("Digite qual o valor final: \n");
	scanf("%d", &final);
	
	srand(3);
	
	for(i =0; i < 10; i++){
		array[i] = rand()%((final - inicio) + 1) + inicio; 
		printf("%d - ", array[i]);	
	}
	
	int *ponteiro = &array[0];
	
	printf("\nQual a posicao do vetor que voce quer ver?\n");
	scanf("%d", &entrada);
	
	printf("O valor da posicao indicada eh: %d\n\n", ponteiro[entrada - 1]); 
	
}

void exercicio04(){
	int array[30], i, final = 100, inicio = 0;
	int *ponteiro;
	
	void srand(3);
	
	for(i=0; i<30; i++){
		array[i] = rand()%100;
	}
	
	printf("Valores entre a posicao 20 a 30\n");
	for(i = 19; i<30; i++){
		printf("\n Posicao %d: %d \n", i+1, array[i]);
	}
}

int main(int argc, char *argv[]) {
	printf("Exercicio 01 \n");
	exercicio01();
	printf("Exercicio 02 \n");
	exercicio02();
	printf("Exercicio 03 \n");
	exercicio03();
	printf("Exercicio 04 \n");
	exercicio04();
	return 0;
}
