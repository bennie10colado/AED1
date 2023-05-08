//Aluno: Joao Guilherme Benjamin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    int valor;
    struct lista *proximo;
};
typedef struct lista Lista;

Lista *inicializa()
{
    return NULL;
}

Lista *insereLista(Lista *lista, int val) // Lista lista se torna o proximo, e aloca nova alista em uma posicao anterior, assim o inicio da lista eh o final
{
    Lista *nova_lista = (Lista *)malloc(sizeof(Lista));
    nova_lista->valor = val;
    nova_lista->proximo = lista;

    printf("valor inserido: %d\n", nova_lista->valor);

    return nova_lista;
}

void visualizaLista(Lista *l)
{
    if (!vazia(l)) // apenas se lista for inicializada e diferente de null; "!vazia é igual a != NULL".
    {
        Lista *prov;
        for (prov = l; prov; prov = prov->proximo) //situacao de parada: quando prov for NULL.
        {
            printf("valor = %d\n", prov->valor);
        }
    }
}

int vazia(Lista *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

void liberaLista(Lista *l)
{

    if (!vazia(l))
    {
        Lista *p = l;
        while (!vazia(p))
        {
            Lista *t = p->proximo;
            free(p);

            p = t;
        }
        printf("Liberado!");
    }
}

Lista *concatenaListas(Lista *lista1, Lista *lista2)
{
    Lista *lista_prov = lista2; // lista provisoria ira receber as posicoes dos nos da lista
    Lista *nova = inicializa();

    while (!vazia(lista_prov)) // lista2
    {
        nova = insereLista(nova, lista_prov->valor);
        lista_prov = lista_prov->proximo;
    }

    lista_prov = lista1; // lista1
    while (!vazia(lista_prov))
    {
        nova = insereLista(nova, lista_prov->valor);
        lista_prov = lista_prov->proximo;
    }
    return nova;
}

int main()
{
    Lista *lista1;
    Lista *lista2;
    Lista *listaCONC;

    lista1 = inicializa();
    lista2 = inicializa();
    listaCONC = inicializa();
    printf("\nlistas inicializadas!\n\n");
    lista1 = insereLista(lista1, 1);
    lista1 = insereLista(lista1, 2);
    lista1 = insereLista(lista1, 5);
    lista1 = insereLista(lista1, 78);
    printf("\ninsercao de valores da lista 1: concluida!\n\n");
    visualizaLista(lista1); // imprimirá: 78 5 2 1, apos a concatenacao devera imprimir: 1 2 5 78
    // liberaLista(lista1);
    //  visualizaLista(lista1);nao imprima isso apos o free, vai colocar enviar infinitos enderecos de memoria.
    printf("\nvisualizacao de valores da lista 1: concluida!\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    lista2 = insereLista(lista2, 0);
    lista2 = insereLista(lista2, 9);
    lista2 = insereLista(lista2, 8);

    printf("\ninsercao de valores da lista 2: concluida!\n\n");
    visualizaLista(lista2);
    printf("\nvisualizacao de valores da lista 2 concluida!\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    listaCONC = concatenaListas(lista1, lista2);
    printf("\ninsercao de valores na lista concatenada: concluida!\n\n");

    visualizaLista(listaCONC);

    printf("\nvisualizacao de valores da lista concatenada invertida: concluida!\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");



    liberaLista(lista1);
    liberaLista(lista2);
    liberaLista(listaCONC);
    
    return 0;
}