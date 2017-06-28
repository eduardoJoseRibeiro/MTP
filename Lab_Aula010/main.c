#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void exercicio01(){
    char primeiroArquivo[50] = "C:\\Users\\1E13\\Desktop\\",
        segundoArquivo[50] = "C:\\Users\\1E13\\Desktop\\",
        terceiroArquivo[50] = "C:\\Users\\1E13\\Desktop\\arquivo3.txt",
        aux[50], aleatorio[50];

    int i = 0, j = 0;

    srand(time(NULL));

    printf("Digite o nome do primeiro Arquivo\n");
    fflush(stdin);
    gets(aux);

    strcat(primeiroArquivo, aux);
    strcat(primeiroArquivo, ".txt");

    printf("Digite o nome do segundo Arquivo\n");
    fflush(stdin);
    gets(aux);

    strcat(segundoArquivo, aux);
    strcat(segundoArquivo, ".txt");

    FILE *arquivo1 = fopen(primeiroArquivo, "w+");
    FILE *arquivo2 = fopen(segundoArquivo, "w+");
    FILE *arquivo3 = fopen(terceiroArquivo, "w+");

    if(arquivo1){
        printf("\nArquivo 1 Aberto com sucesso!\n");
        if(arquivo2){
            printf("\nArquivo 2 Aberto com sucesso!\n");

            for(i = 0; i < 20; i++){
                aleatorio[i] = rand()%100;
                fprintf(arquivo1, "%d\n", aleatorio[i]);

                aleatorio[i] = rand()%100;
                fprintf(arquivo2, "%d\n", aleatorio[i]);
            }
            strcpy(aux, "");

            rewind(arquivo1);
            fprintf(arquivo3, "===== Arquivo 1 =====\n");
            while (!feof(arquivo1)){                    // Verica se chegou no final do arquivo . false false false true !true true true false
                fgets(aux, 50, arquivo1);
                fprintf(arquivo3, "%s", aux);
            }

            strcpy(aux, "");

            rewind(arquivo2);
            fprintf(arquivo3, "\n===== Arquivo 2 =====\n");
            while(!feof(arquivo2)){
                fgets(aux, 50, arquivo2);
                fprintf(arquivo3, "%s", aux);
            }

        }else
            printf("\nErro ao abrir o arquivo 2\n");
    }
    else
        printf("\nErro ao abrir o arquivo 1\n");

    if(arquivo3){
        printf("\nArquivo 3 criado com sucesso\n");
    }else {
        printf("\nArquivo 3 nao foi criado!\n");
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
    system("pause");
}

void exercicio02(){
    system("cls");

    char frase[200], arquivo[] = "C:\\Users\\1E13\\Desktop\\doc.txt";
    int bandeira = 1;

    FILE *arquivo2 = fopen(arquivo, "w");

    if(arquivo2){
        printf("\nArquivo aberto com sucesso!\n");

        rewind(arquivo2);
        printf("Digite qualquer coisa, mas nao esqueca de colocar fim no final\n");
        do{
            fflush(stdin);
            gets(frase);

            fprintf(arquivo2, "%s\n", frase);

            if(frase[0] == 'f' || frase[0] == 'F'){
                if(frase[1] == 'i' || frase[1] == 'I'){
                    if(frase[2] == 'm' || frase[2] == 'M'){
                        bandeira = 0;
                    }else continue;
                }else continue;
            }else continue;

            strcpy(frase, "");

        }while(bandeira);
    }else{
        printf("\nO arquivo nao pode ser aberto!\n");
    }

    fclose(arquivo2);
    system("pause");
}

void exercicio03(){
    system("cls");

    char arquivo[] = "C:\\Users\\1E13\\Desktop\\doc.txt", aux[200];
    int i = 0;

    FILE *doc = fopen(arquivo, "r");

    rewind(doc);
    printf("Imprimindo o arquivo em maiusculo!\n");
    while(!feof(doc)){
        fgets(aux, 50, doc);
        for(i=0; aux[i]!= NULL; i++){
            aux[i] = toupper(aux[i]);
        }
        printf("%s", aux);
    }

    fclose(doc);
    system("pause");
}

int fatorial(int entrada){
    if(entrada == 0)
        return 1;
    else if(entrada == 1)
        return 1;
    else
        return (entrada*fatorial(entrada - 1));
}

void exercicio04(){
    system("cls");

    int i = 0, entrada, fator, bandeira = 1;
    char arquivo[] = "C:\\Users\\1E13\\Desktop\\doc3.txt", aux[100];

    FILE *arq = fopen(arquivo, "w+");

    rewind(arq);
    fprintf(arq, "=============================\n");
    fprintf(arq, "==== Resultado Fatoriais ====\n");
    fprintf(arq, "=============================\n");

    do{
        system("cls");
        printf("Digite um valor n\n");
        fflush(stdin);
        scanf("%d",&entrada);

        if(entrada==999){
            bandeira = 0;
        }else{
            fator = fatorial(entrada);
            printf("\nA fatorial do numero digitado eh %d\n", fator);
            fprintf(arq, "Para %d = %d\n", entrada, fator);
        }
        system("pause");
    }while(bandeira);

    fprintf(arq, "=============================\n");
    fclose(arq);

    FILE *leitura = fopen(arquivo, "r");

    system("cls");
    while(!feof(leitura)){
        fgets(aux, 100, leitura);
        printf("%s", aux);
    }

    fclose(leitura);
    system("pause");
}

int main()
{
    exercicio01();
    exercicio02();
    exercicio03();
    exercicio04();
    return 0;
}
