#include <stdio.h>
#include <stdlib.h>

struct Funcionarios{
    char nome[50];
    int idade;
    float salario;
}funcionario;
struct Data{
    int dia,
        mes,
        ano;
};
struct Pessoas{
    char nome[50],
        rg[20],
        telefone[20];
    struct Data data;
}pessoa;
struct Horario{
    int hora,
        minuto;
};
struct Aeronave{
    char modelo[30];
    int anoFabricacao,
        quantidadeAssentos;
};
struct Voo{
    int numeroDoVoo;
    struct Data data;
    struct Horario horario;
    struct Aeronave aeronave;
}voo[100];
struct Historico{
    char nome[30],
            cpf[20];

}historico;
struct Duracao{
    int minutos,
        segundos;
};
struct Musicas{
    char nome[50];
    struct Duracao duracao;
};
struct Albuns{
    char nome[30];
    struct Musicas musica[200];
};
struct Cantor{
    struct Pessoas pessoa;
    struct Albuns album[100];
}cantores[100];

void exercicio01(){
    system("cls");

    printf("**************************************\n");
    printf("*****Cadastramento de Funcionario*****\n");
    printf("**************************************\n");

    //Cadastra o Funcionario
    printf("\nDigite o nome do funcionario\n");
    gets(funcionario.nome);
    fflush(stdin);

    printf("\nDigite a idade do funcionario\n");
    scanf("%d", &funcionario.idade);
    fflush(stdin);

    printf("\nDigite o salario do funcionario\n");
    scanf("%f", &funcionario.salario);
    fflush(stdin);

    system("cls");

    //Exibe o funcionario cadastrado
    printf("**************************************\n");
    printf("********Funcionario Cadastrado********\n");
    printf("**************************************\n");

    printf("\nNome: ");
    puts(funcionario.nome);
    printf("Idade: %d", funcionario.idade);
    printf("\nSalario: %.2f \n\n", funcionario.salario);

}
void exercicio02(){
    system("cls");

    printf("**************************************\n");
    printf("********Cadastramento de Pessoa*******\n");
    printf("**************************************\n");

    //Cadastra Pessoa
    printf("\nDigite o NOME da Pessoa\n");
    gets(pessoa.nome);
    fflush(stdin);

    printf("\nDigite o RG da Pessoa\n");
    gets(pessoa.rg);
    fflush(stdin);

    printf("\nDigite o TELEFONE da Pessoa\n");
    gets(pessoa.telefone);
    fflush(stdin);

    printf("\nDigite o DIA / MES / ANO de nascimento da Pessoa\n");
    scanf("%d %d %d", &pessoa.data.dia,
                      &pessoa.data.mes,
                      &pessoa.data.ano);
    fflush(stdin);

    //Exibe Pessoa Cadastrada
    system("cls");
    printf("**************************************\n");
    printf("***********Pessoa Cadastrada**********\n");
    printf("**************************************\n");
    printf("\nNome: ");
    puts(pessoa.nome);
    printf("RG: ");
    puts(pessoa.rg);
    printf("Telefone: ");
    puts(pessoa.telefone);
    printf("Data de Nascimento: %d / %d / %d \n\n", pessoa.data.dia,
                                                    pessoa.data.mes,
                                                    pessoa.data.ano);
    printf("**************************************\n");
}
void cadastraVoo(int n){
    system("cls");

    printf("**************************************\n");
    printf("********Cadastramento de Viagem*******\n");
    printf("**************************************\n");

    printf("\nDigite o NUMERO do voo\n");
    scanf("%d", &voo[n].numeroDoVoo);
    fflush(stdin);

    printf("\nDigite a DATA DIA / MES / ANO do voo\n");
    scanf("%d %d %d", &voo[n].data.dia,
                        &voo[n].data.mes,
                        &voo[n].data.ano);
    fflush(stdin);

    printf("\nDigite o HORARIO hh:mm do voo\n");
    scanf("%d %d", &voo[n].horario.hora,
                    &voo[n].horario.minuto);
    fflush(stdin);

    printf("\nDigite o MODELO DO AVIAO\n");
    gets(voo[n].aeronave.modelo);
    fflush(stdin);

    printf("\nDigite o ANO DE FABRICACAO\n");
    scanf("%d", &voo[n].aeronave.anoFabricacao);
    fflush(stdin);

    printf("\nDigite o NUMERO DE ASSENTOS\n");
    scanf("%d", &voo[n].aeronave.quantidadeAssentos);
    fflush(stdin);
}
void imprimeVoo(int n){
    //Exibe Viagem Cadastrada
    printf("**************************************\n");
    printf("***********Viagem Cadastrada**********\n");
    printf("**************************************\n");

    printf("\nNumero do VOO: %d", voo[n].numeroDoVoo);
    printf("\nData: %d / %d / %d", voo[n].data.dia,
                                    voo[n].data.mes,
                                    voo[n].data.ano);
    printf("\nHorario: %d : %d", voo[n].horario.hora,
                                voo[n].horario.minuto);
    printf("\nAeronave: ");
    puts(voo[n].aeronave.modelo);
    printf("Ano de Fabricacao: %d    \nQuantidade de Assentos %d \n\n", voo[n].aeronave.anoFabricacao,
                                                                        voo[n].aeronave.quantidadeAssentos);
    printf("**************************************\n");
}
void exercicio03(){
    cadastraVoo(0);
    system("cls");
    imprimeVoo(0);
}
void exercicio04(){
    int resposta,
        voosCadastrados = 0,
        respostaValida = 1;

    system("cls");
    while(respostaValida){
        printf("Digite o seu NOME\n");
        gets(historico.nome);
        printf("\nDigite o seu CPF\n");
        gets(historico.cpf);
        printf("\nQuantos voos voce deseja cadastrar?\n");
        scanf("%d", &resposta);

        if(resposta > 0){
            while(voosCadastrados < resposta){
                printf("**************************************\n");
                printf("****Cadastro de Viagens Realizadas****\n");
                printf("**************************************\n");

                cadastraVoo(voosCadastrados);
                voosCadastrados++;

                printf("\n");
            }
            respostaValida = 0;
        }else{
            printf("O numero de voos esta incorreto!\n");
        }
    }

    voosCadastrados = 0;
    system("cls");

    for(; voosCadastrados < resposta; voosCadastrados++){
        imprimeVoo(voosCadastrados);
        printf("\n\n");
    }
}
void exercicio05(){
    int resposta = 0,
        numeroDeMusicas = 0,
        musicasCadastradas = 0,
        albunsCadastrados = 0;

    system("cls");

    printf("**************************************\n");
    printf("**********Cadastro de Cantor**********\n");
    printf("**************************************\n");

    printf("\nDigite o nome do Cantor\n");
    gets(cantores[0].pessoa.nome);
    fflush(stdin);

    printf("\nQuantos Albuns deseja cadastrar\n");
    scanf("%d", &resposta);
    fflush(stdin);

    if(resposta > 0){
        while( albunsCadastrados < resposta){
            system("cls");
            printf("Nome do Album %d \n", albunsCadastrados + 1);
            gets(cantores[0].album[albunsCadastrados].nome);
            fflush(stdin);

            printf("\nQuantas musicas contem o album?\n");
            scanf("%d", &numeroDeMusicas);
            fflush(stdin);

            while(musicasCadastradas < numeroDeMusicas){
                system("cls");
                printf("Digite o nome da musica %d \n", musicasCadastradas + 1);
                gets(cantores[0].album[albunsCadastrados].musica[musicasCadastradas].nome);
                fflush(stdin);

                printf("\nDigite a Duracao mm:ss \n");
                scanf("%d %d", &cantores[0].album[albunsCadastrados].musica[musicasCadastradas].duracao.minutos,
                                &cantores[0].album[albunsCadastrados].musica[musicasCadastradas].duracao.segundos);
                fflush(stdin);

                musicasCadastradas++;
            }
            musicasCadastradas = 0;
            albunsCadastrados++;
        }
        albunsCadastrados = 0;

        system("cls");

        printf("**************************************\n");
        printf("**********Cantor Cadastrado***********\n");
        printf("**************************************\n");

        printf("\nNome do Cantor: ");
        puts(cantores[0].pessoa.nome);
        printf("\n\n");

        while(albunsCadastrados < resposta){
            printf("Album: ");
            puts(cantores[0].album[albunsCadastrados].nome);

            musicasCadastradas = 0;

            printf("\n**************************************");
            printf("\n****************MUSICAS***************");
            while(musicasCadastradas < numeroDeMusicas){
                printf("\n**************************************\n\n");
                printf("Nome: ");
                puts(cantores[0].album[albunsCadastrados].musica[musicasCadastradas].nome);
                printf("Duracao: %d min%d s \n\n", cantores[0].album[albunsCadastrados].musica[musicasCadastradas].duracao.minutos,
                                            cantores[0].album[albunsCadastrados].musica[musicasCadastradas].duracao.segundos);

                musicasCadastradas++;
            }
            albunsCadastrados++;
        }
    }else{
        printf("\nValor incorreto!\n");
    }
}

