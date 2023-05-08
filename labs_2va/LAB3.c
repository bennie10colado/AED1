//Alunos: Lucas Branco e Joao Guilherme Benjamin

#include <stdlib.h>
#include <stdio.h>

#define size 50

struct pilha {
	int n;
	float vet[size];
}; typedef struct pilha Pilha;

Pilha *pilha_cria(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p -> n = 0;
	return p;
}

void pilha_insere (Pilha *p, float v){
	if ((*p).n == 50) {
		exit(1);
	}
	p -> vet[p -> n] = v;
	p -> n++;
}

int pilha_vazia (Pilha *p){
	if(p -> n == 0){
		return 1;
	}else{
		return 0;
	}
}

float pilha_remove (Pilha *p){
	float v;
	if (pilha_vazia(p)){
		exit(1);
	}
	v = p -> vet[p -> n-1];
	p -> n--;
	return v;
}

void pilha_libera (Pilha *p){
	free(p);
}

float pilha_topo(Pilha *p){
	if(p -> n == 0){
		printf("a pilha esta vazia\n");
	}
	return p -> vet[p -> n-1];
}

void main(){

	float valor = 0;
	int escolha = 0;
	struct pilha *p = pilha_cria();
	while(1){
		printf("digite a escolha:\n");
		printf("1 - insere valor na pilha\n");
		printf("2 - remove valor na pilha\n");
		printf("3 - exibe topo da pilha\n");
		printf("4 - sair\n");
		scanf("%d", &escolha);
		switch (escolha){
			case 0:
				break;
			case 1:
				printf("Digite o valor desejado\n");
				scanf("%f", &valor);
				pilha_insere(p, valor);
				break;
			case 2:
				printf("valor removido: %f", pilha_remove(p));
				break;
			case 3:
				printf("valor no topo da pilha: %f", pilha_topo(p));
				break;
			case 4:
				exit(0);
			default:
				break;
		}
	}
}