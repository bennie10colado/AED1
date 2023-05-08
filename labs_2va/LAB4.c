//Aluno: Joao Guilherme Benjamin

#include <stdlib.h>
#include <stdio.h>

#define size 10

//----------------STRUCTS---------------

struct pilha
{
    int posicao;
    float vet[size];
};
typedef struct pilha Notas;

struct fila
{
    int posicao;
    int inicio;
    float vet[size];
};
typedef struct fila Aluno;

//----------------PILHA---------------

Notas *pilha_cria()
{
    Notas *n = (Notas *)malloc(sizeof(Notas));
    n->posicao = 0;
    return n;
}

void pilha_insere(Notas *nota, float v)
{
    if ((*nota).posicao == 50)
    {
        exit(1);
    }
    nota->vet[nota->posicao] = v;
    nota->posicao++;
}

int pilha_vazia(Notas *nota)
{
    if (nota->posicao == 0)
    {
        return 1; // true
    }
    else
    {
        return 0; // false
    }
}

float pilha_remove(Notas *n)
{
    float v;
    if (pilha_vazia(n))
    {
        exit(1);
    }
    v = n->vet[n->posicao - 1];
    n->posicao--;
    return v;
}

void pilha_libera(Notas *n)
{
    free(n);
}

float pilha_topo(Notas *n)
{
    if (n->posicao == 0)
    {
        printf("a pilha esta vazia\n");
    }
    return n->vet[n->posicao - 1];
}

int pilha_tamanho(Notas *notas)
{
    if (pilha_vazia(notas))
    {
        exit(1);
    }
    else
        return notas->posicao;
}

void pilha_cheia(Notas *n)
{
    if (pilha_vazia(n))
    {
        exit(1);
    }
    else if (n->posicao == size)
    {
        printf("\nA pilha esta cheia, todos os seus espacos de alocamentos estao preenchidos.\n\n");
    }
}

void pilha_imprime(Notas *n)
{
    for (int i = (n->posicao) - 1; i >= 0; i--)
        printf("%f", n->vet[i]);
    printf("\n");
}

//----------------FILA----------------

Aluno *fila_cria(void)
{
    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
    a->posicao = 0; // inicializa a fila vazia;
    a->inicio = 0;  // escolhe uma posição inicial;
    return a;
}

void fila_enfileira(Aluno *aluno, float v)
{
    int fim;
    if (aluno->posicao == size)
    {
        printf("Fila não tem espaço disponivel\n");
        exit(1);
    }

    fim = (aluno->inicio + aluno->posicao) % size; // calculo do índice do ultimo elemento
    aluno->vet[fim] = v;
    aluno->posicao++;
}

int fila_vazia(Aluno *aluno)
{
    if (aluno->posicao == 0)
    {
        return 1; // true
    }

    else
    {
        return 0; // false
    }
}

float fila_desenfileira(Aluno *aluno)
{
    float v;
    // if (true)
    if (fila_vazia(aluno))
    {
        printf("Fila vazia\nPrograma finalizado...\n");

        exit(1);
    }
    // else
    v = aluno->vet[aluno->inicio];
    aluno->inicio = (aluno->inicio + 1) % size; // inicio +1, logo se retira o primeiro item
    aluno->posicao--;                           // quantidade de itens diminui em 1

    return v;
}

void fila_imprime(Aluno *alunos)
{

    int i;
    int cont = 0;

    for (i = 0; i < alunos->posicao; ++i)
    {
        printf("%.2f\n", alunos->vet[i]);
        cont++;
    }
    printf("o numero de elementos eh: %d\n", cont);
}

//----------------MAIN----------------

void main()
{

    float valor = 0, valor1 = 0;
    int opcao = 0;

    struct pilha *n = pilha_cria();
    struct fila *a = fila_cria();

    while (1)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\ndigite a opcao desejada:\n");

        printf("1 - insere valor na pilha (push)\n");
        printf("2 - remove valor na pilha (pop)\n");
        printf("3 - exibe topo da pilha (top)\n");
        printf("4 - exibe o tamanho da pilha (size)\n");
        printf("5 - exibe se a pilha esta cheia (isFull)\n");

        printf("6 - enfileira valor na fila\n");
        printf("7 - desenfileira valor na fila\n");
        printf("8 - exibe o tamanho da fila\n");
        printf("9 - sair\n\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            break;

        case 1:
            printf("\ndigite o valor desejado\n");
            scanf("%f", &valor);
            pilha_insere(n, valor);
            break;

        case 2:
            printf("\nvalor removido: %f\n", pilha_remove(n));
            break;

        case 3:
            printf("\nvalor no topo da pilha: %f\n", pilha_topo(n));
            break;

        case 4:
            printf("\no tamanho da pilha eh: %d\n", pilha_tamanho(n));
            break;

        case 5:
            pilha_cheia(n);
            break;

        case 6:
            printf("\nDigite o valor desejado\n");
            scanf("%f", &valor1);
            fila_enfileira(a, valor1);
            break;

        case 7:
            printf("\nvalor removido! (se continuar ate a fila zerar, aparecera a mensagem 'fila vazia') \n");
            fila_desenfileira(a);
            break;

        case 8:
            fila_imprime(a);
            break;

        case 9:
            exit(0);

        default:
            printf("\nOPCAO INVALIDA! \n");
        }
    }
}