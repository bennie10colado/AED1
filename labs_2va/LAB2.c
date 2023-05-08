//Alunos: Lucas Branco e João Guilherme Benjamin

#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};typedef struct Node Node;

Node* newNode(Node* list, int data){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = list;
	return new_node;
}

int main(){
	int num;
	Node* list = NULL;

	while(1){
		printf("digite o numero a ser adicionado na lista:");
		scanf("%d", &num);
		newNode(list, num);
	}
	free(list);
}