void despedida(){
    system("cls");

    printf("********************************************************\n");
    printf("******************Obrigado Por Utilizar*****************\n");
    printf("********************************************************\n\n");

    printf("                      ///////////\n");
    printf("                    ##           ##\n");
    printf("      #####       ##    _      _   ##\n");
    printf("     #     #    ##     | |    | |     ##\n");
    printf("     #     #   ##      | |    | |      ##\n");
    printf("     #     #  ##       |_|    |_|       ##\n");
    printf("      #   #   ##                         ##\n");
    printf("    #############                        ##\n");
    printf("   #            # ##                ##   ##\n");
    printf("  ##            #  ##             ##     ##\n");
    printf(" ##   ###########    ##         ##       ##\n");
    printf(" #               #     #########        ##\n");
    printf(" ##              #                     ##\n");
    printf("  #   ############                    ##\n");
    printf("  ##           #  ##                ##\n");
    printf("   ############     ##            ##\n");
    printf("                      ###########\n");

    printf("\n\n             Por: Eduardo Ribeiro :D\n\n");
}

int main()
{

    printf("Exercicio 1\n");
    system("pause");
    exercicio01();

    printf("Exercicio 2\n");
    system("pause");
    exercicio02();

    printf("Exercicio 3\n");
    system("pause");
    exercicio03();

    printf("Exercicio 4\n");
    system("pause");
    exercicio04();

    printf("Exercicio 5\n");
    system("pause");
    exercicio05();

    despedida();

    return 0;
}
