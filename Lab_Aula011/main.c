#include <stdio.h>
#include <stdlib.h>

void exercicio01(){
    FILE * arquivo;
    int i, result;
    int vet[4]={10, 20, 30, 40};

    arquivo = fopen("exemplo.dat", "wb");
    if(arquivo == NULL){
        printf("Nao foi possivel criar o arquivo.\n");
    }else{
        result = fwrite(vet, sizeof(int), 4, arquivo);
        printf("Numero de elementos lidos: %d\n", result);

        for(i=0; i<result; i++){
            printf("vetor[%d] = %d\n",i, vet[i]);
        }
    }
    fclose(arquivo);
}

enum {
    TAMANHO = 100
};

struct Pessoa{
    char nome[TAMANHO];
    int idade;
}numeroPessoas[TAMANHO];

void exercicio03(){
    int entrada, i, resultado;

    FILE *bancoDeDados = fopen("bancoDeDados.dat", "wb");

    if(bancoDeDados == NULL)
        printf("Nao foi possivel criar o arquivo.\n");
    else{
        printf("Quantas pessoas voce deseja cadastrar?\n");
        scanf("%d", &entrada);

        for(i=0; i<entrada; i++){
            system("cls");
            printf("Pessoa %d\n", i+1);
            printf("Digite o nome da pessoa: ");
            fflush(stdin);
            gets(numeroPessoas[i].nome);
            printf("Digite a idade da pessoa: ");
            fflush(stdin);
            scanf("%d", &numeroPessoas[i].idade);
            system("pause");

        }
        system("cls");

        fwrite(numeroPessoas, sizeof(struct Pessoa), entrada, bancoDeDados);
        printf("Numero de elementos lidos: %d\n", entrada);

        for(i=0; i<entrada; i++){
            printf("\n=== Pessoa %d ===\nNome: ", i+1);
            puts(numeroPessoas[i].nome);
            printf("Idade: %d\n", numeroPessoas[i].idade);
        }
    }
    fclose(bancoDeDados);
}

void exercicio04(){
    int resultado, i, entrada;
    char conteudo[200];

    struct Pessoa lerPessoas[100];

    FILE *arquivo;

    arquivo = fopen("bancoDeDados.dat", "rb");

    system("pause");
    system("cls");

    printf("Quantos estruturas voce quer ler?\n");
    scanf("%d", &entrada);

    if(arquivo){
        resultado = fread(lerPessoas, sizeof(struct Pessoa), entrada, arquivo);
        printf("Numero de elementos lidos %d\n", resultado);

        for(i = 0; i<entrada; i++){
            printf("\n=== Pessoa %d ===\n", i+1);
            printf("Nome: %s\n", lerPessoas[i].nome );
            printf("Idade: %d\n", lerPessoas[i].idade );
            printf("================\n");
        }
    }else
        printf("Problemas ao abrir o arquivo\n");

    fclose(arquivo);
}

void queriaLer(){
    int resultado, i;
    char escrito[200];

    FILE *arquivo;

    arquivo = fopen("ola.txt", "r");
    if(arquivo){
        resultado = fread(escrito, sizeof(char), 200, arquivo);
        printf("Numero de elementos lidos: %d\n", resultado);

        for(i=0; i<resultado; i++){
            printf("escrito[%d] = %c\n",i, escrito[i]);
        }

    }else{
        printf("Arquivo nao pode ser aberto\n");
    }

    fclose(arquivo);

}

int main()
{
    exercicio03();
    exercicio04();

    return 0;
}
