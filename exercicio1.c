/*
Crie uma struct Contato para representar informações de contatos, incluindo nome, número de telefone e email. Solicite que o usuário cadastre 3 contatos. Escreva uma função que recebe um nome como parâmetro, e retorna o número de telefone correspondente a esse nome. Em seguida, implemente um programa que utiliza essa função para buscar e imprimir o número de telefone de um contato específico.
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

    printf("INFORME OS DADOS DO %iº CONTATO:\n",i+1);
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
  printf("Contato não encontrado.\n");

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