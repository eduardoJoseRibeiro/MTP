#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

enum tipoCliente {
    Comum, Especial
}tipo;

enum tipoCarro{
    Popular, Luxo, Utilitario
}tipoCarros;

class Cliente {
   public: char RG[20], CPF[20], nome[50],
        endereco[100], telefone[20], cidade[50],
        UF[2];
    tipoCliente tipo = Comum;
}Clientes[200];

class Carro {
    public: int codigo, ano, kmRodado, valorAluguelDia, valorAluguelSemana;
    char placa[20], fabricante[50, modelo[50], cor[50];
    tipoCarro tipoCarros = Popular;
}Carros;

int main()
{
    int entrada = 0, numeroCliente = 0;

    do{
        system("cls");
        cout << "Digite\n";
        cout << "1 - Para cadastrar um Cliente\n";
        cout << "2 - Para Exibir os Clientes Cadastrados\n";
        cout << "9 - Para Sair\n" << endl;

        cin >> entrada;

        if(entrada == 1){
            system("cls");
            fflush(stdin);
            cout << "Digite o Nome do cliente\n";
            gets(Clientes[numeroCliente].nome);

            fflush(stdin);
            cout << "Digite o CPF do cliente\n";
            gets(Clientes[numeroCliente].CPF);

            fflush(stdin);
            cout << "Digite o RG do cliente\n";
            gets(Clientes[numeroCliente].RG);

            fflush(stdin);
            cout << "Digite o Endereco do cliente\n";
            gets(Clientes[numeroCliente].endereco);

            fflush(stdin);
            cout << "Digite o Telefone do cliente\n";
            gets(Clientes[numeroCliente].telefone);

            fflush(stdin);
            cout << "Digite o Cidade do cliente\n";
            gets(Clientes[numeroCliente].cidade);

            fflush(stdin);
            cout << "Digite o UF do cliente\n";
            gets(Clientes[numeroCliente].UF);

            numeroCliente++;
        }
        else if( entrada == 2){
            system("cls");
            for(int i = 0; i < numeroCliente; i++){
                cout << "Nome: " << Clientes[i].nome << endl;
                cout << "CPF: " << Clientes[i].CPF << endl;
                cout << "RG: " << Clientes[i].RG << endl;
                cout << "Endereco: " << Clientes[i].endereco << endl;
                cout << "Telefone: " << Clientes[i].telefone << endl;
                cout << "Cidade: " << Clientes[i].cidade << " - " << Clientes[i].UF << endl;
            }
            system("pause");
        }
    }while(entrada != 9);
    return 0;
}
