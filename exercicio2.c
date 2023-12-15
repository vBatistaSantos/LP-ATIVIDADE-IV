/*
Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno", esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas. Em seguida, crie um programa que declare um array de 5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno. Também crie uma função para verificar se um aluno está aprovado ou reprovado sendo necessário média maior ou igual a 7,0 para aprovação.
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

    printf("INFORME OS DADOS DO %iº ALUNO:\n",i+1);
    printf("NOME: ");
    gets(aluno[i].nome);
    printf("DATA DE NASCIMENTO: ");
    gets(aluno[i].dataNascimento);
    
    aluno[i].media=0;

    for(j=0;j<N_NOTA;j++){
      printf("%iª NOTA: ",j+1);
      scanf("%f",&aluno[i].nota[j]);
    }
    fflush(stdin);

    aluno[i].media = 0;
    aluno[i].media = calcularMedia(aluno,i);

    printf("MÉDIA: %.2f\n",aluno[i].media);
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