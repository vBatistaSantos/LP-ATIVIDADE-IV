/*
Desenvolva uma struct "Produto" que contenha informações como nome, preço e quantidade em estoque. Em seguida, desenvolva um menu para facilitar a escolha das opções:
1 - Realizar uma compra
2 - Consultar estoque
3 - Sair do programa. 

Escreva funções necessárias para calcular o valor total em estoque do produto e para atualizar a quantidade em estoque com base em uma compra. Crie um programa que utiliza essas funções para um produto[0].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct info_produto{

  char nome[200];
  float preco;
  int estoque;

};

void cadastrarProduto(struct info_produto produto[]){

  printf("=== CADASTRO DE PRODUTOS ===\n\n");
  printf("NOME: ");
  gets(produto[0].nome);
  printf("PREÇO: ");
  scanf("%f",&produto[0].preco);
  printf("QUANTIDADE EM ESTOQUE: ");
  scanf("%i",&produto[0].estoque);

  printf("\nProduto cadastrado!\n\n");
  return;

}

void exibirEstoque(struct info_produto produto[]){

  char sair;

  printf("=========  ESTOQUE =========\n\n");
  printf("PRODUTO: %s\n",produto[0].nome);
  printf("PRECO  : R$ %.2f\n",produto[0].preco);
  printf("ESTOQUE: %i UNDs\n",produto[0].estoque);
  printf("\nVALOR TOTAL EM ESTOQUE: R$ %.2f\n",(produto[0].estoque*produto[0].preco));

  fflush(stdin);

  printf("\nAperte ENTER para voltar ao menu anterior\n");
  scanf("%c",&sair);
  return;

}

void realizarComprar(struct info_produto produto[]){

  char confirmar;
  int nCompra;

  printf("========== COMPRA ==========\n\n");
  printf("PRODUTO: %s\n",produto[0].nome);
  printf("VALOR UNITÁRIO: R$ %.2f\n",produto[0].preco);
  printf("DISPONÍVEIS: %i UNDs\n",produto[0].estoque);
  
  do{
    printf("\nQUANTOS DESEJA COMPRAR?\n");
    scanf("%i",&nCompra);
    while(nCompra>produto[0].estoque){
      printf("POR FAVOR, SELECIONE UMA QUANTIDADE DISPONÍVEL EM ESTOQUE");
      scanf("%i",&nCompra);
    }

    
    printf("\n===== CESTA DE PRODUTO =====");
    printf("\n%s x %01i UND\n",produto[0].nome,nCompra);
    printf("PREÇO TOTAL: R$%.2f\n\n",(nCompra*produto[0].preco));
    
    fflush(stdin);
    printf("CONFIRMA A COMPRA ACIMA?(s/n)\n");
    scanf("%c",&confirmar);
    confirmar = tolower(confirmar);
    while(confirmar!='s' && confirmar!='n'){
      printf("POR FAVOR, ESCREVA (s) PARA SIM OU (n) PARA NÃO\n");
      scanf("%c",&confirmar);
    }
    
  }while(confirmar=='n');

  produto[0].estoque -= nCompra;

} 


int menu(){

  int opcao;

  printf("=========== MENU ===========\n\n");
  printf("1 - Realizar uma compra\n");
  printf("2 - Consultar estoque\n");
  printf("3 - Sair do programa\n");
  scanf("%i",&opcao);

  while(opcao<1 && opcao>3){
    printf("Por favor, insira uma das opções acima.\n");
    scanf("%i",&opcao);
  }

  return opcao;

}

int main(){

  setlocale(LC_ALL,"portuguese");

  struct info_produto produto[1];

  int opcao;

  cadastrarProduto(produto);
  
   do{

    system("cls || clear");

    opcao = menu();
    fflush(stdin);
    switch(opcao){

      case 1:
        realizarComprar(produto);

        break;
      case 2:
        exibirEstoque(produto);
    }
    fflush(stdin);
  }while(opcao!=3);

  printf("\nENCERRANDO PROGRAMA...\n");

  return 0;

}