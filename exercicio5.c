/*
Crie uma struct "Funcionario" com membros para nome, cargo e sal�rio. Escreva uma fun��o que recebe um array de funcion�rios e um cargo como par�metro, e retorna a m�dia salarial dos funcion�rios com esse cargo. Em seguida, implemente um programa que utiliza essa fun��o para calcular e imprimir a m�dia salarial dos programadores em uma empresa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct info_funcionario{

  char nome[200];
  char cargo[200];
  float salario;

};

void cadastrarFuncionario(struct info_funcionario funcionario[],int i){

  printf("NOME: ");
  gets(funcionario[i].nome);
  printf("CARGO: ");
  gets(funcionario[i].cargo);
  printf("SAL�RIO: ");
  scanf("%f",&funcionario[i].salario);

}

float mediaSalarial(struct info_funcionario funcionario[],char *cargo,int totalFuncionario){

  int i,cont=0;
  float media=0;

  for(i=0;i<totalFuncionario;i++){
    if(strcmp(funcionario[i].cargo,cargo)==0){
      media += funcionario[i].salario;
    }
    cont++;
  }
  return   media/=(float)cont;
}

int main(){

  setlocale(LC_ALL,"");
  
  int i=0;
  char continuar;

  struct info_funcionario funcionario[i+1];

  printf("=== CADASTRO DE FUNCIONARIOS ===\n\n");

  do{
    
    cadastrarFuncionario(funcionario,i);
    
    fflush(stdin);
    printf("Deseja cadastrar mais funcion�rios?(s/n) ");
    scanf("%c",&continuar);
    continuar = tolower(continuar);
    fflush(stdin);

    while(continuar!='s' && continuar!='n'){
        printf("Por favor, selecione uma op��o v�lida: ");
        scanf("%c",&continuar);
        continuar = tolower(continuar);
        fflush(stdin);
    }

    i++;
    if (continuar!='s'){
      break;
    }

    printf("\n==================================\n\n");
    printf("funcion�rios cadastrados: %i\n", i);

  }while(continuar=='s');
  
  printf("\nA m�dia salarial dos programadores � R$ %.2f\n",mediaSalarial(funcionario,"PROGRAMADOR",i));

  return 0;

}