/*
Crie uma fun��o chamada "calcularMedia" que recebe como par�metro uma struct "Aluno", esta struct ter� informa��es como: nome, data de nascimento, duas notas e m�dia e retorna a m�dia das notas. Em seguida, crie um programa que declare um array de 5 alunos e utilize a fun��o "calcularMedia" para imprimir a m�dia de cada aluno. Tamb�m crie uma fun��o para verificar se um aluno est� aprovado ou reprovado sendo necess�rio m�dia maior ou igual a 7,0 para aprova��o.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N_ALUNO 5
#define N_NOTA 2

struct info_aluno{

  char nome[200];
  char dataNascimento[200];
  float nota[N_NOTA];
  float media;

};

float calcularMedia(struct info_aluno aluno[],int i){

  int j;
  float media;

  for (j=0;j<N_NOTA;j++){
    media+=aluno[i].nota[j];
  }
  media/=(float)N_NOTA;

  return media;
}

char *verificarAprovado(float media){

  char msg[200];

  strcpy(msg,media>=7?"APROVADO":"REPROVADO");

  return msg;

}

void cadastrarAluno(struct info_aluno aluno[]){

  int i,j;

  for(i=0;i<N_ALUNO;i++){

    printf("INFORME OS DADOS DO %i� ALUNO:\n",i+1);
    printf("NOME: ");
    gets(aluno[i].nome);
    printf("DATA DE NASCIMENTO: ");
    gets(aluno[i].dataNascimento);
    
    aluno[i].media=0;

    for(j=0;j<N_NOTA;j++){
      printf("%i� NOTA: ",j+1);
      scanf("%f",&aluno[i].nota[j]);
    }
    fflush(stdin);

    aluno[i].media = 0;
    aluno[i].media = calcularMedia(aluno,i);

    printf("M�DIA: %.2f\n",aluno[i].media);
    printf("APROVADO: %s\n\n",verificarAprovado(aluno[i].media));

  }
}

int main(){

  setlocale(LC_ALL,"portuguese");

  struct info_aluno aluno[N_ALUNO];

  printf("====== CADASTRAR ALUNOS ======\n\n");
  cadastrarAluno(aluno);

  return 0;

}