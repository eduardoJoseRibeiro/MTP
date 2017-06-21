#include <stdio.h>
#include <stdlib.h>

void abreFecha(){
    FILE *arquivo;
    arquivo = fopen("C:/Users/1E30/Desktop/teste.txt", "w");

    arquivo==0?printf("Erro na abertura do arquivo\n"):printf("Arquivo aberto com sucesso\n");

    fclose(arquivo);
    system("pause");
}

void exercicio001(){
    char entrada[100], lugar[] = "C:/Users/1E30/Desktop/", caracter[100];
    FILE *arquivo;
    int linhas = 0;

    printf("Digite o nome do arquivo\n");
    gets(entrada);
    strcat(lugar, entrada);
    arquivo = fopen(lugar, "r");

    if(arquivo == 0){
        printf("Erro na abertura do arquivo\n");
    }else{
        printf("Arquivo aberto com sucesso\n");
        rewind(arquivo);

        printf("\n");

        while (!feof(arquivo)){
            fgets(caracter, 100, arquivo);
            printf("%s", caracter);
            linhas++;
        }
        printf("\n\n");
    }

    printf("O arquivo possui %d linhas\n\n", linhas);

    fclose(arquivo);
    system("pause");
}

void exercicio002(){
    char entrada[100], lugar[] = "C:/Users/1E30/Desktop/", copiaLinha[100];
    FILE *arquivo;
    int linhas = 0, caracteres = 0, palavras = 0;

    printf("Digite o nome do arquivo\n");
    gets(entrada);
    strcat(lugar, entrada);
    arquivo = fopen(lugar, "r");

    if(arquivo == 0){
        printf("Erro na abertura do arquivo\n");
    }else{
        printf("Arquivo aberto com sucesso\n");
        rewind(arquivo);

        printf("\n");

        while (!feof(arquivo)){                    // Verica se chegou no final do arquivo . false false false true !true true true false
            fgets(copiaLinha, 100, arquivo);       // Copia o conteudo da Linha do arquivo para copiaLinha
            printf("%s", copiaLinha);
            linhas++;
            int i = strlen(copiaLinha);
            if(i > 0){
                i = i - 1;
            }
            for(i; i>=0;  i--){
                caracteres++;
                if(copiaLinha[i]==' '&& copiaLinha[i+1]!=' '){
                    palavras++;
                }
            }
        }
        palavras+= linhas;
        printf("\n\n");
    }

    printf("O arquivo possui\n%d - Linhas\n%d - Caracteres\n%d - Palavras \n\n", linhas, caracteres, palavras);

    fclose(arquivo);
    system("pause");
}
int main()
{
    exercicio001();
    printf("\n\n");
    exercicio002();
    return 0;
}
