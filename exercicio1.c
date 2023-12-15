/*
Crie uma struct Contato para representar informa��es de contatos, incluindo nome, n�mero de telefone e email. Solicite que o usu�rio cadastre 3 contatos. Escreva uma fun��o que recebe um nome como par�metro, e retorna o n�mero de telefone correspondente a esse nome. Em seguida, implemente um programa que utiliza essa fun��o para buscar e imprimir o n�mero de telefone de um contato espec�fico.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N_CONTATO 3

struct info_contato{

  char nome[200];
  char telefone[200];
  char email[200];

};

void cadastrarContato(struct info_contato contato[]){

  int i;

  for(i=0;i<N_CONTATO;i++){

    printf("INFORME OS DADOS DO %i� CONTATO:\n",i+1);
    printf("NOME:");
    gets(contato[i].nome);
    printf("TELEFONE:");
    gets(contato[i].telefone);
    printf("E-MAIL:");
    gets(contato[i].email);
    printf("\n");

  }

}

void buscarContato(struct info_contato contato[],char *buscarNome){

  int i;

  for(i=0;i<N_CONTATO;i++){

    if (strcmp(contato[i].nome,buscarNome)==0){

      printf("NOME: %s\n",contato[i].nome);
      printf("TELEFONE: %s\n",contato[i].telefone);
      printf("EMAIL: %s\n",contato[i].email);
      return;

    }
  }
  printf("Contato n�o encontrado.\n");

}


int main(){

  setlocale(LC_ALL,"portuguese");

  struct info_contato contato[N_CONTATO];
  char buscarNome[N_CONTATO];

  printf("====== CADASTRAR CONTATOS ======\n\n");
  cadastrarContato(contato);

  printf("\n======== BUSCAR CONTATO ========\n\n");
  printf("Informe nome do contato que deseja buscar: ");
  gets(buscarNome);
  printf("\n");
  buscarContato(contato,buscarNome);

  return 0;

}