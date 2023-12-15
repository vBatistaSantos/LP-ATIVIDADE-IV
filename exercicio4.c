/*
Modele uma struct "ContaBancaria" que represente uma conta banc�ria com n�mero da conta, nome do titular, saldo e tipo de conta (poupan�a ou corrente). Implemente fun��es para depositar e sacar dinheiro da conta, bem como para imprimir o saldo atual. Crie um programa que utilize essas fun��es para simular opera��es banc�rias. Crie um menu para as opera��es dispon�veis.

1-DEPOSITAR 2-SACAR 3-SALDO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct info_contaBancaria{

  char numero[200];
  char nome[200];
  char tipo[200];
  float saldo;

};

void cadastrarcontaBancaria(struct info_contaBancaria contaBancaria[]){

  int opcao;

  printf("=== CADASTRO DE CONTA BANCARIA ===\n\n");
  printf("N�MERO DA CONTA: ");
  gets(contaBancaria[0].numero);
  printf("NOME DO TITULAR: ");
  gets(contaBancaria[0].nome);
  printf("TIPO DA CONTA: \n");
  printf("1-POUPAN�A\n");
  printf("2-CONTA CORRENTE\n");
  scanf("%i",&opcao);
  while(opcao>2 || opcao<1){
      printf("POR FAVOR, SELECIONE UMA OPCAO V�LIDA\n");
      scanf("%i",&opcao);
  }
  strcpy(contaBancaria[0].tipo,opcao==1?"POUPAN�A":"CONTA CORRENTE");
  printf("SALDO: ");
  scanf("%f",&contaBancaria[0].saldo);

  printf("\ncontaBancaria cadastrada!\n\n");

}

void saldoAtualizado(struct info_contaBancaria contaBancaria[]){

  printf("N�MERO DA CONTA: %s\n",contaBancaria[0].numero);
  printf("NOME DO TITULAR: %s\n",contaBancaria[0].nome);
  printf("TIPO DA CONTA  : %s\n",contaBancaria[0].tipo);
  printf("SALDO ATUAL    : R$ %.2f\n\n",contaBancaria[0].saldo);

}

void voltarMenu(){
  
  char sair;

  fflush(stdin);
  printf("\nAperte ENTER para continuar!\n");
  scanf("%c",&sair);
  
}

void exibirSaldo(struct info_contaBancaria contaBancaria[]){

  printf("=========  SALDO =========\n\n");

  saldoAtualizado(contaBancaria);

  voltarMenu();

}

void saque(struct info_contaBancaria contaBancaria[]){

  float saque;

  printf("========== SAQUE ==========\n\n");
    
  saldoAtualizado(contaBancaria);
  
  printf("QUANTOS DESEJA SACAR? ");
  scanf("%f",&saque);
  while(saque>contaBancaria[0].saldo){
    printf("POR FAVOR, DIGITE UM VALOR V�LIDO: ");
    scanf("%f",&saque);
  }

  contaBancaria[0].saldo -= saque;

  printf("SALDO ATUALIZADO: R$ %.2f\n",contaBancaria[0].saldo);

  voltarMenu();

}

void deposito(struct info_contaBancaria contaBancaria[]){

  float deposito;

  printf("========== DEPOSITO ==========\n\n");
  saldoAtualizado(contaBancaria);

  printf("QUANTOS DESEJA DEPOSITAR?\n");
  scanf("%f",&deposito);

  contaBancaria[0].saldo += deposito;

  printf("\nSALDO ATUALIZADO: R$ %.2f\n",contaBancaria[0].saldo);

  voltarMenu();

}

int menu(){

  int opcao;

  printf("=========== MENU ===========\n\n");
  printf("1 - DEPOSITAR\n");
  printf("2 - SACAR\n");
  printf("3 - SALDO\n");
  printf("4 - SAIR\n");
  scanf("%i",&opcao);

  while(opcao<1 && opcao>4){
    printf("Por favor, insira uma das op��es acima.\n");
    scanf("%i",&opcao);
  }

  return opcao;

}

int main(){

  setlocale(LC_ALL,"portuguese");

  struct info_contaBancaria contaBancaria[1];

  int opcao;

  cadastrarcontaBancaria(contaBancaria);
  
   do{

    system("cls || clear");

    opcao = menu();
    fflush(stdin);
    switch(opcao){

      case 1:
        deposito(contaBancaria);
        break;
      case 2:
        saque(contaBancaria);
        break;
      case 3:
        exibirSaldo(contaBancaria);
        break;
    }
    fflush(stdin);
  }while(opcao!=4);

  printf("\nENCERRANDO PROGRAMA...\n");

  return 0;

}