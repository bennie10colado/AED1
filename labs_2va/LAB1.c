//Aluno: João Guilherme Benjamin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int id;
    int idade;
} Aluno;

typedef struct{
    Aluno alunos[10];
    char nomeDoProfessor[20];
    int quantidade_alunos;
} Sala;

void cadastraAluno(Sala *s){
    printf("Digite o nome do Aluno: \n");
    scanf("%s", s->alunos->nome);
    printf("Digite o id do Aluno: \n");
    scanf("%d", &s->alunos->id);
    printf("Digite a idade do Aluno: \n");
    scanf("%d", &s->alunos->idade);

    s->alunos[s->quantidade_alunos];
    s->quantidade_alunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

void verificaAluno(Sala *s){
    int i, idAluno;
    printf("Digite o id do Aluno procurado: \n");
    scanf("%d", &idAluno);

    for (i = 0; i < s->quantidade_alunos; i++)
    {
        if (s->alunos[i].id == idAluno)
        {
            printf("Aluno encontrado!\n");
        }
    }
}

int main(){
    char nomeProfessor[15];
    Sala sala;
    sala.quantidade_alunos = 0; // inicia na posicao 0

    printf("Digite o nome do professor: \n");
    scanf("%s", sala.nomeDoProfessor);

    cadastraAluno(&sala);

    // printf("Verificando...\n");

    verificaAluno(&sala);
    printf("\nVerificado!\nPrograma finalizado...\nbip...\nbip...\nbop...\n");

    return 0;
}