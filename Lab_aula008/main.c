#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

	printf("A soma dos numeros impares eh : %d\n\n", soma);

	free(p);
}

void exercicio02(){
    char *frase, primeiroCaracter, aux[200];
    int i = 0, contador = 0;

    printf("Digite a frase desejada: \n");
    gets(aux);

    frase = (char *)malloc(strlen(aux));

    strcpy(frase, aux);

    printf("A frase digitada foi ");
    puts(frase);

    primeiroCaracter = frase[0];

    for(i = 0; i < strlen(frase); i++){
        if(frase[i] == primeiroCaracter){
            contador++;
        }
    }

    printf("O primeiro caracter se repete na frase %d vezes\n\n", contador);

    free(frase);
}

struct aluno{
    char nome[30];
    float media;
    int faltas;
};

exercicio03(){
    int entrada, i;
    struct aluno *alunos;

    srand(time(NULL));

    printf("Deseja ver a informacao de quantos alunos?\n");
    scanf("%d", &entrada);

    alunos = (struct aluno *)malloc(entrada * sizeof(struct aluno));
    printf("\n\n");

    for(i = 0; i<entrada; i++){
        printf("Nome: ");
        fflush(stdin);
        gets(alunos[i].nome);
        printf("Media: ");
        scanf("%f",&alunos[i].media);
        printf("Faltas: ");
        scanf("%d",&alunos[i].faltas);
        printf("\n\n");
    }

    system("cls");

    printf("Exibindo as informacoes inseridas na ordem inversa; \n");

    for(i = entrada - 1; i >= 0; i--){
        printf("_______________________________\n");
        printf("Nome: ");
        puts(alunos[i].nome);
        printf("Media: %.1f\n", alunos[i].media);
        printf("Faltas: %d\n", alunos[i].faltas);
        printf("_______________________________\n");
    }

    free(alunos);
}

void exercicio04(){
    int i, entrada, acumulado, aux, numeroDePares = 0, numeroDeImpares = 0,
        *vetor, *impares, *pares;

    srand(time(NULL));

    printf("Digite o tamanho do vetor que voce deseja\n");
    scanf("%d", &entrada);

    vetor = (int *)malloc(entrada * sizeof(int));

    for(i = 0; i < entrada; i++){
        vetor[i] = rand()%100;
    }
    for(i = 1; i < entrada; i++){
        acumulado = 1;
        while(vetor[i] > vetor[i - acumulado]){
            aux = vetor[i];
            vetor[i] = vetor[i - acumulado];
            vetor[i - acumulado] = aux;
            i--;
        }
    }

    printf("Vetor em ordem decrescente\n");
    for(i = 0; i < entrada; i++){
        printf("%d - %d\n", i+1, vetor[i]);
    }

    printf("\n\n");

     for(i = 0; i < entrada; i++){
        if(vetor[i]%2 == 0){
            pares[numeroDePares] = vetor[i];
            numeroDePares++;
            pares = (int *)malloc(numeroDePares * sizeof(int));
        }else{
            impares[numeroDeImpares] = vetor[i];
            numeroDeImpares++;
            impares = (int *)malloc(numeroDeImpares * sizeof(int));
        }
    }

    printf("Vetor dos numeros impares\n");
    for(i = 0; i < numeroDeImpares; i++){
        printf("%d - %d\n", i+1, impares[i]);
    }

    printf("\n\n");

    printf("Vetor dos numeros pares\n");
    for(i = 0; i < numeroDePares; i++){
        printf("%d - %d\n", i+1, pares[i]);
    }

    free(vetor);
    free(impares);
    free(pares);
    free(aux);
}

int main(int argc, char** argv) {
	//exercicio01();
	//exercicio02();
	//exercicio03();
	exercicio04();
	return 0;
}
