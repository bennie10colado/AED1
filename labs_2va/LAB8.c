/*
Aluno: Joao Guilherme Benjamin
fazer array V
printar array V
definir maior e menor elemento e seus indices V
ordenacao sort de insercao em ordem decrescente colocando o menor elemento no ultimo indice V
eliminar elemento de posicao especifica e depois reordernar deixando o 0 na ultima posicao V
*/

#include <stdio.h>
#include <stdlib.h>


int maiorElemento(int vetor[], int tam)
{
    int i;
    int maior = vetor[0];
    for (i = 0; i < tam; i++)
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    return maior;
}

int indiceMaiorElemento(int vetor[], int tam)
{
    int i, indiceMaior = 0;
    int maiorNUM = maiorElemento(vetor, tam);

    for (i = 0; i < tam; i++)
    {
        if (vetor[i] == maiorNUM)
        {
            return indiceMaior;
        }
        else
            indiceMaior++;
    }
}

int menorElemento(int vetor[], int tam)
{
    int i;
    int menor = vetor[0];
    for (i = 0; i < tam; i++)
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    return menor;
}

int indiceMenorElemento(int vetor[], int tam)
{
    int i, indiceMenor = 0;
    int menorNUM = menorElemento(vetor, tam);

    for (i = 0; i < tam; i++)
    {
        if (vetor[i] == menorNUM)
        {
            return indiceMenor;
        }
        else
            indiceMenor++;
    }
}

void cloneArray(int vetorOrigem[], int vetorResultante[])
{
    int i;

    for (i = 0; i < 10; i++)
    {
        vetorResultante[i] = vetorOrigem[i];
    }
}

void SortDEC(int vetor[], int tam)
{
    int i, j, key;

    for (i = 1; i < tam; i++)
    {
        key = vetor[i];
        j = i - 1;

        while (j >= 0 && key > vetor[j]) // enquanto valor key for maior que o valor do vetor, gera-se a expressao de forma decrescente
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}

void sortFinal(int vetor[], int tamanho)
{
    int maior = vetor[0];
    int menor = vetor[0];
    int i, j, k;
    int posicao_maior, posicao_menor;
    int auxiliar[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int contador_maior = 0;
    int contador_menor = 1;

    for (i = 0; i < tamanho; i++)
    {
        if (contador_maior <= tamanho / 2 && contador_menor <= tamanho / 2)
        {
            for (j = 0; j < tamanho; j++)
            {
                if (vetor[j] != -1 && vetor[j] >= maior)
                {
                    maior = vetor[j];
                    posicao_maior = j;
                }
            }

            for (k = 0; k < tamanho; k++)
            {
                if (vetor[k] != -1 && vetor[k] <= menor)
                {
                    menor = vetor[k];
                    posicao_menor = k;
                }
            }

            auxiliar[contador_maior] = maior;
            printVector(auxiliar, tamanho);
            vetor[posicao_maior] = -1;

            auxiliar[10 - contador_menor] = menor;
            printVector(auxiliar, tamanho);
            printf("\n");
            vetor[posicao_menor] = -1;
            menor = maior;
            maior = 0;
        }
        contador_maior++;
        contador_menor++;
    }
    cloneArray(auxiliar, vetor);
}

void removeElemDoVet(int vetor[], int tam, int indice_removivel)
{
    int i, j;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i] == vetor[indice_removivel])
        {
            vetor[i] = 0;
        }
    }
    printf("elemento foi removido, substituido por 0 e reordenado.\n");
    sortFinal(vetor, tam);
}

void printVector(int vet[], int t)
{
    int i;
    for (i = 0; i < t; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(void)
{
    int opcao, indice_remover = 2;
    int vetor[10] = {5, 10, 7, 12, 20, 1, 2, 3, 4, 5};
    int tam = 10; // pode tambem ser : tam = sizeof(vetor) / sizeof(vetor[0]);

    do
    {
        printf("\n=-=-=-=-=-=-=-=-= Menu =-=-=-=-=-=-=-=-=\n");
        printf("1. Printar vetor. \n");
        printf("2. Aplica Sort. \n");
        printf("3. Retorna maior e menor valor do vetor, maior e menor indices do vetor. \n");
        printf("4. Remove um elemento. \n");
        printf("5. Aplica InsertionSort(bonus). \n");
        printf("6. Sair. \n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Rrintando vetor: \n");
            printVector(vetor, tam);
            break;
        case 2:
            sortFinal(vetor, tam);
            printf("Sort aplicado.\n");
            break;
        case 3:
            printf("\n%d\n", maiorElemento(vetor, tam));
            printf("%d\n", menorElemento(vetor, tam));
            printf("%d\n", indiceMaiorElemento(vetor, tam));
            printf("%d\n", indiceMenorElemento(vetor, tam));
            break;
        case 4:
            printf("Removendo...\n");
            removeElemDoVet(vetor, tam, indice_remover);
            break;
        case 5:
            SortDEC(vetor, tam);
            printf("Sort aplicado.\n");
            break;
        case 6:
            printf("finalizado.\n");
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao);
}