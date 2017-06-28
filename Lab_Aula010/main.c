
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

    printf("Digite o nome do segundo Arquivo\n");
    fflush(stdin);
    gets(aux);

    strcat(segundoArquivo, aux);

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
}

void exercicio02(){
    char frase[200], arquivo[] = "C:\\Users\\1E13\\Desktop\\doc.txt";
    int bandeira = 1;

    printf("Passei por aqui\n");
    FILE *arquivo2 = fopen(arquivo, "w");
    printf("Passei aqui tambem\n");

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
}


void exercicio03(){
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
}
